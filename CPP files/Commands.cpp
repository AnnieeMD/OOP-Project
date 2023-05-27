#include <iostream>
#include <fstream>
#include <sstream>

#include "Commands.hpp"

void Commands::toLower (std::string &str) {

    for (size_t i = 0; i < str.length(); i++) {

        if(str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] - 'A' + 'a';
        }

    }
}

void Commands::process(const std::string& command) {

    std::string generalCommand, commandFileName, id, key, value;

    std::istringstream iss(command);
    iss >> generalCommand >> commandFileName;

    std::istringstream iss1(command);
    iss1 >> generalCommand >> id >> key >> value;

    toLower(generalCommand);

    if(generalCommand == "open") {

        try{
            open(commandFileName);
        } catch(const std::invalid_argument& e) {
            
            std::cout << e.what() << std::endl;

        } catch (const std::runtime_error& e) {

            std::cout << e.what() << std::endl;
        }
        

    } else if (generalCommand == "help") {

        help();

    } else if (generalCommand == "exit") {
        exit();

    } else if (generalCommand == "print") {

        std::cout << tree;

    } else if (generalCommand == "save") {

        try {
            saveas(this->fileName);

        } catch (const std::runtime_error& e) {

            std::cout << e.what() << std::endl;
        } 
        
    } else if (generalCommand == "saveas") {

        std::ofstream newFile(commandFileName);

        try {
            saveas(commandFileName);
            
        } catch (const std::runtime_error& e) {

            std::cout << e.what() << std::endl;
        } 

    } else if (generalCommand == "select") {
        
        try {
            tree.select(id, key);

        } catch (const std::invalid_argument& e) {

            std::cout << e.what() << std::endl;
            
        } catch (const std::runtime_error& e) {

            std::cout << e.what() << std::endl;
        }

    } else if(generalCommand == "set") {

        tree.set(id, key, value);

    } else if (generalCommand == "children") {

        try {
            tree.children(id);

        } catch (const std::runtime_error& e) {
            
            std::cout << e.what() << std::endl;
        }

    } else if (generalCommand == "child") {

        try {

            int number = std::stoi(key); //convert string to number
            tree.child(id, number);

        } catch (const std::invalid_argument& e) {

            std::cout << e.what() << std::endl;
            
        } catch (const std::out_of_range& e) {

            std::cout << e.what() << std::endl;

        }  catch (const std::runtime_error& e) {

            std::cout << e.what() << std::endl;
        }

    } else if (generalCommand == "text") {

        try{
            tree.text(id);

        }catch (const std::runtime_error& e) {

            std::cout << e.what() << std::endl;
        }
        
    } else if(generalCommand == "delete") {
        
        try {
            tree.deleteA(id, key); 

        }catch (const std::runtime_error& e) {
            
            std::cout << e.what() << std::endl;
        } 
        

    } else if (generalCommand == "newchild") {

        tree.newChild(id);

    } else if (generalCommand == "xpath") {
        
        tree.xpath();
    }

}  

void Commands::open(const std::string& str) {

    if (file.is_open()) {

        throw std::invalid_argument("A file is already open!");

    } else {

        std::size_t size = str.size();


        if(str[size - 1] != 'l' || str[size - 2] != 'm' || str[size - 3] != 'x') {
            throw std::runtime_error("File is not a .xml file!");
        }

        this->fileName = str;

        this->file.open(fileName, std::iostream::in | std::ios::app);

        // It opens the file and checks if it is successfully opened, if it doesn't exists, creates a new one.

        if (!file.is_open()) {

        std::cout << "Couldn't open input file. Creating new file..." << std::endl;

        std::ofstream newFile(str);
        

        if (!newFile.is_open()) {

            throw std::runtime_error("Failed to create a new file");
        }

        newFile.close();

        file.open(str);

        if (!file.is_open()) {

            throw std::runtime_error("Failed to open a new file");
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
            this->tree.UniqueID();
            this->tree.UniqueID();

        }
    }

    file.close();
} 

bool Commands::close() {

    std::cout << "File " << this->fileName << " successfully closed!" << std::endl;

    std::cout << "Do you want to open another file or exit the program?" << std::endl;
    std::cout << "Choose between continue or exit: " << std::endl;

    std::string str1;
    std::cin >> str1;

    toLower(str1);

    if(str1 == "exit") {

        exit();
        return false;

    } else if (str1 == "continue") {
    
        std::cout << "Enter the file path: " << std::endl;

        std::string fileName;
        std::cin >> fileName;
        std::cin.ignore();

        std::cout << "Opening another file..." << std::endl;
        std::cout << "------------------" << std::endl;
        
        try {
            this->open(fileName);

        } catch (const std::invalid_argument& e) {
            
            std::cout << e.what() << std::endl;

        } catch (const std::runtime_error& e) {
            
            std::cout << e.what() << std::endl;
        }
    }
        
    return true;

}

void Commands::saveas(const std::string& fileName) {

    std::size_t size = fileName.size();

    if(fileName[size - 1] != 'l' || fileName[size - 2] != 'm' || fileName[size - 3] != 'x') {
        throw std::runtime_error("File is not a .xml file!");
    }

    std::ofstream output(fileName);

    if(!output.is_open()) {
        
        throw std::runtime_error("Couldn't open the file!");
    }

    output << tree;

    this->fileName = fileName;

    if(output.good()) {
        std::cout << "File " << this->fileName << " successfully saved!" << std::endl;
    } else {
        std::cout << "Error saving file!" << std::endl;
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
        << "XPATH: operations to perform simple XPath 2.0 queries on the root element\n"; 
} 

void Commands::exit() {
    
    std::cout << "Exiting the program..." << std::endl;
    return;
}