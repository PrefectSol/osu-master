#include "utilities.h"

std::vector<std::string> Utilities::split(std::string input, char delimiter)
{
    std::vector<std::string> output;
    std::stringstream stream(input);
    std::string currentLine;

    while (std::getline(stream, currentLine, delimiter))
    {
        output.push_back(currentLine);
    }

    return output;
}

std::string Utilities::trim(std::string input)
{
    return input.erase(input.find_last_not_of(' ') + 1).erase(0, input.find_first_not_of(' '));
}
