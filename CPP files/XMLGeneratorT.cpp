#include "XMLGeneratorT.hpp"
#include "XMLParser.hpp"

#include <stdexcept>

XMLElement Generator::TreeGenerator(const std::vector<std::string>& content, size_t& i) {

    if(content[i] != "") {

        if(XMLParser::isLeafTag(content[i])) {

            Tag openTag = XMLParser::getOpenTag(content[i]);

            size_t index = content[i].find('>');

            if(index != content[i].size() - 1) {

                std::string line2 = content[i].substr(index + 1, content[i].size());

                std::string text = line2.substr(0, line2.find('<'));

                XMLElement node(openTag.name, openTag.attributes, text);

                return node;
            }
            
        } else {

            Tag openTag = XMLParser::getOpenTag(content[i]);
            std::string str = "";
            
            XMLElement node(openTag.name, openTag.attributes, str);
            
            while(!XMLParser::hasClosingTag(content[i + 1])) {
            
            i++;

                if(XMLParser::hasOpenTag(content[i])) {
                    
                    try {

                        node.addChild(Generator::TreeGenerator(content, i));

                    } catch (const std::exception& e) {

                        std::cout << e.what() << std::endl;
                    }
                    
                } else {
                    node.appendText(content[i]);
                }
            }

            i++;
            return node;  
        }
         
    }

    throw std::runtime_error("Invalid content.");
}

XMLTree Generator::GenerateTree( std::vector<std::string>& content) {

    size_t i = 0;

    try {

        XMLElement root = TreeGenerator(content, i);
        return XMLTree(root);

    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;

    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return XMLTree();
    
}