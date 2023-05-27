#include "catch.hpp"
#include "XMLParser.hpp"

TEST_CASE("XMLParser-removeSpaces") {
    
    SECTION("Removes leading spaces from the string") {
        std::string str = "  test";
        std::string result = XMLParser::removeSpaces(str);
        REQUIRE(result == "test");
    }

    SECTION("Doesn't remove spaces within the string") {
        std::string str = "Hello    World!";
        std::string result = XMLParser::removeSpaces(str);
        REQUIRE(result == "Hello    World!");
    }

    SECTION("Handles empty string") {
        std::string str = "";
        std::string result = XMLParser::removeSpaces(str);
        REQUIRE(result == "");
    }
}

TEST_CASE("XMLParser- getOpenTag") {
    
    SECTION("Returns the open tag with the identifier and attributes") {
        std::string str = "<test attr1=\"value1\" attr2=\"value2\">";
        Tag result = XMLParser::getOpenTag(str);
        REQUIRE(result.name == "test");
        REQUIRE(result.attributes.attr_names.size() == 2);
        REQUIRE(result.attributes.attr_names[0] == "attr1");
        REQUIRE(result.attributes.attr_names[1] == "attr2");
        REQUIRE(result.attributes.attr_values.size() == 2);
        REQUIRE(result.attributes.attr_values[0] == "value1");
        REQUIRE(result.attributes.attr_values[1] == "value2");
    }

    SECTION("Throws an exception for an invalid open tag") {
        std::string str = "invalid tag";
        REQUIRE_THROWS_AS(XMLParser::getOpenTag(str), std::runtime_error);
    }
}

TEST_CASE("XMLParser- parseAttr") {
    
    SECTION("Parses attributes from the given line") {
        std::string str = "attr1=\"value1\" attr2=\"value2\">";
        size_t i = 0;
        Attributes result = XMLParser::parseAttr(str, i);
        REQUIRE(result.attr_names.size() == 2);
        REQUIRE(result.attr_names[0] == "attr1");
        REQUIRE(result.attr_names[1] == "attr2");
        REQUIRE(result.attr_values.size() == 2);
        REQUIRE(result.attr_values[0] == "value1");
        REQUIRE(result.attr_values[1] == "value2");
    }
}

TEST_CASE("XMLParser- hasOpenTag") {

    SECTION("Returns true of false for a string with or without an open tag") {
        std::string tag = "<tag>";
        bool result = XMLParser::hasOpenTag(tag);
        REQUIRE(result == true);

        std::string tag1 = "some text";
        bool resultt = XMLParser::hasOpenTag(tag1);
        REQUIRE(resultt == false);
    }
}

TEST_CASE("XMLParser- hasClosingTag") {
    SECTION("Returns true of false for a string with or without a closing tag") {
        std::string tag = "</tag>";
        bool result = XMLParser::hasClosingTag(tag);
        REQUIRE(result == true);

        std::string tag1 = "text";
        bool result1 = XMLParser::hasClosingTag(tag1);
        REQUIRE(result1 == false);
    }
}

TEST_CASE("XMLParser- isLeafTag") {
    SECTION("Return true for a leaf tag") {
        std::string tag = "<tag></tag>";
        bool result = XMLParser::isLeafTag(tag);
        REQUIRE(result == true);
    }

    SECTION("Returns false for a non-leaf tag") {
        std::string tag = "<tag/>";
        bool result = XMLParser::isLeafTag(tag);
        REQUIRE(result == false);
    }

    SECTION("Returns false for a string without an open tag") {
        std::string tag = "some text";
        bool result = XMLParser::isLeafTag(tag);
        REQUIRE(result == false);
    }
}