#pragma once

#include "attributes.hpp"

#include <iostream>
#include <stdexcept>

/*!
 * @class XMLElement
 * @brief Represents an XML element.
 */

class XMLElement {

private:

    std::string identifier;  /*!< The name of the XML element. */
    std::string value; /*!< The value or text content of the XML element. */
    std::vector<XMLElement> children; /*!< The vector of child elements of the XML element. */
    Attributes attributes; /*!< The attributes of the XML element. */


    friend class XMLTree;

    /*!
    * @brief Checks if a vector of children contains a specific element.
    * @param children The vector of children.
    * @param element The element to check for.
    * @return True if the element is present, false otherwise.
    */
    bool contains(const std::vector<XMLElement>& children, const XMLElement& element) const;

public:

    /*!
    *@brief Default constructor
    */
    XMLElement() = default;

    /*!
    * @brief Constructs an XMLElement object.
    * @param _tagname The tag name of the element.
    * @param _attribute_list The attribute list of the element.
    * @param _text The text value of the element.
    */
    XMLElement(const std::string& _tagname, const Attributes& _attribute_list, std::string& _text);

    /*!
    * @brief Retrieves the children of the element.
    * @return A constant reference to the vector of child elements.
    */
    const std::vector<XMLElement>& getChildren() const;

    /*!
    * @brief Retrieves the attributes of the element.
    * @return A constant reference to the attributes of the element.
    */
    const Attributes& getAttributes() const;

    /*!
    * @brief Retrieves the attributes of the element.
    * @return A constant reference to the attributes of the element.
    */
    const std::string& getValue() const;

    /*!
    * @brief Appends text to the element's value.
    * @param _text The text to append.
    */
    void appendText(const std::string&_text);

    /*!
    * @brief Retrieves a child element by index.
    * @param i The index of the child element to retrieve.
    * @return The child element.
    * @throw std::out_of_range If the index is out of range.
    */
    XMLElement getChild(int i) const;

    /*!
    * @brief Finds a child element with the specified ID.
    * @param id The ID to search for.
    * @param key A reference to store the found child element.
    * @throw std::runtime_error If the child element with the specified ID is not found.
    */
    void findChild(const std::string &id, XMLElement& result) const;

    /*!
    * @brief Adds a child element to the current element.
    * @param child The child element to add.
    */
    void addChild(const XMLElement& child);

    /*!
    * @brief Prints the attributes to the output stream.
    * @param os The output stream.
    * @param attributes The attributes to print.
    */
    static void printAttributes(std::ostream &os, const Attributes &attributes);
    
    /*!
    * @brief Adds spaces to the output stream.
    * @param os The output stream.
    * @param spaces The number of spaces to add.
    */
    static void addSpaces (std::ostream &os, int spaces);
    
    /*!
    * @brief Prints an XML element to the output stream.
    * @param os The output stream.
    * @param element The element to print.
    * @param spaces The number of spaces for indentation.
    */
    static void printXMLElement(std::ostream &os, const XMLElement &element, int spaces);
   
    /*!
    * @brief Checks and generates unique IDs for the elements recursively.
    * @param element The element to check and modify the ID.
    * @param usedIDs The list of used IDs.
    */
    void CheckIds(XMLElement& element, std::vector<std::string>& usedIDs);
    
    /*!
    * @brief Deletes an attribute from an element with a specific ID.
    * @param id The ID of the element to delete the attribute from.
    * @param key The key of the attribute to delete.
    */
    void deleteAttr(const std::string& id, const std::string& key);

    /*!
    * @brief Adds a new child element to an element with a specific ID.
    * @param id The ID of the element to add the new child to.
    */
    void newChild(const std::string& id);

    /*!
    * @brief Finds all children with a specific name.
    * @param name The name of the children to find.
    * @param foundChildren A vector to store the found children.
    */
    void findChildren(const std::string& name, std::vector<XMLElement>& foundChildren) const;
};