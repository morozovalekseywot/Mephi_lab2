#include "Dynamic_array.hpp"

template<class T>
void Dynamic_array<T>::resize(int size)
{
    if (size < 0)
        throw bad_array_new_length();//"Dynamic_array::resize error,new size<0"
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
        m_size++;
    } else
        m_size = size;
}

template<class T>
void Dynamic_array<T>::append(T &item)
{
    resize(m_size + 1);
    str[m_size - 1] = item;
}

template<class T>
void Dynamic_array<T>::insert(T &item, int &i)
{
    if (i < 0 || i >= m_size)
        throw out_of_range("Index out of range");
    resize(m_size + 1);
    for (int j = m_size; j > i; j--)
        str[j] = str[j - 1];
    str[i] = item;
}

template<class T>
void Dynamic_array<T>::prepend(T &item)
{
    resize(m_size + 1);
    for (int j = m_size; j > 0; j--)
        str[j] = str[j - 1];
    str[0] = item;
    m_size++;
}

template<class T>
int Dynamic_array<T>::size() const
{
    return m_size;
}

template<class T>
T Dynamic_array<T>::operator[](int i) const
{
    if (i < 0 || i >= m_size)
        throw out_of_range("Index out of range");
    return str[i];
}

template<class T>
T &Dynamic_array<T>::get(int i) const
{
    if (i < 0 || i >= m_size)
        throw out_of_range("Index out of range");
    return str[i];
}

template<class T>
T &Dynamic_array<T>::operator[](int i)
{
    if (i < 0 || i >= m_size)
        throw out_of_range("Index out of range");
    return str[i];
}

template<class T>
bool Dynamic_array<T>::operator==(const T &a)
{
    if (a.size() != m_size)
        return false;
    for (int i = 0; i < m_size; i++)
        if (str[i] != a[i])
            return false;
    return true;
}

/*
template<class T>
Dynamic_array<T> &Dynamic_array<T>::operator=(const Dynamic_array<T> &a)
{
    if (this == a)
        return *this;
    resize(a.m_size);
    for (int i = 0; i < m_size; i++)
        str[i] = a[i];
    return *this;
}
*/
template<class T>
int Dynamic_array<T>::find(const Dynamic_array<T> &a, int begin, int end) const
{
    if (end == -1)
        end = m_size;
    else
        end = min(end, m_size);
    if (a.size() > end - begin || a.size() == 0)
        return end;
    for (int index = begin; index < end; index++)
    {
        int j = 0, i = index;
        while (j < a.size() && i < end && str[i] == a[j])
        {
            i++;
            j++;
        }
        if (j == a.size())
            return index;
    }
    return end;
}

template<class T>
int Dynamic_array<T>::rfind(const Dynamic_array<T> &a, int begin, int end) const
{
    if (end == -1)
        end = m_size;
    else
        end = min(end, m_size);
    if (a.size() > end - begin || a.size() == 0)
        return end;
    for (int index = end - 1; index >= begin; index--)
    {
        int j = a.size(), i = index;
        while (j >= 0 && i >= begin && str[i] == a[j])
        {
            i--;
            j--;
        }
        if (j == -1)
            return i + 1; // индекс на первый элемент строки
    }
    return end;
}

template<class T>
Dynamic_array<T> &Dynamic_array<T>::replace(Dynamic_array<T> *a, Dynamic_array<T> *b) const
{
    if (a == b || a->size() == 0)
        return *this;
    auto *Str = new Dynamic_array<T>(m_size * b->m_size / a->m_size + m_size);
    int it = 0;
    for (int index = 0; index < m_size;)
    {
        int i = find(a, index);
        for (int j = index; j < i; j++)
            Str[it++] = str[j];
        for (int j = 0; j < b->m_size; j++)
            Str[it++] = b[j];
        index += a->size();
    }
    Str->resize(it + 1);
    return Str;
}

template<class T>
void Dynamic_array<T>::print()
{
    for (int i = 0; i < m_size; ++i)
        cout << str[i];
}

template<class T>
T Dynamic_array<T>::getFirst() const
{
    return get(0);
}

template<class T>
T Dynamic_array<T>::getLast() const
{
    return get(m_size - 1);
}

template<class T>
Dynamic_array<T> &Dynamic_array<T>::substr(int begin, int end) const
{
    if (begin < 0 || end < 0 || begin > end)
    {
        if (begin > end)
            throw invalid_argument("In function substring begin < end");
        else
            throw out_of_range("In function substring begin or end < 0");
    }
    if (end > m_size)
        throw out_of_range("In function substring end>size");
    auto *subArray = new Dynamic_array<T>(end - begin);
    for (int i = begin; i < end; i++)
    {
        subArray->str[i - begin] = str[i];
    }
    return subArray;
}

template<class T>
Dynamic_array<T> &Dynamic_array<T>::concat(Dynamic_array<T> *array) const
{
    auto *res = new Dynamic_array<T>(m_size + array->m_size);
    for (int i = 0; i < m_size; i++)
        res->str[i] = str[i];
    for (int i = 0; i < array->size(); i++)
        res->str[i + m_size] = array->str[i];
    return res;
}



