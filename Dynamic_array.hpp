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

    Dynamic_array(T *data, int count) : m_size(count)
    {
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
        for (int i = 0; i < size; ++i)
        {
            str[i] = NULL;
        }
        if (size != 0)
            str = new T[size];
        else
            str = 0;
    }

    /// Деструктор
    ~Dynamic_array<T>()
    {
        delete[] str;
        str = nullptr;
    }
    /// получение размера
    [[nodiscard]] int size() const;
    /*
    при уменьшении размера массива, элементы остаются и можно попробовать
    обратиться к ним, так же сделано и в реализации stl <Vector>
   */
    void resize(int size);

    /// вставка элемента в конец
    void append(T &item);

    /// вставка элемента в начало
    void prepend(T &item);

    /// вставка элемента по индексу
    void insert(T &item, int &i);

    T getFirst() const;

    T getLast() const;

    T &get(int i) const;

    /// получение значения
    T operator[](int i) const;

    /// присвоение значения
    T &operator[](int i);

    bool operator==(const T &a);

    //Dynamic_array<T> &operator=(const Dynamic_array<T> &a);

    /// получение substr с begin до end
    Dynamic_array<T> &substr(int begin, int end) const;

    /// Соединение двух строк
    Dynamic_array<T> &concat(Dynamic_array<T> *array) const;

    /// поиск первого вхождения подстроки в строке между begin и end
    int find(const Dynamic_array<T> &a, int begin = 0, int end = -1) const;

    /// поиск последнего вхождения подстроки в строке между begin и end
    int rfind(const Dynamic_array<T> &a, int begin = 0, int end = -1) const;

    /// замена всех вхождений подстроки на новую строку
    Dynamic_array<T> &replace(Dynamic_array<T> *a, Dynamic_array<T> *b) const;

    /// вывод массива на экран
    void print();
};


