#include "XMLPath.hpp"

#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>

XMLPath::XMLPath(const std::string& query) : xmlquery(query) {}

bool XMLPath::isLetter(const char symbol) const {
    
    return ((symbol >= 'A' && symbol <= 'Z') || (symbol >= 'a' && symbol <= 'z'));
}

void XMLPath::OperatorSlash(const XMLElement& root) const {

    std::string parentName, childName;
    XMLElement parent;

    //Extract the parent name from the XML query

    for(std::size_t i = 0; i < this->xmlquery.size();) {

        while(isLetter(this->xmlquery[i])) {
            
            parentName += this->xmlquery[i];
            i++;
        }

        if(this->xmlquery[i] == '/') {
            break;
        }
    }

    std::size_t size = parentName.size() + 1;


    //Extract the child name from the XML query
    for(std::size_t j = size; j < this->xmlquery.size(); j++) {

        childName += this->xmlquery[j];
    }

    std::vector<XMLElement> foundParents;

    root.findChildren(parentName, foundParents);

    std::vector<XMLElement> foundChildren;

    // Find the children matching the parent and child names
    for (std::size_t i = 0; i < foundParents.size(); ++i) {

        std::vector<XMLElement> currentChildren;

        foundParents[i].findChildren(childName, currentChildren);

        for (std::size_t j = 0; j < currentChildren.size(); ++j) {

            foundChildren.push_back(currentChildren[j]);
        }
    }

    // Print the values of the found children
    for(int i = 0; i < foundChildren.size(); i++) {

        std::cout << "[" << foundChildren[i].getValue() << "]" << std::endl;
    }

}

void XMLPath::OperatorBrackets(const XMLElement& root) const {

    std::string parentName, childName;

    // Extract the parent name from the XML query
    for(std::size_t i = 0; i < this->xmlquery.size();) {

        while(isLetter(this->xmlquery[i])) {
            
            parentName += this->xmlquery[i];
            i++;
        }

        if(this->xmlquery[i] == '/') {
            break;
        }
    }

    std::size_t size = parentName.size() + 1;
    int firstBracket = -1, secondBracket = -1;

    // Extract the child name and index of the first bracket from the XML query
    for(std::size_t j = size; j < this->xmlquery.size();) {

        while(isLetter(this->xmlquery[j])) {

            childName += this->xmlquery[j];
            j++;
        }

        if(this->xmlquery[j] == '[') {
            firstBracket = j;
            break;
        }
    }

    secondBracket = this->xmlquery.find(']');

    //Throws exception if there is missing bracket
    if(firstBracket == -1 || secondBracket == -1) {
        throw std::invalid_argument("Invalid query: Missing '[' or ']'");
    }

    std::string indexString = this->xmlquery.substr(firstBracket + 1, secondBracket - 1);

    int index;

    //converting string to number with std::stoi
    try {

        index = std::stoi(indexString);

    } catch (const std::invalid_argument&) {

        throw std::invalid_argument("Invalid query: Invalid index value");
    }


    std::vector<XMLElement> foundParents;

    root.findChildren(parentName, foundParents);

    std::vector<XMLElement> foundChildren;

    // Find the children matching the parent and child names
    for (std::size_t i = 0; i < foundParents.size(); ++i) {

        std::vector<XMLElement> currentChildren;

        foundParents[i].findChildren(childName, currentChildren);

        foundChildren.push_back(currentChildren[index - 1]);
        
    }

    for(int i = 0; i < foundChildren.size(); i++) {

        std::cout << "[" << foundChildren[i].getValue() << "]" << std::endl;
    }

}

