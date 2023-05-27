#pragma once

#include "XMLElement.hpp"
#include "XMLGeneratorT.hpp"
#include "XMLParser.hpp"
#include "XMLPath.hpp"
#include "XMLTree.hpp"

/*!
*@class Commands
*@brief This class processes the commands given by the user and 
*performs the corresponding operations.
*/

class Commands {

private:

    std::ifstream file; /*!<Input file*/
    std::string fileName; /*!<Name of the input file*/

    XMLTree tree; /*!<The tree on which all operations will be performed*/

public:

    Commands() = default;

    /*!
    * @brief Converts a string to lowercase.
    * 
    * @param str The string to convert.
    */
    void toLower (std::string &str);

    /*!
    * @brief Processes a command.
    * 
    * @param command The command to process.
    */
    void process(const std::string& command);

    /*!
    * @brief Opens an XML file for processing.
    * 
    * @param str The name of the file to open.
    * @throws std::invalid_argument if a file is already open.
    * @throws std::runtime_error if the file is not a .xml file or if there is an error opening the file.
    */
    void open(const std::string& str);

    /*!
    * @brief Closes the current XML document.
    * 
    * @return True if the user wants to continue with another file, False if the user wants to exit the program.
    */
    bool close();

    /*!
    * @brief Saves the current XML document with a new file name.
    * 
    * @param fileName The new file name to save the XML document.
    */
    void saveas(const std::string& fileName);
    
    /*!
    * @brief Displays the available commands.
    */
    void help();

    /*!
    * @brief Exits the program.
    */
    void exit();

};
