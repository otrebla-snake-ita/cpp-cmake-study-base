#include <iostream>
#include <variant>

#include "Entry.h"
#include "Entry_Variant.h"
#include "Node.h"


void f(Entry*);
void f_variant(Entry_Variant*);

int main()
{

    // new() is heap allocation, creates the object in an address owned by the program.
    // without new we would be allocating in the stack and owning it anyway. 

    Entry* e = new Entry(); // Heap alloc. 
    e->name = "Entry int";
    e->t = Type::num;
    e->v.i = 10;

    f(e);

    Entry* a = new Entry();
    a->name = "Entry ptr";
    a->t = Type::ptr;

    Node* n = new Node();
    a->v.p = n;
    a->v.p->val = 150;

    f(a);

    // Accessing the e.p->val we have a segmentation fault because the union is initializated with the other data type.
    //std::cout << e->v.p->val;
    //std::cout << '\n';
    //std::cout << a->v.i;

    Entry_Variant* ev = new Entry_Variant();
    ev->name = "Variant int";
    ev->v = 200;

    f_variant(ev);

    Node* nVariant = new Node();
    nVariant->val = 999;

    Entry_Variant* evPtr = new Entry_Variant();
    evPtr->name = "Variant ptr";
    evPtr->v = nVariant;

    f_variant(evPtr);

    delete evPtr;
    delete nVariant;
    delete ev;
    delete n;
    delete a;
    delete e;
}

void f(Entry* pe)
{
    if (pe->t == Type::num)
        std::cout << "Entry num: " << pe->v.i << '\n';
    else if (pe->t == Type::ptr)
        std::cout << "Entry ptr: " << pe->v.p->val << '\n';
}

void f_variant(Entry_Variant* pe)
{
    if (std::holds_alternative<int>(pe->v))         // Is v int?
        std::cout << "Entry variant int: " << std::get<int>(pe->v) << '\n';  // get the int 
    else if (std::holds_alternative<Node*>(pe->v))
        std::cout << "Entry variant ptr: " << std::get<Node*>(pe->v)->val << '\n';
}