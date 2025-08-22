#pragma once

#include "Node.h"

class Node;

// Unions are just structs where their members are allocated in the same address, so that the union size is 
// the same of the biggest of its members. Indeed we can't use both p and i, but only one of them.
union Value
{
    Node* p;
    int i;
};