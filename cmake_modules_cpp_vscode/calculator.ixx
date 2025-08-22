// This line informs build systems that this is a module file
module;

// Export module moduleName. The moduleName is used then to allow us to import it by using its name.
export module calculator;

// Export makes things visible to the outside. 
// Once that we have the module defined, we have to make it be picked up and processed by our CMakeLists file
export class Calculator 
{
    public:
    int add(int a, int b)
    {
        return a + b;
    }
    int subtract(int a, int b)
    {
        return a - b;
    }
    int multiply(int a, int b)
    {
        return a * b;
    }
    int divide(int a, int b)
    {
        return a / b;
    }
};