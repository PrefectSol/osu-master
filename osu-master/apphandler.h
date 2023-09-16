#ifndef APP_HANDLER_H
#define APP_HANDLER_H

#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>

#include <Windows.h>

#define SLASH "\\"

class AppHandler
{
public:
    enum ResultCode
    {
        success = 0,

        createToolhelp32SnapshotError = 2,
        process32FirstError,
        findProcessError,
        openDirectoryError,

        openPidError,
        retriveExeError,
        findCfgFileError,
        openCfgFileError,

        findAppTitleError,
        mapSelectedError,

        openChatFileError,
        getBeatmapIdError,
    };

    AppHandler();

    AppHandler::ResultCode getStatus();

    AppHandler::ResultCode getMapPath(std::string *path);

    std::string getKeyOsuLeft();

    std::string getKeyOsuRight();

    std::string getKeyPause();

    std::string getKeySkip();

    int getHeight();

    int getWidth();

private:
    const std::wstring m_processName;

    const char *m_cfgExtension;

    const char *m_osuExtension;

    const std::string m_chat;

    const std::string m_appCfg;

    AppHandler::ResultCode m_status;

    DWORD m_pid;

    std::string m_appDirectory;

    std::string m_keyOsuLeft;

    std::string m_keyOsuRight;

    std::string m_keyPause;

    std::string m_keySkip;

    std::string m_beatmapDirectory;

    int m_height;

    int m_width;

    AppHandler::ResultCode initPid();

    AppHandler::ResultCode initAppDirectory();

    AppHandler::ResultCode getBeatmapId(std::string *id);

    std::string getMapFilename(std::string dir, std::string difficulty);

    AppHandler::ResultCode getUserCfgPath(std::string *path);

    AppHandler::ResultCode parseCfg();

protected:
};

#endif // !APP_HANDLER_H
