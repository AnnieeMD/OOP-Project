#include "catch.hpp"
#include "XMLElement.hpp"

TEST_CASE("XMLElement- getters") {

    std::string s1 = "tag1";
    std::string s2 = "text1";
    std::string s3 = "tag2";
    std::string s4 = "text2";

    SECTION("getAttributes") {
        XMLElement element(s1, {{"attr1", "value1"}}, s2);
    
        const Attributes& attributes = element.getAttributes();
        REQUIRE(attributes.attr_names[0] == "attr1");
    }

    SECTION("getValue") {
        XMLElement element(s3, {{"attr2", "value2"}}, s4);
        REQUIRE(element.getValue() == "text2");
    }

    std::string parent = "parent";
    std::string child1 = "child1";
    std::string p1 = "parent text";
    std::string ct = "child1 text";

    SECTION("getChild") {
        XMLElement element(parent, {{"attr2", "value2"}}, p1);
        XMLElement child(child1,{{"attr2", "value2"}}, ct);
        element.addChild(child);

        XMLElement ch = element.getChild(0);
        REQUIRE(ch.getValue() == "child1 text");
        REQUIRE_THROWS_AS(element.getChild(3), std::out_of_range);
    }
}

TEST_CASE("XMLElement- find") {

    std::string parent = "parent";
    std::string ch1 = "child1";
    std::string ch2 = "child2";
    std::string p1 = "parent text";
    std::string ct1 = "child1 text";
    std::string ct2 = "child2 text";
    
    SECTION("findChild") {

        Attributes attr;
        attr.attr_names.push_back("id");
        attr.attr_values.push_back("1");

        Attributes attr1;
        attr1.attr_names.push_back("id");
        attr1.attr_values.push_back("2");

        XMLElement element(parent, {{"attr", "value"}}, p1);
        XMLElement child1(ch1, attr, ct1);
        XMLElement child2(ch2, attr, ct2);

        element.addChild(child1);
        element.addChild(child2);

        XMLElement foundChild;

        element.findChild("1", foundChild);

        REQUIRE(foundChild.getValue() == ct1);
        REQUIRE_THROWS_AS(element.findChild("3", foundChild), std::runtime_error);
    }

    SECTION("findChildren") {
        XMLElement element(parent, {{"attr", "value"}}, p1);
        XMLElement child1 (ch1, {{"id", "1"}}, ct1);
        XMLElement child2 (ch2, {{"id", "2"}}, ct2);
        element.addChild(child1);
        element.addChild(child2);

        std::vector<XMLElement> foundChildren;
        element.findChildren("child1", foundChildren);
        REQUIRE(foundChildren[0].getAttributes().attr_names[0] == "id");
    }
}

TEST_CASE("XMLElement- help functions") {

    std::string tag = "tag";
    std::string text = "text";
    std::string parent = "parent";
    std::string ch1 = "child1";
    std::string ch2 = "child2";
    std::string p1 = "parent text";
    std::string ct1 = "child1 text";
    std::string ct2 = "child2 text";

    Attributes attr;
    attr.attr_names.push_back("id");
    attr.attr_values.push_back("1");

    SECTION("appendText") {
        XMLElement element(tag, attr, text);
        element.appendText(" additional");
        const std::string& value = element.getValue();
        REQUIRE(value == "text additional");
    }

    SECTION("deleteAttr") {

        XMLElement element(parent, attr, p1);
        XMLElement child (ch1, attr, ct1);
        element.addChild(child);
        element.deleteAttr("1", "attr");

        const Attributes& attributes = child.getAttributes();

        REQUIRE(attributes.attr_names.size() == 1);
        REQUIRE(attributes.attr_names[0] == "id");
    }

    SECTION("newChild") {
        XMLElement element(parent, attr, p1);
        XMLElement child (ch1, attr, ct1);
        element.addChild(child);
        element.newChild("1");
        std::cout << "------------------" << std::endl;

        const std::vector<XMLElement>& children = element.getChildren();
        REQUIRE(children.size() == 2);
        REQUIRE(children[1].getAttributes().attr_names[0] == "id");
    }
}