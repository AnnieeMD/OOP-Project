#pragma once

#include <string>
#include <fstream>

#include "attributes.hpp"
#include "tag.hpp"

class XMLParser {

public:
    
    static std::string removeSpaces(std::string& str);
 
    static Tag getOpenTag(const std::string& line);
    static Attributes parseAttr(const std::string &line, size_t &i);

    static bool hasOpenTag(const std::string& line);
    static bool hasClosingTag(const std::string& line);
    static bool isLeafTag(const std::string& line);

};