#include "XMLGeneratorT.hpp"
#include "XMLParser.hpp"

// ID checker

// Изграждането на дървото става рекурсивно, като се прочита всеки ред от файла, този ред бива обработен и от него се 
// създава един от следните обекти: Tag, обикновен текст към даден елемент, Tag от тип листо. 
// Елементите от дървото се описват с клас XMLElement, който съдържа името на таг-а, списък с атрибутите на таг-а, 
// текста в този таг и списък с наследници(вложени елементи). Всеки елемент е с уникално id. 
// Дъното при рекурсивното създаване на дървото е при достигане на Tag от тип листо(т.е елемент, който няма вложени елементи).

XMLElement Generator::TreeGenerator(const std::vector<std::string>& content, size_t& i) {


    if(content[i] != "") {

        if(XMLParser::isLeafTag(content[i])) {

            Tag openTag = XMLParser::getOpenTag(content[i]);

            size_t index = content[i].find('>');

            if(index != content[i].size() - 1) {

                std::string line2 = content[i].substr(index + 1, content[i].size());

                std::string text = line2.substr(0, line2.find('<'));

                XMLElement node(openTag.name, openTag.attributes, text);
                node.CheckIds();

                return node;

            }

        } else {

            Tag openTag = XMLParser::getOpenTag(content[i]);

            XMLElement node(openTag.name, openTag.attributes, "");
            node.CheckIds();
            
            while(!XMLParser::hasClosingTag(content[i + 1])) {
            
            i++;

                if(XMLParser::hasOpenTag(content[i])) {
                    
                    node.addChild(Generator::TreeGenerator(content, i));

                } else {
                    node.appendText(content[i]);
                }
            }

            i++;
            return node;  
        }
         
    }

    return XMLElement();
}

XMLTree Generator::GenerateTree( std::vector<std::string>& content) {

    size_t i = 0;

    XMLElement root = TreeGenerator(content, i);
    return XMLTree(root);
}