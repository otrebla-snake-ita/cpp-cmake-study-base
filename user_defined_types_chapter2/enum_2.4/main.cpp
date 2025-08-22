#include <iostream>
#include "Color.h"
#include "Hardware_Component.h"

using namespace std;
using namespace my_color;
using namespace my_hardware;

int main() 
{
    // You can't initialize enum classes with numeric value (or vice-versa) unless using initialization syntax.
    // Color green = 2; // illegal.
    // int i = Color::red; // illegal
    Color red = Color{0}; // Bad readability and ugly
    Color blue {1}; // Better

    int x = int(Color::red);

    Color myRgb {Color::red};

    for (int i = 0; i < 3; i++)
    {
        cout << int(myRgb) << '\n';
        ++myRgb;
    }

    // --------------------------

    // Less type safety for "clasic" enums
    int myHw = Hardware_Component::CPU;
}