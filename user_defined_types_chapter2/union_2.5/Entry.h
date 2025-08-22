#pragma once

#include <string>
#include "Type.h"
#include "Value.h"

struct Entry
{
    std::string name;
    Type t;
    Value v; // Uses v.p if t == Type::ptr, uses v.i if t == Type::num
};