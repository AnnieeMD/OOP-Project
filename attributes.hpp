#pragma once

#include <string>
#include <vector>

struct Attributes {

    std::vector<std::string> attr_names;
    std::vector<std::string> attr_values;

    bool operator == (const Attributes& other) const {
        return attr_names == other.attr_names && attr_values == other.attr_values;
    }
};