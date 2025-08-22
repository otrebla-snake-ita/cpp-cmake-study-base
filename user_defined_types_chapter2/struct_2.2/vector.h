namespace my_vector
{
    struct Vector 
    {
        double* elem; 
        int sz; // size
        ~Vector();
    };

    void vector_init(Vector& v, int s);
    
    void f(Vector v, Vector& rv, Vector* pv);
}
