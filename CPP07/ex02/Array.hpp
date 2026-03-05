#ifndef ARRAY_HPP
#define ARRAY_HPP




template <typename T>

class Array
{
    private:
        T*        numbers;
        const int len;
    public: 
        Array(): numbers(new T[100]), len(100){};
        Array(unsigned int n): numbers(new T[n]), len(n){};
        Array(const Array& other){*this = other;};
        Array& operator=(const Array& other)
        {
            if(this != &other)
            {
                delete numbers;
                numbers = new T[len];
                for(int i = 0; i < len; i++)
                    numbers[i] = other.numbers[i];
            }
            return *this;
        }




};


#endif