#include <iostream>
#include "vector.h"

using namespace std;
using namespace my_vector;

double read_and_sum(int);

int main()
{
    cout << "Welcome\n" << read_and_sum(6);
}

double read_and_sum(int s)
{
    Vector v(s);

    for (int i = 0; i != v.size(); ++i)
        cin >> v[i];
    
    double sum = 0;
    for (int i = 0; i != v.size(); ++i )
        sum += v[i];

    return sum;
}