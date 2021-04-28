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

    void resize(int size)
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
        return data[i];
    }

    T &operator[](int i) override
    {
        return data[i];
    }

    void set(int index, T &item) override
    {
        data.set(index, item);
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
        auto *res = new Linked_List_Sequence<T>(*this);
        for (int i = 0; i < second_str->getLength(); i++)
        {
            res->append((*second_str)[i]);
        }
        return res;
    }

    int find(Sequence<T> *subStr, int begin, int end) const override
    {
        if (end == -1)
            end = getLength();
        else
            end = min(end, getLength());
        if (subStr->getLength() > end - begin || subStr->getLength() == 0)
            return end;
        Node<T> *it = data.get_first();
        int index;
        for (index = 0; index < begin; index++)
            it = it->next;
        for (index = begin; index < end; index++)
        {
            int j = 0, i = index;
            Node<T> *iter = it;
            while (j < subStr->getLength() && i < end && iter->value == (*subStr)[j])
            {
                iter = iter->next;
                i++;
                j++;
            }
            it = it->next;
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
        Node<T> *it = data.get_last();
        int index;
        for (index = getLength() - 1; index >= end; index++)
            it = it->prev;
        for (index = end - 1; index >= begin; index--)
        {
            Node<T> *iter = it;
            int j = subStr->getLength() - 1, i = index;
            while (j >= 0 && i >= begin && iter->value == (*subStr)[j])
            {
                iter = iter->prev;
                i--;
                j--;
            }
            it = it->prev;
            if (j == -1)
                return i + 1; // индекс на первый элемент строки
        }
        return end;
    }

    Sequence<T> *replace(Sequence<T> *oldStr, Sequence<T> *newStr) override
    {
        if (oldStr->getLength() == 0)
            return this;
        auto *Str = new Linked_List_Sequence<T>(*this);
        Str->resize(getLength() * newStr->getLength() / oldStr->getLength() + getLength());
        int it = 0;
        Node<T> *now = data.get_first();
        for (int index = 0; index < getLength();)
        {
            int i = find(oldStr, index, -1);
            for (int j = index; j < i; j++)
            {
                (*Str)[it++] = now->value;
                now = now->next;
            }
            for (int j = 0; j < newStr->getLength(); j++)
                (*Str)[it++] = (*newStr)[j];
            index += i - index + oldStr->getLength();
            for (int j = 0; j < oldStr->getLength(); j++)
                now = now->next;
        }
        Str->resize(it + 1);
        return Str;
    }

    Sequence<T> *substr(int begin, int end) override
    {
        if (begin < 0 || end < 0 || begin > end)
        {
            if (begin > end)
                throw invalid_argument("In function substring begin < end");
            else
                throw out_of_range("In function substring begin or end < 0");
        }
        if (end > getLength())
            throw out_of_range("In function substring end>size");
        Node<T> *now = data.get_first();
        for (int i = 0; i < begin && now != nullptr; i++)
            now = now->next;
        auto *subList = new Linked_List_Sequence<T>();
        for (int i = begin; i <= end; i++)
        {
            subList->append(now->value);
            now = now->next;
        }
        return subList;
    }

    void print() override
    {
        data.print();
    }

    virtual ~Linked_List_Sequence() = default;
};
