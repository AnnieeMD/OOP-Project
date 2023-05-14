#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

#include "Commands.hpp"

    void Commands::open(std::string& str) {

        if (file.is_open()) {

            std::cout << "A file is already open!" << std::endl;

        } else {

            this->fileName = str;

            this->file.open(fileName, std::iostream::in | std::ios::app);

        	// It opens the file and checks if it is successfully opened, if it doesn't exists, creates a new one.
    
            if (!file.is_open()) {

            std::cout << "Couldn't open input file. Creating new file..." << std::endl;

            std::ofstream newFile(str);

            if (!newFile.is_open()) {
                std::cerr << "Failed to create new file." << std::endl;
                return;
            }

            newFile.close();

            file.open(str);

            if (!file.is_open()) {

                std::cerr << "Failed to open new file." << std::endl;
                return;
            }

            } else {

                std::cout << "File " << str << " successfully opened!" << std::endl;
                
                std::vector<std::string> content;
                std::string line;
        
                while(!file.eof()) {

                    std::getline(file, line);
                    line = XMLParser::removeSpaces(line);

                    content.push_back(line);
                }

                this->tree = Generator::GenerateTree(content);

            }
        }

        file.close();
    } 

    void Commands::process(std::string& command) {

        std::string generalCommand, commandFileName;
        std::string id, key, value;

        std::istringstream iss(command);
        iss >> generalCommand >> commandFileName;

        std::istringstream iss1(command);
        iss1 >> generalCommand >> id >> key >> value;

        if(generalCommand == "open") {

            open(commandFileName);

        } else if (command == "close") {

            close(commandFileName);

        } else if (command == "help") {

            help();

        } else if (command == "exit") {
            exit();

        } else if (command == "print") {

            std::cout << tree;

        } else if (command == "save") {

            saveas(this->fileName);
            
        } else if (generalCommand == "saveas") {

            std::ofstream newFile(commandFileName);
            saveas(commandFileName);

        } else if (generalCommand == "select") {
            
            tree.select(id, key);

        } else if(generalCommand == "set") {

            tree.set(id, key, value);

        } else if (generalCommand == "children") {

            tree.children(id);

        } else if (generalCommand == "child") {

            int number = std::stoi(key); //convert string to number
            tree.child(id, number);

        } else if (generalCommand == "text") {

            tree.text(id);
            
        }
    }  

    void Commands::toLower (std::string &str) {

        for (size_t i = 0; i < str.length(); i++) {

            if(str[i] >= 'A' && str[i] <= 'Z') {
                str[i] = str[i] - 'A' + 'a';
            }

        }
    }  

    void Commands::help() {

    std::cout << "Available commands:\n"
            << "OPEN <fileName>: Load an XML file\n"
            << "CLOSE: Close the current XML document\n"
            << "SAVE: Save the current XML document to its current fileName\n"
            << "SAVEAS <filename>: Save the current XML document to a new fileName\n"
            << "HELP: Display this help message\n"
            << "EXIT: Exit the program\n"
            << "PRINT: Print the entire document\n"
            << "SELECT <id> <key>: Returns an attribute value given an element id and attribute key\n"
            << "SET <id> <key> <value>: Assigns to an attribute value\n"
            << "CHILDREN <id>: List the child elements of an element\n"
            << "CHILD <id> <n>: Access the Nth descendant of an element\n"
            << "TEXT <id>: Get the text value of an element\n"
            << "DELETE <id> <key>: Delete element attribute by key\n"
            << "NEWCHILD: Adding a NEW element successor \n"
            << "XPATH <XPath>: operations to perform simple XPath 2.0 queries on the root element\n"; 
    } 

    void Commands::close(std::string& str) {
    
    std::cout << "File " << str << " successfully closed!" << std::endl;

    std::cout << "Do you want to open another file or exit the program?" << std::endl;
    std::cout << "Choose between continue or exit: " << std::endl;

    std::string str1;
    std::cin >> str1;

    toLower(str1);

    if(strcmp(str1.c_str(), "exit") == 0) {

        exit();
        return;

    } else if (strcmp(str1.c_str(), "continue") == 0) {
    
        std::cout << "Enter the file path: " << std::endl;

        std::string fileName;
        std::cin >> fileName;

        std::cout << "Opening another file..." << std::endl;
        Commands nextCommand;
        nextCommand.open(fileName);

    }
}

    void Commands::saveas(std::string& fileName) {

    std::ofstream output(fileName);

    if(!output.is_open()) {
        std::cout << "Couldn't open file!" << std::endl;
        return;
    }

    output << tree;

    this->fileName = fileName;

    if(output.good()) {
        std::cout << "File " << this->fileName << " successfully saved!" << std::endl;
    } else {
        std::cout << "Error saving file!" << std::endl;
    }
    }

    void Commands::exit() {
        //cout << "You have an open file with unsaved changes, please select close or save first." << endl;
        std::cout << "Exiting the program..." << std::endl;
    }