#pragma once

#include "XMLElement.hpp"
#include "XMLTree.hpp"

#include <fstream>

class Generator {

public:

static XMLTree GenerateTree(std::vector<std::string>& content);

static XMLElement TreeGenerator(const std::vector<std::string>& content, size_t& i);

};