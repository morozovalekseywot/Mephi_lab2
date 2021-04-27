#pragma once

#include "Linked_List_Sequence.hpp"
#include "Array_Sequence.hpp"

template<class T, class basis = ArraySequence<T>>
class Cstring
{
    basis symbols;
public:
    Cstring() : symbols()
    {};

    Cstring(T *items, int count) : symbols(items, count)
    {};

    /// получить длину строки
    [[nodiscard]] int getLen() const
    {
        return symbols.getLen();
    }

    /// получение первого элемента
    T getFirst() const
    {
        return symbols.getFirst();
    }

    /// получение последнего элемента
    T getLast() const
    {
        return symbols.getLast();
    }

    /// получение элемента по индексу
    T get(int index) const
    {
        return symbols.get(index);
    }

    /// получение значения
    T operator[](int i) const
    {
        return symbols[i];
    }

    /// присвоение значения
    T &operator[](int i)
    {
        return symbols[i];
    }

    /// вставка элемента в конец
    void append(T &item)
    {
        symbols.append(item);
    }

    /// вставка элемента в начало
    void prepend(T &item)
    {
        symbols.prepend(item);
    }

    /// вставка элемента по индексу
    void insert(T &item, int index)
    {
        symbols.insert(item, index);
    }

    /// получение substr с begin до end
    Cstring<T, basis> *substr(int begin, int end) const
    {
        return Cstring<T,basis>((symbols.substr(begin, end)).data,(symbols.substr(begin, end))->getLength);
    }

    /// поиск первого вхождения подстроки в строке между begin и end, если её нет вернёт -1
    int find(Cstring<T, basis> &subStr, int begin = 0, int end = -1) const
    {
        int i = symbols.find(subStr, begin, end);
        if (i != end)
            return i;
        else
            return -1;
    }

    /// поиск последнего вхождения подстроки в строке между begin и end, если её нет вернёт -1
    int rfind(Cstring<T, basis> &subStr, int begin = 0, int end = -1) const
    {
        int i = symbols.rfind(subStr, begin, end);
        if (i != end)
            return i;
        else
            return -1;
    }

    /// Соединение двух строк
    Cstring<T, basis> *concat(Cstring<T, basis> *second_str)
    {
        return symbols.concat(second_str);
    }

    /// замена всех вхождений подстроки на новую строку
    Cstring<T, basis> *replace(Cstring<T, basis> &oldStr, Cstring<T, basis> &newStr) const
    {
        return symbols.replace(oldStr, newStr);
    }

    /// печать
    void print()
    {
        symbols.print();
    }
    /*
    /// Деструктор
    ~Cstring()
    {
        delete symbols;
    }
    */
};

