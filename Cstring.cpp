#include "Cstring.hpp"
using namespace std;

template<typename T>
void dynamic_array<T>::resize(int size)
{
    if (size > capacity)
    {
        int new_capacity = max(size, m_size * 2);
        T *new_data = new T[new_capacity];
        for (int i = 0; i < m_size; ++i)
            new_data[i] = str[i];
        delete[] str;
        str = new_data;
        capacity = new_capacity;
    }
    m_size = size;
}

template<class T>
T dynamic_array<T>::concat(T &a, T &b)
{
    return nullptr;
}

template<class T>
T dynamic_array<T>::substr(T &a, int &i, int &k)
{
    return nullptr;
}

template<class T>
int dynamic_array<T>::find(T &a)
{
    return 0;
}

template<class T>
int dynamic_array<T>::rfind(T &a)
{
    return 0;
}

template<class T>
T dynamic_array<T>::replace(T &a, T &b)
{
    return nullptr;
}



template <typename T>
ostream &operator<<(ostream &out, dynamic_array<T> a)
{
    for (int i = 0; i < a.size(); ++i)
        out << a[i] << " ";
    return out;
}
