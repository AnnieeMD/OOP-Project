#pragma once

#include <string>
#include <vector>

#include "attributes.hpp"

/*!
 * @struct Tag
 * @brief Represents a tag in an XML document.
 */

struct Tag {

    std::string name = ""; /*!< The name of the tag. */
    Attributes attributes; /*!< The attributes associated with the tag. */

    /*!
    * @brief Default constructor for the Tag struct.
    */
    Tag() = default;

    /*!
    * @brief Constructs a Tag object with the specified identifier and attributes.
    * @param identifier The name of the tag.
    * @param attributes The attributes associated with the tag.
    */
    Tag(const std::string& identifier, const Attributes& attributes) : name(identifier), attributes(attributes) {}

};