void XMLPath::OperatorAtSign(const XMLElement& root) const {

    std::string parentName, childName;

    // Extract the parent name from the XML query
    for(std::size_t i = 0; i < this->xmlquery.size();) {

        while(isLetter(this->xmlquery[i])) {
            
            parentName += this->xmlquery[i];
            i++;
        }

        if(this->xmlquery[i] == '[') {
            break;
        }
    }

    std::size_t size = parentName.size() + 1;

    if(this->xmlquery[size] == '@') {

        for(std::size_t j = size + 1; j < this->xmlquery.size() - 1; j++) {
            childName += this->xmlquery[j];
        }
    }

    std::vector<XMLElement> foundParents;

    root.findChildren(parentName, foundParents);

    std::vector<Attributes> parentsWithSpecific;

    // Get the attributes of the parents matching the parent name
    for (std::size_t i = 0; i < foundParents.size(); i++) {

        parentsWithSpecific.push_back(foundParents[i].getAttributes());
    }

    // Print the attributes with the specified name
    for (std::size_t i = 0; i < parentsWithSpecific.size(); i++) {

        const Attributes& attributes = parentsWithSpecific[i];
        
        for (std::size_t j = 0; j < attributes.attr_names.size(); j++) {
            
            if (attributes.attr_names[j] == childName) {

            std::cout << "[" << attributes.attr_names[j] << "=" << attributes.attr_values[j] << "]" << std::endl;
            }
        }
    }
}

void XMLPath::OperatorEqual(const XMLElement& root) const {

    std::string parentName, childName, brotherName;

    // Extract the parent name from the XML query
    for(std::size_t i = 0; i < this->xmlquery.size();) {

        while(isLetter(this->xmlquery[i])) {
            
            parentName += this->xmlquery[i];
            i++;
        }

        if(this->xmlquery[i] == '[') {
            break;
        }
    }

    std::size_t size = parentName.size() + 1;
    std::size_t indexOne = 0, indexTwo = 0;

    // Extract the brother name and comparison text from the XML query
    for(std::size_t j = size; j < this->xmlquery.size();) {
        
        while(this->xmlquery[j] != '=') {
            
            brotherName += this->xmlquery[j];
            j++;
        }

        if(this->xmlquery[j] == '=') {
            indexOne = j + 1;
            break;
        }
    }

    for(std::size_t k = indexOne + 1; k < this->xmlquery.size(); k++) {

        if(this->xmlquery[k] == '\"') {
            indexTwo = k;
            break;
        }
    }

    std::string comparisonText;

    for (std::size_t i = indexOne + 1; i < indexTwo; i++) {

        comparisonText += this->xmlquery[i];
    }

    childName = this->xmlquery.substr(indexTwo + 3, this->xmlquery.size());

    std::vector<XMLElement> foundParents;
    root.findChildren(parentName, foundParents);

    std::vector<std::string> textForPrint;

    // Find the parents with matching brothers and values, and their children matching the child name
    for (std::size_t i = 0; i < foundParents.size(); i++) {

        const XMLElement& parent = foundParents[i];

        std::vector<XMLElement> foundChildren, foundBrothers;
        parent.findChildren(brotherName, foundBrothers);

        for (std::size_t j = 0; j < foundBrothers.size(); j++) {

            if(foundBrothers[j].getValue() == comparisonText) {
        
                parent.findChildren(childName, foundChildren);

                for(std::size_t k = 0; k < foundChildren.size(); k++) {

                    textForPrint.push_back(foundChildren[k].getValue());
                }
                
            }
        }

    }

    // Print the values of the found children
    for (std::size_t i = 0; i < textForPrint.size(); i++) {

        std::cout << textForPrint[i] << std::endl;
    }

}

void XMLPath::parse(const int number, const XMLElement& root) {

    try {
        if(number == 1) {
            OperatorSlash(root);

        } else if (number == 2) {
            OperatorBrackets(root);

        } else if (number == 3) {
            OperatorAtSign(root);

        } else if(number == 4) {
            OperatorEqual(root);

        } else {

            throw std::invalid_argument("Invalid query");
        }
        
    } catch (const std::exception& e) {
        
        std::cout << e.what() << std::endl;
    }

}