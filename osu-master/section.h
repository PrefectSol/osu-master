#ifndef SECTION_H
#define SECTION_H

#include <string>
#include <vector>
#include <map>

class Section
{
public:
    virtual void parse(std::vector<std::string> &lines) = 0;

private:
    std::map<std::string, std::string> m_sectionMap = {};

protected:
    std::string getAttribute(std::string key);

    void loadAttributes(const std::vector<std::string> &lines);

    void insertAttribute(std::string key, std::string value);
};

#endif // !SECTION_H
