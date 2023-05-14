#pragma once

#include <string>
#include "XMLTree.hpp"

class XMLPath {

public:

    static std::vector<const XMLElement*> getElements(const std::string&, const XMLTree&);

};