//
// Tool.cpp for Tool.cpp in /home/ip_y/rendu/cpp_plazza/src
// 
// Made by ip_y
// Login   <ip_y@epitech.net>
// 
// Started on  Thu Apr 21 14:59:17 2016 ip_y
// Last update Thu Apr 21 14:59:20 2016 ip_y
//

#include "Tool.hh"

std::vector<std::string>	&Tool::strToWordVector(std::string const &str, char split, std::vector<std::string> &subStrings)
{
    std::stringstream	ss(str);
    std::string		subString;

    while (std::getline(ss, subString, split))
        subStrings.push_back(subString);
    return (subStrings);
}

std::vector<std::string>	Tool::strToWordVector(std::string const &str, char split)
{
    std::vector<std::string> subStrings;
    Tool::strToWordVector(str, split, subStrings);
    return (subStrings);
}