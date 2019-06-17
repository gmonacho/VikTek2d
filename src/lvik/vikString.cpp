#include "vikString.h"
#include <vector>
#include <string>

namespace vik
{

std::vector<std::string> strSplit(const std::string &str, const char &c)
{
    std::vector<std::string>    splitTab;
    int                         pos{0};
    int                         i{0};

    while (str[i] == c)
        i++;
    pos = i;
    while (i < str.size())
    {
        if (str[i] == c)
        {
            splitTab.push_back(str.substr(pos, i - pos));
            while (str[i + 1] == c)
                i++;
            pos = i + 1;
        }
        i++;
    }
    if (i != 0 && str[i - 1] != c)
        splitTab.push_back(str.substr(pos, i - pos));
    return (splitTab);
}

}   //  namespace vik
