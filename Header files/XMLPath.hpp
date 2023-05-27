#pragma once

#include "XMLElement.hpp"
#include <string>

/*!
*@class XMLPath
*@brief Class takes care of handling the Xpath queries. 
*It supports 4 types of operators: /, [], @, =.
*/

/*!
*Note: Xpath queries work correctly only if the input is correctly entered, otherwise, 
*the program behaves unexpectedly or prompts you to re-enter the main command.
*/

class XMLPath {

private:

    std::string xmlquery; /*!< Name of the current query*/

public:

    /*!
    *@brief Constructor with parameters
    */
    XMLPath(const std::string& query);
    
    /*!
    * Check if a character is a letter.
    *
    * @param symbol The character to check.
    * @return True if the character is a letter, false otherwise.
    */
    bool isLetter(const char symbol) const;

    /*!
    * Process the slash operator in the XML path.
    *
    * @param root The root element of the XML document.
    */
    void OperatorSlash(const XMLElement& root) const;

    /*!
    * Process the brackets operator in the XML path.
    *
    * @param root The root element of the XML document.
    */
    void OperatorBrackets(const XMLElement& root) const;

    /*!
    * Process the at sign operator in the XML path.
    *
    * @param root The root element of the XML document.
    */
    void OperatorAtSign(const XMLElement& root) const;

    /*!
    * Process the equal operator in the XML path.
    *
    * @param root The root element of the XML document.
    */
    void OperatorEqual(const XMLElement& root) const;

    /*!
    * Parse the XML path query and execute the corresponding operator.
    *
    * @param number The operator number to execute.
    * @param root The root element of the XML document.
    */
    void parse(const int number, const XMLElement& root);

};