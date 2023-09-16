#include "apphandler.h"
#include <TlHelp32.h>
#include <settings.hpp>

std::string p_mapProcName;
std::size_t p_appNameSize;

AppHandler::AppHandler()
    : m_cfgExtension(".cfg"), m_osuExtension(".osu"),
    m_status(AppHandler::ResultCode()),
    m_pid(0), m_keyOsuLeft(std::string()),
    m_keyOsuRight(std::string()), m_keyPause(std::string()), m_keySkip(std::string()), m_beatmapDirectory(std::string()),
    m_height(0), m_width(0)
{
    m_status = initialize();
}

AppHandler::ResultCode AppHandler::initialize()
{
    m_appCfg = settings::osuClientName.toStdString() + ".cfg";
    m_chat = settings::osuBotName.toStdString();
    m_processName = settings::osuClientName.toStdWString() + L".exe";
    p_appNameSize = settings::osuClientName.size();

    const AppHandler::ResultCode isInitPid = initPid();
    if (isInitPid != AppHandler::ResultCode::success)
    {
        return isInitPid;
    }

    const AppHandler::ResultCode isInitAppDir = initAppDirectory();
    if (isInitAppDir != AppHandler::ResultCode::success)
    {
        return isInitAppDir;
    }

    return parseCfg();
}

AppHandler::ResultCode AppHandler::getStatus()
{
    return m_status;
}

AppHandler::ResultCode AppHandler::initPid()
{
    const HANDLE hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    if (hProcessSnap == INVALID_HANDLE_VALUE)
    {
        return AppHandler::ResultCode::createToolhelp32SnapshotError;
    }

    PROCESSENTRY32 pe32{};
    pe32.dwSize = sizeof(PROCESSENTRY32);

    if (!Process32First(hProcessSnap, &pe32))
    {
        CloseHandle(hProcessSnap);

        return AppHandler::ResultCode::process32FirstError;
    }

    bool processFound = false;

    do
    {
        const std::wstring processNameFromSnapshot(pe32.szExeFile);

        if (processNameFromSnapshot.find(m_processName) != std::wstring::npos)
        {
            m_pid = pe32.th32ProcessID;
            processFound = true;

            break;
        }
    } while (Process32Next(hProcessSnap, &pe32));

    CloseHandle(hProcessSnap);

    if (!processFound)
    {
        return AppHandler::ResultCode::findProcessError;
    }

    return AppHandler::ResultCode::success;
}

AppHandler::ResultCode AppHandler::initAppDirectory()
{
    const HANDLE hProcess = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, m_pid);

    if (!hProcess)
    {
        return AppHandler::ResultCode::openPidError;
    }

    char exeBytePath[MAX_PATH];
    DWORD bufferSize = MAX_PATH;

    if (!QueryFullProcessImageNameA(hProcess, 0, exeBytePath, &bufferSize))
    {
        CloseHandle(hProcess);

        return AppHandler::ResultCode::retriveExeError;
    }

    CloseHandle(hProcess);

    const std::string exePath = std::string(exeBytePath);
    m_appDirectory = std::filesystem::path(exePath).parent_path().string();

    return AppHandler::ResultCode::success;
}

AppHandler::ResultCode AppHandler::parseCfg()
{
    std::string userCfgPath;
    const AppHandler::ResultCode isGetUserCfgPath = getUserCfgPath(&userCfgPath);

    if (isGetUserCfgPath != AppHandler::ResultCode::success)
    {
        return isGetUserCfgPath;
    }

    std::ifstream cfgFile(userCfgPath.c_str());
    if (!cfgFile.is_open())
    {
        return AppHandler::ResultCode::openCfgFileError;
    }

    while (cfgFile)
    {
        std::string line;
        std::getline(cfgFile, line);

        if (line.find("BeatmapDirectory") != std::string::npos)
        {
            m_beatmapDirectory = line.substr(line.find("=") + 2);
        }
        else if (line.find("keyOsuLeft") != std::string::npos)
        {
            m_keyOsuLeft = line.substr(line.find("=") + 2);
        }
        else if (line.find("keyOsuRight") != std::string::npos)
        {
            m_keyOsuRight = line.substr(line.find("=") + 2);
        }
        else if (line.find("keyPause") != std::string::npos)
        {
            m_keyPause = line.substr(line.find("=") + 2);
        }
        else if (line.find("keySkip") != std::string::npos)
        {
            m_keySkip = line.substr(line.find("=") + 2);
        }
        else if (line.find("Height") != std::string::npos)
        {
            m_height = std::stoi(line.substr(line.find("=") + 2));
        }
        else if (line.find("Width") != std::string::npos)
        {
            m_width = std::stoi(line.substr(line.find("=") + 2));
        }
    }

    cfgFile.close();

    return AppHandler::ResultCode::success;
};

AppHandler::ResultCode AppHandler::getUserCfgPath(std::string *path)
{
    for (const std::filesystem::path &entry : std::filesystem::directory_iterator(m_appDirectory))
    {
        const bool isCfg = entry.extension() == m_cfgExtension;

        if (isCfg && entry.filename() != m_appCfg)
        {
            *path = entry.string();
            return AppHandler::ResultCode::success;
        }
    }

    return AppHandler::ResultCode::findCfgFileError;
}
