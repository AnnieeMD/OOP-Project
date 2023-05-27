#include "XMLElement.hpp"
#include <cstdlib>

XMLElement::XMLElement(const std::string& _tagname, const Attributes& _attribute_list, std::string& _text) {

    this->identifier = _tagname;
    this->attributes = _attribute_list;
    this->value = _text;
}

const std::vector<XMLElement>& XMLElement::getChildren() const {
    return this->children;
}

const Attributes& XMLElement::getAttributes() const {
    return this->attributes;
}

const std::string& XMLElement::getValue() const {
    return this->value;
}

void XMLElement::appendText(const std::string& _text) {

    this->value += _text;
}

XMLElement XMLElement::getChild(int i) const {

    if(i < children.size()) {
        return children[i];
        
    } else {
        throw std::out_of_range("Incorrect index");
    }
}

void XMLElement::findChild (const std::string &id, XMLElement &key) const {

    if(!this->attributes.attr_names.empty() && this->attributes.attr_names[0] == "id" && this->attributes.attr_values[0] == id) {

        key = *this;
        return;
    }

    for(std::size_t i = 0; i < children.size(); i++) {

        try{
            
            children[i].findChild(id, key);
            return;

        } catch (const std::exception& e) {

            // Child with the specified ID not found in this iteration, continue searching
        }
    
    }

    throw std::runtime_error("Child element with such ID not found.");

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
        os << "/>" << std::endl;
    
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

void XMLElement::CheckIds(XMLElement& element, std::vector<std::string>& usedIDs) {

    if (element.attributes.attr_names.empty()) {

        // Element does not have an "id" field, so append a unique identifier
        int random = 1 + (rand() % 100);

        element.attributes.attr_names.push_back("id");
        element.attributes.attr_values.push_back("0_" + std::to_string(random));

        usedIDs.push_back(element.attributes.attr_values[0]);

    } else {

        std::string originalID = element.attributes.attr_values[0];
        bool foundDublicate = false;
        bool isUnique = true;
        
        for(std::size_t i = 0; i < usedIDs.size(); i++) {
            if (usedIDs[i] == originalID) {
                isUnique = false;
                foundDublicate = true;
                break;
            }
        }

        if(foundDublicate) {

            int suffix = 1;

            std::string newId = originalID + "_" + std::to_string(suffix);

            //Generate a unique ID
            while(!isUnique) {

                isUnique = true;

                for(std::size_t i = 0; i < usedIDs.size(); i++) {

                    if (usedIDs[i] == newId) {
                        isUnique = false;
                        ++suffix;
                        newId = originalID + "_" + std::to_string(suffix);
                        break;
                    }
                }
            }

            element.attributes.attr_values[0] = newId;
            usedIDs.push_back(newId);
        
        } else {
            usedIDs.push_back(originalID);
        }
    }

    for(std::size_t i = 0; i < element.children.size(); i++) {
        CheckIds(element.children[i], usedIDs);
    }
}

void XMLElement::deleteAttr(const std::string& id, const std::string& key) {

    if(!attributes.attr_names.empty() && attributes.attr_names[0] == "id" && attributes.attr_values[0] == id) {

        for(std::size_t i = 0; i < attributes.attr_names.size(); i++) {
            
            if(attributes.attr_names[i] == key) {
                
                attributes.attr_names.erase(attributes.attr_names.begin() + i);
                attributes.attr_values.erase(attributes.attr_values.begin() + i); 
                std::cout << "You have successfully deleted the attribute!" << std::endl;
                return;
            }
        }
    }

    for(std::size_t i = 0; i < children.size(); i++) {

        children[i].deleteAttr(id, key);

    }
}

void XMLElement::newChild(const std::string& id) {

    if (!attributes.attr_names.empty() && attributes.attr_names[0] == "id" && attributes.attr_values[0] == id) {

        XMLElement node;

        std::cout << "Enter the name of the new successor: ";
        std::cin >> node.identifier;
        std::cin.ignore();

        node.attributes.attr_names.push_back("id");
        node.attributes.attr_values.push_back(id + "_" + std::to_string(children.size() + 1));
        this->children.push_back(node);

        std::cout << "You have successfully added a new child!" << std::endl;
        return;
    }

    for(std::size_t i = 0; i < this->children.size(); i++) {

        this->children[i].newChild(id);
    }
}

bool XMLElement::contains(const std::vector<XMLElement>& children, const XMLElement& element) const
{
    for (std::size_t i = 0; i < children.size(); i++) {
        
        if (children[i].attributes.attr_values[0] == element.attributes.attr_values[0]) {
            return true;
        }
    }

    return false;
}

void XMLElement::findChildren(const std::string& name, std::vector<XMLElement>& foundChildren) const {
    
    if(this->identifier == name && !contains(foundChildren, *this)) {
        
        foundChildren.push_back(*this);
    }

    for (std::size_t i = 0; i < children.size(); i++) {

        children[i].findChildren(name, foundChildren);
    }
}
