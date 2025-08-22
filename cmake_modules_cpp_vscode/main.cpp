#include <fmt/format.h>

import calculator;

int main() 
{
    int value{5};
    int count{10};
    Calculator calc;
    auto result = calc.add(value, count);

    fmt::println("The value is: {}", value);
    fmt::println("Hello World, my friend!");
    fmt::println("The result is: {}", result);
    return 0;
}