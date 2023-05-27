#include "catch.hpp"
#include "XMLTree.hpp"
#include "XMLParser.hpp"
#include "XMLGeneratorT.hpp"

#include <fstream>

XMLTree helperFunction() {
    
    std::ifstream file;

    file.open("./example2.xml");

    if (!file.is_open()) {
        std::cout << "Problem with file!" << std::endl;
    }

    std::vector<std::string> content;
    std::string line;

    while(!file.eof()) {

        std::getline(file, line);
        line = XMLParser::removeSpaces(line);

        content.push_back(line);
    }

    XMLTree tree = Generator::GenerateTree(content);

    return tree;
}

TEST_CASE("XMLTree- select, set, children") {

    XMLTree tree = helperFunction();

    SECTION("select") {
        
        tree.select("7", "nationality");
        std::cout << "------------------" << std::endl;

        REQUIRE_THROWS_AS(tree.select("1", "nonexistent_key"), std::invalid_argument);
        REQUIRE_THROWS_AS(tree.select("noexistent_id", "nationality"), std::runtime_error);
        
    }

    SECTION("set") {
        tree.set("7", "nationality", "bulgarian");
        std::cout << "------------------" << std::endl;
        REQUIRE(tree.getRoot().getChild(2).getAttributes().attr_values[1] == "bulgarian");
    }

    SECTION("chidren") {
        
        tree.children("1");
        std::cout << "------------------" << std::endl;

        SECTION("Finding children attributes of non-existing id") {
            REQUIRE_THROWS_WITH(tree.children("noexistent_id"), "Child element with such ID not found.");
        }   
    }
}

TEST_CASE("XMLTree- child, text, deleteA") {

    XMLTree tree1 = helperFunction();
    
    SECTION("child") {
        
        tree1.child("7", 2);
        std::cout << "------------------" << std::endl;
    
        REQUIRE_THROWS_AS(tree1.child("nonexistent_id", 4), std::runtime_error);
        REQUIRE_THROWS_AS(tree1.child("7", 6), std::invalid_argument);
    }

    SECTION("text") {
        
        tree1.text("8");
        std::cout << "------------------" << std::endl;

        SECTION("Retrieving text content of non-existing id") {
            REQUIRE_THROWS_WITH(tree1.text("nonexistent_id"), "Child element with such ID not found.");
        }
    }

    SECTION("deleteA") {

        tree1.deleteA("1", "vegan");
        std::cout << "------------------" << std::endl;

        SECTION("Deleting id attribute") {
            REQUIRE_THROWS_WITH(tree1.deleteA("1_2", "id"), "You cannot delete id");
        }
    }
}