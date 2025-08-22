#pragma once

#include <string>
#include <variant>
#include "Node.h"

struct Entry_Variant
{
    std::string name;
    std::variant<Node*, int> v; // Type safe union

};