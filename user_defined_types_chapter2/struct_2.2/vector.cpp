#include "vector.h"

using namespace my_vector;

my_vector::Vector::~Vector()
{
    delete[] elem;
}

void my_vector::vector_init(Vector& v, int s)
{
    v.elem = new double[s];
    v.sz = s;
}

void my_vector::f(Vector v, Vector& rv, Vector* pv)
{
    int i1 = v.sz;      // accesso tramite nome
    int i2 = rv.sz;     // accesso tramite riferimento 
    int i3 = pv->sz;    // accesso tramite puntatore
}