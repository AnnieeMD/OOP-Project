#pragma once

#include <string>
#include <vector>

/*!
 * @struct Attributes
 * @brief Represents a collection of attributes for an XML element.
 */

struct Attributes {

    std::vector<std::string> attr_names; /*!< The names of the attributes. */
    std::vector<std::string> attr_values; /*!< The values of the attributes. */
};