#include "vector.h"

using namespace my_vector;

// Lista di inizializzatori di membri, in ordine "elem" e poi "sz".
Vector::Vector(int s) : elem { new double[s] }, sz {s} { } 
Vector::~Vector() { delete[] elem; }

double& Vector::operator[](int i) { return elem[i]; } 
const int Vector::size() { return sz; }