#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "XMLGeneratorT.hpp"
#include "XMLParser.hpp"

TEST_CASE ("TreeGenerator") {
    
    std::ifstream file;

    file.open("./example3.xml");

    REQUIRE(file.is_open());

    std::vector<std::string> content;
    std::string line;
    
    while(!file.eof()) {

        std::getline(file, line);

        line = XMLParser::removeSpaces(line);
        content.push_back(line);
    }

    std::size_t i = 0;

    XMLElement root = Generator::TreeGenerator(content, i);

    XMLElement element1 = root.getChild(1);
    XMLElement subelement1 = element1.getChild(0);

    REQUIRE(subelement1.getValue() == "Dumbo");
}

TEST_CASE("GenerateTree") {
    
    std::ifstream file;

    file.open("./example3.xml");

    REQUIRE(file.is_open());

    std::vector<std::string> content;
    std::string line;
    
    while(!file.eof()) {

        std::getline(file, line);

        line = XMLParser::removeSpaces(line);
        content.push_back(line);
    }

    XMLTree tree = Generator::GenerateTree(content);

    REQUIRE(tree.getRoot().getChildren().size() == 3);

    XMLElement element1 = tree.getRoot().getChild(0);
    XMLElement subelement = element1.getChild(2);

    REQUIRE(subelement.getValue() == "Africa");
}