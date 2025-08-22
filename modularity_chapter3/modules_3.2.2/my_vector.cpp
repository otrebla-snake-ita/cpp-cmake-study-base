module;

export module my_vector;

export class My_Vector
{
    public:
        My_Vector(int s);
        const double& operator[](int i) const; // Returning a const value and prevents changing values in the class.
        int size() const;
    private:
        double* elem; 
        int sz;
};

My_Vector::My_Vector(int s)
    : elem { new double[s] }, sz {s} 
    {}

const double& My_Vector::operator[](int i) const
{
    return elem[i];
}

int My_Vector::size() const
{
    return sz;
}

export bool operator==(const My_Vector& v1, const My_Vector& v2)
{
    if (v1.size() != v2.size()) 
        return false;

    for (int i = 0; i < v1.size(); ++i)
    {
        if (v1[i] != v2[i])
            return false;
    }

    return true;
}