#include "XMLPath.hpp"
#include "XMLTree.hpp"
#include "XMLElement.hpp"

std::ostream &operator<<(std::ostream &os, const XMLTree &tree) {

    XMLElement::printXMLElement(os, tree.root, 0);
    return os;
}

XMLTree::XMLTree(XMLElement& _root) {
    this->root = _root;
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

XMLElement XMLTree::getRoot() const {
    return root;
}

void XMLTree::UniqueID() {
    
    std::vector<std::string> usedIDs;
    this->root.CheckIds(this->root,usedIDs);
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

        throw std::invalid_argument("No such attribute");
            
    } else {

        throw std::invalid_argument("No such id");
    }
}

void XMLTree::set(const std::string &id, const std::string &key, const std::string &value) {

    if(!root.attributes.attr_names.empty() && root.attributes.attr_names[0] == "id" && root.attributes.attr_values[0] == id) {

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

    XMLElement result;
    root.findChild(id, result);

    const std::vector<XMLElement>& children = result.getChildren();

    std::cout << "Children's attributes: " << std::endl;

    for(std::size_t i = 0; i < children.size(); i++) {

        const Attributes& child_attr = children[i].getAttributes();

        for(std::size_t j = 0; j < child_attr.attr_names.size(); j++) {

            std::cout << "(" << child_attr.attr_names[j] << "=" << child_attr.attr_values[j] << ")" << std::endl;
        }

   }
}

void XMLTree::child(const std::string& id, int n) const {

    XMLElement child;
    root.findChild(id, child);

    if (n > child.children.size()) {
        throw std::invalid_argument("No such successor exists");
    }

    std::cout << "Child " << n << " of " << id << ": " << child.getChild(n-1).identifier << std::endl;

}

void XMLTree::text(const std::string& id) const {

    XMLElement result;
    root.findChild(id, result);

    std::cout << result.identifier << "\'s text: " << result.value << std::endl;

}

void XMLTree::deleteA(const std::string &id, const std::string &key) {

    if (key != "id") {

       root.deleteAttr(id, key);

    } else {
        throw std::runtime_error("You cannot delete id");
    }
}

void XMLTree::newChild(const std::string& id) {

    root.newChild(id);
}

void XMLTree::xpath() const {
    
    std::cout << "Supported XPath Queries:" << std::endl;
    std::cout << "1. The / operator: (<>/<>) returns a list of all elements of <> that are child elements of <>, for each <> element in the file.\n" 
              << "2. The [] operator: (<>/<>[index]) returns an element of <> that is a child of <> for each element of <> in the file.\n"
              << "3. The @ operator: (<>[@<>]) returns a list of <> attributes of all <> elements in the file.\n"
              << "4. The = operator: (<>[<>=" "]/<>) returns a list of all names (contents of child element <>) of elements <> in the file that have a child element <> with text content \" \"." << std::endl;

    std::cout << "Enter the number of the query you wish to execute: ";

    int number;
    std::cin >> number;

    std::cout << "Enter the specific query: ";

    std::string query;
    std::cin >> query;
    std::cin.ignore();

    XMLPath xpath(query);
    xpath.parse(number, root);
}