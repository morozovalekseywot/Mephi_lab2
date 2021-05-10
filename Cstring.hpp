#pragma once

#include "Linked_List_Sequence.hpp"
#include "Array_Sequence.hpp"

using namespace std;

template<class T>
class Cstring
{
    Sequence<T> *symbols;
public:
    explicit Cstring(Sequence<T> *sequence) : symbols(sequence)
    {};

    /// получить длину строки
    [[nodiscard]] int getLength() const
    {
        return symbols->getLength();
    }

    /// получение первого элемента
    T getFirst() const
    {
        return symbols->getFirst();
    }

    /// получение последнего элемента
    T getLast() const
    {
        return symbols->getLast();
    }

    /// получение элемента по индексу
    T get(int index) const
    {
        return symbols->get(index);
    }

    /// получение значения
    T operator[](int i) const
    {
        return (*symbols)[i];
    }

    /// присвоение значения
    T &operator[](int i)
    {
        return (*symbols)[i];
    }

    Cstring<T> &operator=(const Cstring<T> &cstring)
    {
        symbols->resize(cstring.getLength());
        for (int i = 0; i < getLength(); i++)
            (*symbols)[i] = cstring[i];
        return *this;
    }

    /// вставка элемента в конец
    void append(T &item)
    {
        symbols->append(item);
    }

    /// вставка элемента в начало
    void prepend(T &item)
    {
        symbols->prepend(item);
    }

    /// вставка элемента по индексу
    void insert(T &item, int index)
    {
        symbols->insert(item, index);
    }

    /// получение substr с begin до end, end указывает на элемент после последнего
    Cstring<T> *substr(int begin, int end) const
    {
        return new Cstring<T>((symbols->substr(begin, end)));
    }

    /// поиск первого вхождения подстроки в строке между begin и end, если её нет вернёт -1
    int find(Cstring<T> &subStr, int begin = 0, int end = -1) const
    {
        int i = symbols->find(subStr.symbols, begin, end);
        if (i != end)
            return i;
        else
            return -1;
    }

    /// поиск последнего вхождения подстроки в строке между begin и end, если её нет вернёт -1
    int rfind(Cstring<T> &subStr, int begin = 0, int end = -1) const
    {
        int i = symbols->rfind(subStr.symbols, begin, end);
        if (i != end)
            return i;
        else
            return -1;
    }

    /// Соединение двух строк
    Cstring<T> *concat(Cstring<T> &second_str)
    {
        return new Cstring<T>(symbols->concat(second_str.symbols));
    }

    /// замена всех вхождений подстроки на новую строку
    Cstring<T> *replace(Cstring<T> &oldStr, Cstring<T> &newStr) const
    {
        return new Cstring<T>(symbols->replace(oldStr.symbols, newStr.symbols));
    }

    /// печать
    void print()
    {
        symbols->print();
    }

    /// Деструктор
    ~Cstring()
    {
        delete symbols;
        symbols = nullptr;
    }
};

template<class T>
ostream &operator<<(std::ostream &os, const Cstring<T> &a)
{
    for (int i = 0; i < a.getLength(); i++)
        os << a.get(i);
    return os;
}

