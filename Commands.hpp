#include "XMLElement.hpp"
#include "XMLGeneratorT.hpp"
#include "XMLParser.hpp"
#include "XMLPath.hpp"
#include "XMLTree.hpp"

class Commands {

private:

    std::ifstream file;
    std::string fileName;

    XMLTree tree;

public:

    Commands() = default;
    ~Commands() = default;

    void open(std::string& str);
    void process(std::string& command);
    void close(std::string& str);
    void toLower (std::string &str);
    void help();
    void exit();

    void saveas(std::string& fileName);


};