#pragma once

#include <string>
#include <vector>

#include "attributes.hpp"

struct Tag {

    std::string name = "";
    Attributes attributes;

    Tag() = default;
    Tag(const std::string& identifier, const Attributes& attributes) : name(identifier), attributes(attributes) {}

};