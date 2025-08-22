import my_vector;

 // We could import this as module as well, but for example sake we are showing that different syntaxes can be used together.
#include <cmath>

double sqrt_sum(My_Vector&);

int main ()
{

}

double sqrt_sum(My_Vector& v)
{
    double sum = 0;
    for int (i = 0; i != v.size(); i++)
        sum += std::sqrt(v[i]);

    return sum;
}