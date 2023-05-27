#include "catch.hpp"
#include "XMLElement.hpp"
#include "XMLPath.hpp"
#include "XMLTree.hpp"
#include "XMLParser.hpp"
#include "XMLGeneratorT.hpp"

#include <fstream>

XMLTree helper() {
    
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

TEST_CASE("XMLPath- isLetter") {

    XMLPath xmlPath("");

    SECTION("Return true for a uppercase letters") {
        REQUIRE(xmlPath.isLetter('A') == true);
    }

    SECTION("Return true for a lowercase letters") {
        REQUIRE(xmlPath.isLetter('z') == true);
    }

    SECTION("Return false for non-letter characters") {
        REQUIRE(xmlPath.isLetter('1') == false);
    }
}

TEST_CASE("XMLParser- OperatorSlash") {

    XMLTree tree = helper();

    XMLPath xmlPath("person/name");
    xmlPath.OperatorSlash(tree.getRoot());
    std::cout << "------------------" << std::endl;
}

TEST_CASE("XMLParser- OperatorBrackets") {

    XMLTree tree = helper();

    XMLPath xmlPath("person/name[1]");
    xmlPath.OperatorBrackets(tree.getRoot());
    std::cout << "------------------" << std::endl;

}

TEST_CASE("XMLParser- OperatorAtSign") {

    XMLTree tree = helper();

    XMLPath xmlPath("person[@nationality]");
    xmlPath.OperatorAtSign(tree.getRoot());
    std::cout << "------------------" << std::endl;
    
}

TEST_CASE("XMLParser- OperatorEqual") {
    
    XMLTree tree = helper();

    std::string str = "person[address=\"Varna,Bulgaria\"]/name";

    XMLPath xmlPath(str);
    //xmlPath.OperatorEqual(tree.getRoot());
    //std::cout << "------------------" << std::endl;
    
}

TEST_CASE("XMLParser- parse") {

    SECTION("Operator/") {
        XMLTree tree = helper();
        XMLPath xmlPath("person/name");
        xmlPath.parse(1, tree.getRoot());
        std::cout << "------------------" << std::endl;
    }

    SECTION("Operator[]") {
        XMLTree tree = helper();
        XMLPath xmlPath("person/name[1]");
        xmlPath.parse(2, tree.getRoot());
        std::cout << "------------------" << std::endl;
    }

    SECTION("Operator@") {
        XMLTree tree = helper();
        XMLPath xmlPath("person[@nationality]");
        xmlPath.parse(3, tree.getRoot());
        std::cout << "------------------" << std::endl;
    }

    SECTION("Operator=") {
        XMLTree tree = helper();
        std::string str = "person[address=\"Varna,Bulgaria\"]/name";

        XMLPath xmlPath(str);
        // xmlPath.parse(4, tree.getRoot());
        // std::cout << "------------------" << std::endl;
    }

    SECTION("Invalid query") {
        XMLTree tree = helper();
        XMLPath xmlPath("");
        xmlPath.parse(6, tree.getRoot());
    }
}