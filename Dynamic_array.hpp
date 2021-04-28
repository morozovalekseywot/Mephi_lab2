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

    Dynamic_array(Dynamic_array<T> &array)
    {
        m_size = array.size();
        capacity = m_size;
        str = new T[array.size()];
        memcpy(str, array.str, array.size() * sizeof(T));
    }

    Dynamic_array(T *data, int count) : m_size(count)
    {
        if (count < 0)
            throw bad_alloc();
        capacity = m_size;
        str = new T[count];
        memcpy(str, data, count * sizeof(T));
    }

    explicit Dynamic_array(int size)
    {
        if (size < 0)
            throw bad_alloc();//"Constructor Dynamic_array error,size<0"
        m_size = size;
        capacity = size;
        str = new T[size];
        for (int i = 0; i < size; ++i)
        {
            str[i] = NULL;
        }
    }

    /// Деструктор
    ~Dynamic_array<T>()
    {
        delete[] str;
        str = nullptr;
    }

    /// получение размера
    [[nodiscard]] int size() const
    {
        return m_size;
    }

    /*
    при уменьшении размера массива, элементы остаются и можно попробовать
    обратиться к ним, так же сделано и в реализации stl <Vector>
   */
    void resize(int size)
    {
        if (size < 0)
            throw bad_array_new_length();//"Dynamic_array::resize error,new size<0"
        if (size > capacity)
        {
            int new_capacity = size;
            T *new_data = new T[new_capacity];
            memcpy(new_data, str, sizeof(T) * size);
            delete[] str;
            str = new_data;
            capacity = new_capacity;
            m_size = size;
        } else
            m_size = size;
    }

    /// вставка элемента в конец
    void append(T &item)
    {
        resize(m_size + 1);
        str[m_size - 1] = item;
    }

    /// вставка элемента в начало
    void prepend(T &item)
    {
        resize(m_size + 1);
        for (int j = m_size; j > 0; j--)
            str[j] = str[j - 1];
        str[0] = item;
        m_size++;
    }

    /// вставка элемента по индексу
    void insert(T &item, int &i)
    {
        if (i < 0 || i >= m_size)
            throw out_of_range("Index out of range");
        resize(m_size + 1);
        for (int j = m_size; j > i; j--)
            str[j] = str[j - 1];
        str[i] = item;
    }

    T getFirst() const
    {
        return get(0);
    }

    T getLast() const
    {
        return get(m_size - 1);
    }

    T &get(int i) const
    {
        if (i < 0 || i >= m_size)
            throw out_of_range("Index out of range");
        return str[i];
    }

    void set(int index, T item)
    {
        str[index] = item;
    }

    /// получение значения
    T operator[](int i) const
    {
        if (i < 0 || i >= m_size)
            throw out_of_range("Index out of range");
        return str[i];
    }

    /// присвоение значения
    T &operator[](int i)
    {
        if (i < 0 || i >= m_size)
            throw out_of_range("Index out of range");
        return str[i];
    }

    bool operator==(const T &a)
    {
        if (a.size() != m_size)
            return false;
        for (int i = 0; i < m_size; i++)
            if (str[i] != a[i])
                return false;
        return true;
    }

    //Dynamic_array<T> &operator=(const Dynamic_array<T> &a);
    /*
    /// получение substr с begin до end
    Dynamic_array<T> *substr(int begin, int end) const
    {};

    /// Соединение двух строк
    Dynamic_array<T> *concat(Dynamic_array<T> *array) const
    {};

    /// поиск первого вхождения подстроки в строке между begin и end
    int find(const Dynamic_array<T> *a, int begin = 0, int end = -1) const
    {};

    /// поиск последнего вхождения подстроки в строке между begin и end
    int rfind(const Dynamic_array<T> *a, int begin = 0, int end = -1) const
    {};

    /// замена всех вхождений подстроки на новую строку
    Dynamic_array<T> *replace(Dynamic_array<T> *oldStr, Dynamic_array<T> *newStr)
    {};
    */
    /// вывод массива на экран
    void print()
    {
        for (int i = 0; i < m_size; ++i)
            cout << str[i];
    }
};


