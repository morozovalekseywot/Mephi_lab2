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
    ArraySequence(T *items, int count) : data(items, count)
    {}

    /// Создание пустого массива
    ArraySequence() : data()
    {};

    explicit ArraySequence(int size) : data(size)
    {};

    /// Копирующий конструктор
    explicit ArraySequence(const Dynamic_array<T> &array) : data(array)
    {};

    void resize(int size) override
    {
        data.resize(size);
    }

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
    /*
    Sequence<T> &operator=(const Sequence<T> *sequence) override
    {
        resize(sequence->getLength());
        for (int i = 0; i < getLength(); i++)
            data[i] = (*sequence)[i];
        return *this;
    }
    */
    Sequence<T> *substr(int begin, int end) const override
    {
        if (begin < 0 || end < 0 || begin > end)
        {
            if (begin > end)
                throw invalid_argument("In function substring begin < end");
            else
                throw out_of_range("In function substring begin or end < 0");
        }
        if (end > data.size())
            throw out_of_range("In function substring end>size");
        auto *subArray = new ArraySequence<T>(end - begin);
        for (int i = begin; i < end; i++)
        {
            (*subArray)[i - begin] = data[i];
        }
        return subArray;
        //return new ArraySequence<T>(data.substr(begin, end));
    }

    [[nodiscard]] int getLength() const override
    {
        return data.size();
    }

    int find(Sequence<T> *subStr, int begin, int end) const override
    {
        if (end == -1)
            end = data.size();
        else
            end = min(end, data.size());
        if (subStr->getLength() > end - begin || subStr->getLength() == 0)
            return end;
        for (int index = begin; index < end; index++)
        {
            int j = 0, i = index;
            while (j < subStr->getLength() && i < end && data[i] == (*subStr)[j])
            {
                i++;
                j++;
            }
            if (j == subStr->getLength())
                return index;
        }
        return end;
    }

    int rfind(Sequence<T> *subStr, int begin, int end) const override
    {
        if (end == -1)
            end = getLength();
        else
            end = min(end, getLength());
        if (subStr->getLength() > end - begin || subStr->getLength() == 0)
            return end;
        for (int index = end - 1; index >= begin; index--)
        {
            int j = subStr->getLength() - 1, i = index;
            while (j >= 0 && i >= begin && data[i] == (*subStr)[j])
            {
                i--;
                j--;
            }
            if (j == -1)
                return i + 1; // индекс на первый элемент строки
        }
        return end;
    }

    void set(int index, T &item) override
    {
        data.set(index, item);
    }

    Sequence<T> *replace(Sequence<T> *oldStr, Sequence<T> *newStr) const override
    {
        if (oldStr == newStr || oldStr->getLength() == 0)
            return new ArraySequence<T>(*this);
        auto *Str = new ArraySequence<T>(data.size() * newStr->getLength() / oldStr->getLength() + data.size());
        int it = 0;
        for (int index = 0; index < data.size();)
        {
            int i = find(oldStr, index, -1);
            for (int j = index; j < i; j++)
                (*Str)[it++] = data[j];
            for (int j = 0; j < newStr->getLength(); j++)
                (*Str)[it++] = (*newStr)[j];
            index += i - index + oldStr->getLength();
        }
        Str->resize(it + 1);
        return Str;
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

    Sequence<T> *concat(Sequence<T> *second_str) const override
    {
        auto *res = new ArraySequence<T>(this->data);

        res->data.resize(getLength() + second_str->getLength());
        for (int i = 0; i < second_str->getLength(); i++)
        {
            (*res)[getLength() + i] = second_str->get(i);
        }
        return res;
    }


    void print() override
    {
        data.print();
    }

    virtual ~ArraySequence<T>() = default;
};