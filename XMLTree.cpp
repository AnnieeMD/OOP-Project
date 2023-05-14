#include "XMLTree.hpp"
#include "XMLElement.hpp"

XMLTree::XMLTree(XMLElement _root) {
    this->root = _root;
}

XMLElement XMLTree::find(const std::string& id) const {
    
    XMLElement result;
    root.findChild(id, result);
    return result;
}

XMLTree::XMLTree(const XMLTree &tree) {
    root = tree.root;
}

XMLTree &XMLTree::operator=(const XMLTree &tree) {

    if(this != &tree) {
        
        root = tree.root;
    }

    return *this;
}

const XMLElement& XMLTree::getRoot() const {
    return root;
}

std::ostream &operator<<(std::ostream &os, const XMLTree &tree) {

    XMLElement::printXMLElement(os, tree.root, 0);
    return os;
}

void XMLTree::select(const std::string &id, const std::string &key) const {
    
    XMLElement child;

    root.findChild(id, child);

    if(!child.attributes.attr_names.empty()) {

        for(std::size_t i = 1; i < child.attributes.attr_names.size(); i++) {

            if(key == child.attributes.attr_names[i]) {

                std::cout << child.attributes.attr_values[i] << std::endl;
                return;

            }
        }

        std::cout << "No such attribute!" << std::endl;
            
    } else {

        std::cout << "No such id!" << std::endl;
    }
}

void XMLTree::set(const std::string &id, const std::string &key, const std::string &value) {

    if(root.attributes.attr_names[0] == "id" && root.attributes.attr_values[0] == id) {

        for(std::size_t i = 0; i < root.attributes.attr_names.size(); i++) {
            
            if(root.attributes.attr_names[i] == key) {
                
                root.attributes.attr_values[i] = value;
                std::cout << "You have successfully changed the value of the attribute with id: " << id << std::endl;
                return;
            }
        }
    }

    for(std::size_t i = 0; i < root.children.size(); i++) {

        XMLTree childTree(root.children[i]);
        childTree.set(id, key, value);
        root.children[i] = childTree.root;
    }
    
}

void XMLTree::children(const std::string &id) const {

    XMLElement child;
    root.findChild(id, child);

    std::cout << "Children of " << id << ": " << std::endl;
    std::cout << child.children.size() << " children:" << std::endl;
    std::cout << "--------------------------------" << std::endl;
    for(std::size_t i = 0; i < child.children.size(); i++) {
        std::cout << child.children[i] << std::endl;
    }
}

void XMLTree::child(const std::string& id, int n) const {

    XMLElement child;
    root.findChild(id, child);

    std::cout << "Child " << n << " of " << id << ": " << std::endl;
    std::cout << child.getChild(n).identifier << std::endl;

}

void XMLTree::text(const std::string& id) const {

    XMLElement result;
    root.findChild(id, result);

    std::cout << result.identifier << "\'s text: " << result.value << std::endl;

}

// void XMLTree::printText(const std::string &id) const {

//     XMLElement resultNode;
//     root.getChild(id, resultNode);

//     std::cout << resultNode.getID() << "\'s text: " << resultNode.getValue() << '\n';
// }