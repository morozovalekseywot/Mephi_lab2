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

    int find(Sequence<T> *subStr, int begin, int end) const override
    {
        auto sub =  Dynamic_array<T>(subStr->getLength());
        for (int i = 0; i < subStr->getLength(); i++)
            sub[i] = subStr->get(i);
        return data.find(sub, begin, end);
        /*
        if (i != end)
            return i;
        else
            return -1;
        */
    }

    int rfind(Sequence<T> *subStr, int begin, int end) const override
    {
        auto sub = Dynamic_array<T>(subStr->getLength());
        for (int i = 0; i < subStr->getLength(); i++)
            sub[i] = subStr->get(i);
        return data.rfind(sub, begin, end);
        /*
        if (i != end)
            return i;
        else
            return -1;
        */
    }

    Sequence<T> *replace(Sequence<T> *oldStr, Sequence<T> *newStr) const override
    {
        auto old_str = Dynamic_array<T>(oldStr->getLength());
        for (int i = 0; i < oldStr->getLength(); i++)
            old_str[i] = oldStr->get(i);
        auto new_str = Dynamic_array<T>(newStr->getLength());
        for (int i = 0; i < newStr->getLength(); i++)
            new_str[i] = newStr->get(i);
        return new ArraySequence<T>(data.replace(new Dynamic_array<T>(old_str), new Dynamic_array<T>(new_str)));
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
        auto sec_str = Dynamic_array<T>(second_str->getLength());
        for (int i = 0; i < second_str->getLength(); i++)
            sec_str[i] = second_str->get(i);
        return new ArraySequence<T>(data.concat(sec_str));
    }


    void print() override
    {
        data.print();
    }

    virtual ~ArraySequence<T>() = default;
};