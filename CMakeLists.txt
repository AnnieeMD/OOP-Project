cmake_minimum_required(VERSION 3.0.0)
project(FinalProject VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(FinalProject main.cpp Commands.cpp XMLElement.cpp XMLGeneratorT.cpp XMLParser.cpp XMLPath.cpp XMLTree.cpp Runner.cpp)

add_executable(Tests Commands.cpp XMLElement.cpp XMLGeneratorT.cpp XMLParser.cpp XMLPath.cpp XMLTree.cpp testsForGenerator.cpp 
               testsForParser.cpp testsForPath.cpp testsForTree.cpp testsForCommands.cpp testsForElement.cpp) 

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
