#include <iostream>
#include "vector.h"

using namespace my_vector;
using namespace std;

double read_and_sum(int);

int main()
{
    int n = 4;

    cout << "Welcome\n" << read_and_sum(n);
}

// legge s interi da cin e restituisce la loro somma, assumiamo che sia positivo
double read_and_sum(int s)
{
    Vector v;
    vector_init(v, s); // inizializziamo v con s elementi.

    for (int i = 0; i != s; ++i)
        cin >> v.elem[i];

    double sum = 0;

    for (int i = 0; i != s; i++)
        sum += v.elem[i];

    return sum;
}
