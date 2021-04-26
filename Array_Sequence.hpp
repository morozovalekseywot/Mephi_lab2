#pragma once

#include "Dynamic_array.hpp"
#include "Sequence.hpp"


template<class T>
class ArraySequence : public Sequence<T>
{
private:
    Dynamic_array<T> data;
public:
    /// Копирование элементов из переданного массива
    ArraySequence(T *data, int count) : data(data, count)
    {}

    /// Создание пустого массива
    ArraySequence() : data()
    {};

    /// Копирующий конструктор
    explicit ArraySequence(Dynamic_array<T> &array) : data(array)
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
        return data.get(i);
    }

    T &operator[](int i) override
    {
        return data.get(i);
    }

    Sequence<T> *substr(int begin, int end) const override
    {
        /*
        auto *sub = new ArraySequence<T>(Dynamic_array<T>(data.substr(begin, end)));
        return sub;
         */
        return new ArraySequence<T>(data.substr(begin, end));
    }

    [[nodiscard]] int getLength() const override
    {
        return data.size();
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


    void print() override
    {
        data.print();
    }

    virtual ~ArraySequence<T>() = default;
};