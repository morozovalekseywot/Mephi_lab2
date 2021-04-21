#pragma once
#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdexcept>

using namespace std;

template<class T>
class Dynamic_array
{
private:
    int m_size;
    int capacity;
    T *str;
public:
    Dynamic_array()
    {
        m_size = 0;
        capacity = 0;
        str = NULL;
    }
    Dynamic_array(const Dynamic_array<T> &array)
    {
        m_size = array.m_size;
        capacity = m_size;
        str = new T[array.size];
        memcpy(str, array.data, array.size * sizeof(T));
    }

    [[maybe_unused]]Dynamic_array(int size, T def)
    {
        if (size < 0)
            throw bad_alloc("Constructor Dynamic_array error,size<0");
        m_size = size;
        capacity = size;
        for (int i = 0; i < size; ++i)
        {
            str[i] = def;
        }
        if (size != 0)
            str = new T[size];
        else
            str = 0;
    }

    ~Dynamic_array<T>()
    {
        delete[] str;
        str = nullptr;
    }

    /*
     при уменьшении размера массива, элементы остаются и можно попробовать
     обратиться к ним, так же сделано и в реализации stl <Vector>
     */
    void resize(int size)
    {
        if (size < 0)
            throw bad_array_new_length("Dynamic_array::resize error,new size<0");
        if (size > capacity)
        {
            int new_capacity = max(size, m_size * 2);
            T *new_data = new T[new_capacity];
            for (int i = 0; i < m_size; ++i)
                new_data[i] = str[i];
            delete[] str;
            memcpy(new_data, str, sizeof(T) * size);
            str = new_data;
            capacity = new_capacity;
        } else
            m_size = size;
    }

    void push_back(T &c)
    {
        resize(m_size + 1);
        str[m_size - 1] = c;
    }

    void insert(T &c, int &i)
    {
        if (i < 0 || i >= m_size)
            throw out_of_range("Index out of range");
        resize(m_size + 1);
        for (int j = m_size; j > i; j--)
            str[j] = str[j - 1];
        str[i] = c;
        m_size++;
    }

    void push_begin(T &c) override
    {
        resize(m_size + 1);
        for (int j = m_size; j > 0; j--)
            str[j] = str[j - 1];
        str[0] = c;
        m_size++;
    }

    [[nodiscard]] int size() const
    {
        return m_size;
    }
    // получение значения
    T operator[](int i) const
    {
        if (i < 0 || i >= m_size)
            throw out_of_range("Index out of range");
        return str[i];
    }
    // присвоение значения
    T &operator[](int i)
    {
        if (i < 0 || i >= m_size)
            throw out_of_range("Index out of range");
        return str[i];
    }

    void print()
    {
        for (int i = 0; i < m_size; ++i)
            cout << str[i];
    }
};
