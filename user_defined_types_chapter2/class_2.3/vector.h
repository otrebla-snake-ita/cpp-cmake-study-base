namespace my_vector
{
    class Vector 
    {
        public:
            Vector(int s);              // costruisce un vector
            double& operator[](int i);  // accesso agli elementi: sottoscrizione
            const int size();
            ~Vector();
        private:
            double* elem;   // puntatore agli elementi
            int sz;         // totale elementi
    };
}