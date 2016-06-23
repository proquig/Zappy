//
// Tool.hh for Tool.hh in /home/ip_y/rendu/cpp_plazza/src
// 
// Made by ip_y
// Login   <ip_y@epitech.net>
// 
// Started on  Thu Apr 21 14:57:15 2016 ip_y
// Last update Thu Apr 21 14:57:20 2016 ip_y
//

#ifndef _TOOL_HH_
# define _TOOL_HH_

# include <string>
# include <sstream>
# include <vector>

namespace Tool
{
    std::vector<std::string>	&strToWordVector(std::string const &str, char split, std::vector<std::string> &subStrings);
    std::vector<std::string>	strToWordVector(std::string const &str, char split);
}

#endif /*_TOOL_HH_*/