#pragma once

#include "attributes.hpp"

#include <iostream>

class XMLElement {

private:

    std::string identifier;
    std::string value;
    std::vector<XMLElement> children;
    Attributes attributes;

    friend class XMLTree;

public:

    XMLElement() = default;
    ~XMLElement() = default;
    XMLElement(const std::string& _tagname, const Attributes& _attribute_list, std::string _text);

    std::string getID() const;
    std::string getValue() const;

    void appendText(const std::string&_text);

    XMLElement getChild(int i) const;
    void findChild(const std::string &id, XMLElement& result) const;
    void addChild(const XMLElement& child);

    static void printXMLElement(std::ostream &os, const XMLElement &element, int spaces);
    static void printAttributes(std::ostream &os, const Attributes &attributes);
    static void addSpaces (std::ostream &os, int spaces);
    
    void CheckIds();
};