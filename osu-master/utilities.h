#ifndef UTILITIES_H
#define UTILITIES_H

#include <sstream>
#include <vector>

namespace Utilities
{
    std::vector<std::string> split(std::string input, char delimeter);

    std::string trim(std::string input);
};

#endif // !UTILITIES_H
