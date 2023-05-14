#include "XMLElement.hpp"

XMLElement::XMLElement(const std::string& _tagname, const Attributes& _attribute_list, std::string _text) {

    this->identifier = _tagname;
    this->attributes = _attribute_list;
    this->value = _text;
}

std::string XMLElement::getID() const {

    return identifier;
}

std::string XMLElement::getValue() const {

    return value;
}

void XMLElement::appendText(const std::string& _text) {

    this->value += _text;
}

XMLElement XMLElement::getChild(int i) const {

    if(i < children.size()) {
        return children[i];
        
    } else {
        std::cout << "Incorrect index" << std::endl;
        return XMLElement();
    }
}

void XMLElement::findChild (const std::string &id, XMLElement &key) const {

    if(this->attributes.attr_names[0] == "id" && this->attributes.attr_values[0] == id) {

        key = *this;
        return;
    }

    for(std::size_t i = 0; i < children.size(); i++) {

        children[i].findChild(id, key);
    }

}

void XMLElement::addChild(const XMLElement &child) {
    children.push_back(child);
}

void XMLElement::printAttributes(std::ostream &os, const Attributes &attributes) {

    for(std::size_t i = 0; i < attributes.attr_names.size(); i++) {
        os << " " << attributes.attr_names[i] << "=\"" << attributes.attr_values[i] << "\"";
        
    }

}

void XMLElement::addSpaces (std::ostream &os, int spaces) {

    for (int i = 0; i < spaces; i++) {
        os << " ";
    }

}

void XMLElement::printXMLElement(std::ostream &os, const XMLElement &element, int spaces) {

    addSpaces(os, spaces);

    os << "<" << element.identifier;
    printAttributes(os, element.attributes);

    if(element.children.empty() && element.value.empty()) {
        os << "/>";
    
    } else {
        os << ">";

        if(!element.value.empty()) {

            os << element.value;

        }

        if(!element.children.empty()) {

            os << std::endl;

            for (size_t i = 0; i < element.children.size(); i++) {
                const XMLElement& child = element.children[i];
                printXMLElement(os, child, spaces + 4);
            }

            addSpaces(os, spaces);
        }

        os << "</" << element.identifier << ">" << std::endl;
   }
}

void XMLElement::CheckIds() {

    int nextId = 1;

    for (std::size_t i = 0; i < children.size(); i++) {

        XMLElement& child = children[i];

        if (child.identifier.empty()) {

            // Element does not have an "id" field, so append a unique identifier
            child.identifier = "id=" + std::to_string(nextId);
            nextId++;

        } else {

            bool foundDublicate = false;

            for(std::size_t j = 0; j < i; j++) {

                if(children[j].identifier == child.identifier) {
                    foundDublicate = true;
                    break;
                }
            }

            if(foundDublicate) {

                int suffix = 1;

                std::string newId = child.identifier + "_" + std::to_string(suffix);

                bool isUnique = false;

                while(!isUnique) {
                    isUnique = true;

                    for(std::size_t j = 0; j < i; i++) {
                        if(children[j].identifier == newId) {
                            
                            isUnique = false;
                            suffix++;

                            newId = child.identifier + "_" + std::to_string(suffix);
                            break;
                        }
                    }
                }

                child.identifier = newId;
            }
        }
    }
}
