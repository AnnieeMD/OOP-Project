#pragma once

#include <string>
#include <fstream>

#include "attributes.hpp"
#include "tag.hpp"

/*!
*@class XMLParser
*@brief This class takes care of parsing 
*the information from the file before the tree is created.
*/


class XMLParser {

public:
    
    /*!
    *@brief Removes leading spaces from a string.
    *   
    *This function removes leading spaces from a given string and returns the modified string.
    *   
    *@param str The string to remove spaces from.
    *
    *@return std::string The modified string without leading spaces.
    */
    static std::string removeSpaces(std::string& str);
 
    /*!
    *@brief Extracts the opening tag from a line of XML.
    *
    *This function extracts the opening tag (identifier and attributes) from a line of XML
    *and returns a Tag object representing the opening tag.
    *
    *@param line The line of XML containing the opening tag.
    *@return Tag The extracted opening tag.
    *@throws std::runtime_error if the line is an invalid open tag.
    */
    static Tag getOpenTag(const std::string& line);

    /*!
    *@brief Parses the attributes of an XML opening tag.
    *
    *This function parses the attributes of an XML opening tag from a given line
    *and returns an Attributes object containing the attribute names and values.
    *The parsing starts at the specified index in the line.
    *
    *@param line The line of XML containing the attributes.
    *@param i The index to start parsing from.
    *@return Attributes The parsed attributes.
    */
    static Attributes parseAttr(const std::string &line, size_t &i);

    /*!
    *@brief Checks if a line of XML contains an opening tag.
    *
    *This function checks if a line of XML contains an opening tag.
    *It returns true if the line has an opening tag, false otherwise.
    *
    *@param line The line of XML to check.
    *@return bool True if the line has an opening tag, false otherwise.
    */
    static bool hasOpenTag(const std::string& line);

    /*!
    *@brief Checks if a line of XML contains a closing tag.
    *
    *This function checks if a line of XML contains a closing tag.
    *It returns true if the line has a closing tag, false otherwise.
    *
    *@param line The line of XML to check.
    *@return bool True if the line has a closing tag, false otherwise.
    */
    static bool hasClosingTag(const std::string& line);

    /*!
    *@brief Checks if a line of XML represents a leaf tag.
    *
    *This function checks if a line of XML represents a leaf tag,
    *i.e., an opening tag followed immediately by a closing tag.
    *It returns true if the line represents a leaf tag, false otherwise.
    *
    *@param line The line of XML to check.
    *@return bool True if the line represents a leaf tag, false otherwise.
    */
    static bool isLeafTag(const std::string& line);

};