#pragma once

#include "XMLElement.hpp"

class XMLTree {

private:

    XMLElement root;
    
    XMLElement find(const std::string& id) const;
    friend std::ostream &operator<< (std::ostream &os, const XMLTree &tree);

public:

XMLTree() = default;

XMLTree(XMLElement _root);

XMLTree(const XMLTree &tree);

XMLTree &operator= (const XMLTree& tree);

~XMLTree() = default;

const XMLElement& getRoot() const;

void select(const std::string &id, const std::string &key) const;
void set(const std::string &id, const std::string &key, const std::string &value);
void children(const std::string &id) const;
void child(const std::string &id, int n) const;
void text(const std::string &id) const;

// void deleteATTR(const std::string &id, const std::string &key);
// void newChild(const std::string &id, const std::string &_tagName);



};