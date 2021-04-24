#pragma once

#include "Dynamic_array.hpp"
#include "Cstring.hpp"

// АТД последовательность на основе динамического массива
template<class T>
class ArraySequence : public Cstring<T>
{
private:
    Dynamic_array<T> data;  // Массив данных
public:
    /// Копирование элементов из переданного массива
    ArraySequence(T *data, int count) : data(data, count)
    {}

    /// Создание пустого массива
    ArraySequence() : data()
    {};

    /// Копирующий конструктор
    explicit ArraySequence(const Dynamic_array<T> &array) : data(array)
    {};

    T getFirst() const override
    {
        return data.getFirst();
    };

    T getLast() const override
    {
        return data.getLast();
    };

    T get(int index) const override
    {
        return data.get(index);
    };

    T operator[](int i) const override
    {
        return data[i];
    }

    T &operator[](int i) override
    {
        return data[i];
    }

    Cstring<T> *substr(int begin, int end) const override
    {
        return data.substr(begin, end);
    }

    [[nodiscard]] int getLength() const override
    {
        return data.size();
    }

    void append(T &item) override
    {
        data.append(item);
    }

    int find(Cstring<T> &subStr, int begin, int end) override
    {
        int i = data.find(subStr, begin, end);
        if (i != end)
            return i;
        else
            return -1;
    }

    int rfind(Cstring<T> &subStr, int begin, int end) override
    {
        int i = data.rfind(subStr, begin, end);
        if (i != end)
            return i;
        else
            return -1;
    }

    Cstring<T> *replace(Cstring<T> &oldStr, Cstring<T> &newStr) override
    {
        return data.replace(oldStr, newStr);
    }

    void prepend(T &item) override
    {
        data.prepend(item);
    }

    void insert(T &item, int index) override
    {
        data.insert(item, index);
    }

    // Сцепляет два списка
    Cstring<T> *concat(Cstring<T> *second_str) override
    {
        return data.concat(second_str);
    }


    // Печать на экран всех элементов
    void print() override
    {
        data.print();
    }

    // == Виртуальный деструктор ==
    virtual ~ArraySequence<T>() = default;
};