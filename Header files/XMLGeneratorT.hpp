#pragma once

#include "XMLElement.hpp"
#include "XMLTree.hpp"

#include <fstream>

/*!
*@class Generator
*@brief Building the tree is done recursively, by reading each line from the file, that line is processed and from it creates one of 
*the following objects: Tag, plain text to a given element, Tag of type leaf. Tree elements are described with an XMLElement class that 
*contains the name of the tag, a list of the tag's attributes, the text in this tag and a list of descendants(nested elements). 
*Each element has a unique id. The bottom of the recursive creation of the tree is when a Tag of type leaf (ie an element that has no 
*nested elements) is reached.
*/

class Generator {

public:

/*!
*@brief Generates an XML tree from the given content.
*@param content A vector of strings representing the content.
*@return An XMLTree object representing the generated XML tree.
*This method takes a vector of strings and generates an XML tree based on the content.
*The generated XML tree is returned as an XMLTree object.
*/

static XMLTree GenerateTree(std::vector<std::string>& content);

/*!
*@brief Recursive helper function for generating XML tree nodes.
*@param content A vector of strings representing the content.
*@param i The index of the current content string being processed.
*@return An XMLElement object representing a node in the XML tree.
*This recursive function takes a vector of strings and generates an XML tree node based on the content
*starting from the specified index. The generated XML tree node is returned as an XMLElement object.
*/

static XMLElement TreeGenerator(const std::vector<std::string>& content, size_t& i);

};