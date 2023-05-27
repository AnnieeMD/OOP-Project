#include "XMLParser.hpp"

#include <iostream>
#include <stdexcept>

using std::size_t;

std::string XMLParser::removeSpaces(std::string& str) {

    std::string result = "";

    // Remove spaces until first non-space character is found

    size_t i = 0;
    while (i < str.length() && str[i] == ' ') {
        i++;
    }

    // Concatenate the rest of the string without checking for spaces
    for (; i < str.length(); i++) {
        result += str[i];
    }

    return result;
} 

Tag XMLParser::getOpenTag(const std::string& line) {

    if(line.empty() || line[0] != '<') {

       throw std::runtime_error("Invalid open tag.");
    }    
    
    std::string identifier = "";
    Attributes attributes;

    size_t index = 1;

    while (line[index] != ' ' && line[index] != '>') {

        identifier += line[index];
        index++;

    }

    attributes = XMLParser::parseAttr(line, index);
    return Tag(identifier, attributes);

}

Attributes XMLParser::parseAttr(const std::string &line, size_t &i) {

    Attributes list;

    if(line[i] == ' ') i++;

    while (line[i] != '>') {

        std::string attr_name = "";
        std::string attr_value = "";

        while (line[i] != '=') {

            if(line[i] == '\"') {
                i++;
                continue;
            }

            attr_name += line[i];
            i++;
        }
        
        i++;

        while (line[i] != ' ' && line[i] != '>') {

            if(line[i] == '\"') {
                i++;
                continue;
            }

            attr_value += line[i];
            i++;
        }

        list.attr_names.push_back(attr_name);
        list.attr_values.push_back(attr_value);

        if(line[i] == '>') {
            break;
        }

        i++;
    }

    return list;

}

bool XMLParser::hasOpenTag(const std::string& tag) {

    size_t index = tag.find('<');
    return index != std::string::npos && tag[index + 1] != '/' && tag.find('>') != std::string::npos;
}

bool XMLParser::hasClosingTag(const std::string& tag) {

    size_t index = tag.find('<');
    return index != std::string::npos && tag[index + 1] == '/' && tag.find('>') != std::string::npos;
} 

bool XMLParser::isLeafTag(const std::string& tag) {

    if (hasOpenTag(tag)) {

        size_t index = tag.find('>');

        if(index != tag.size() - 1) {

            std::string line2 = tag.substr(index + 1, tag.size());

            if(hasClosingTag(line2)) {
                return true;
            }
        }
    }

    return false;
}
