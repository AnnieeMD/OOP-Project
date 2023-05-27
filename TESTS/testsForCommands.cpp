#include "catch.hpp"
#include "Commands.hpp"

TEST_CASE("Commands") {

    Commands commands;

    SECTION("toLower"){
        std::string str = "Hello World";
        commands.toLower(str);
        REQUIRE(str == "hello world");
    }

    SECTION("open") {
        std::string validFileName = "test.xml";
        std::string invalid = "Hello.txt";
        
        REQUIRE_THROWS_WITH(commands.open(invalid), "File is not a .xml file!");
    }

    SECTION("saveas") {
        std::string validFileName = "test.xml";
        REQUIRE_NOTHROW(commands.saveas(validFileName));
        std::cout << "------------------" << std::endl;

        std::ifstream file(validFileName);
        REQUIRE(file.good() == true);
        file.close();
    }
}
