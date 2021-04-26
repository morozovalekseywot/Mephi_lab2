#pragma once

#include "Linked_List.hpp"
#include "Sequence.hpp"

template<class T>
class Linked_List_Sequence : public Sequence<T>
{
    Linked_List<T> data;

public:
    /// Копирование элементов из переданного массива
    Linked_List_Sequence(T *items, int count) : data(items, count)
    {}

    /// Создание пустого связного списка
    Linked_List_Sequence() : data()
    {};

    /// Копирующий конструктор
    explicit Linked_List_Sequence(const Linked_List<T> &list) : data(new Linked_List<T>(list))
    {};

    T getFirst() const override
    {
        return data.getFirst();
    }

    T getLast() const override
    {
        return data.getLast();
    }

    T get(int index) const override
    {
        return data.get(index);
    }

    T operator[](int i) const override
    {
        return data[i];
    }

    T &operator[](int i) override
    {
        return data[i];
    }

    Sequence<T> *substr(int begin, int end) const override
    {
        return data.substr(begin, end);
    }

    [[nodiscard]] int getLength() const override
    {
        return data.getLength();
    }

    void append(T &item) override
    {
        data.append(item);
    }

    void prepend(T &item) override
    {
        data.prepend(item);
    }

    void insert(T &item, int index) override
    {
        data.insert(item, index);
    }

    Sequence<T> *concat(Sequence<T> *second_str) override
    {
        return data.concat(second_str);
    }

    int find(Sequence<T> &subStr, int begin, int end) const override
    {
        return data.find(subStr, begin, end);
        /*
        if (i != end)
            return i;
        else
            return -1;
        */
    }

    int rfind(Sequence<T> &subStr, int begin, int end) const override
    {
        return data.rfind(subStr, begin, end);
        /*
        if (i != end)
            return i;
        else
            return -1;
        */
    }

    Sequence<T> *replace(Sequence<T> &oldStr, Sequence<T> &newStr) const override
    {
        return data.replace(oldStr, newStr);
    }


    void print() override
    {
        data.print();
    }

    virtual ~Linked_List_Sequence() = default;
};
