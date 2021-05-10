#pragma once

#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdexcept>

using namespace std;


template<class T>
struct Node
{
    T value;
    Node<T> *prev = nullptr;
    Node<T> *next = nullptr;

    Node(T value, Node<T> *prev, Node<T> *next) : value(value), prev(prev), next(next)
    {};
    /*
    ~Node()
    {
        delete prev;
        delete next;
        prev = nullptr;
        next = nullptr;
    }
     */
};

template<class T>
class Linked_List
{
    Node<T> *first = nullptr;  // Первый элемент списка
    Node<T> *last = nullptr;   // Последний элемент списка
    int count=0;

public:
    // Создание объекта
    [[maybe_unused]] Linked_List(T *items, int Count)
    {
        for (int i = 0; i < Count; i++)
        {
            append(items[i]);
        }
    }

    // Создать пустой список
    Linked_List() : first(nullptr), last(nullptr), count(0)
    {};

    // Копирующий конструктор
    Linked_List(const Linked_List<T> &list) : count(list.count)
    {
        for (Node<T> *it = list.first; it != nullptr; it = it->next)
        {
            auto *node = new Node<T>(it->value, last, nullptr);
            if (first == nullptr)
                first = node;
            if (last != nullptr)
                last->next = node;
            last = node;
        }
    }

    /// Деструктор
    ~Linked_List()
    {
        while (first != nullptr)
        {
            Node<T> *node = first;
            first = first->next;
            delete node;
        }
        first = nullptr;
        last = nullptr;
    }

    void resize(int size)
    {
        if (size < 0)
            throw bad_array_new_length();
        if (size <= getLength())
        {
            int j = getLength();
            while (j > size)
            {
                Node<T> *node = last;
                last = last->prev;
                delete node;
                j--;
            }
            last->next = nullptr;
            count = size;
        } else
        {
            int old_size = getLength();
            while (size != old_size)
            {
                auto *node = new Node<T>(NULL, last, nullptr);
                last->next = node;
                last = node;
                old_size++;
            }
            last->next = nullptr;
            count = size;
        }
    }

    Node<T> * get_first() const
    {
        return first;
    }

    Node<T> *get_last() const
    {
        return last;
    }

    T getFirst() const
    {
        if (first == nullptr)
            throw out_of_range("List is empty");
        return first->value;
    }

    T getLast() const
    {
        if (last == nullptr)
            throw out_of_range("List is empty");
        return last->value;
    }

    T &get(int index) const
    {
        if (index < 0 || index >= getLength())
            throw out_of_range("Index out of range in function get");
        int j = 0;
        for (Node<T> *node = first; node != nullptr; node = node->next)
        {
            if (j == index)
                return node->value;
            j++;
        }
    }

    void set(int index, T &item)
    {
        if (index < 0 || index >= getLength())
            throw out_of_range("Index out of range in function set");
        int j = 0;
        for (Node<T> *node = first; node != nullptr; node = node->next)
        {
            if (j == index)
            {
                node->value = item;
                return;
            }
            j++;
        }
    }

    /// получение значения
    T operator[](int i) const
    {
        return get(i);
    }

    /// присвоение значения
    T &operator[](int i)
    {
        return get(i);
    }

    // Получить длину списка
    [[nodiscard]] int getLength() const
    {
        return count;
    }

    // Добавляет элемент в конец списка
    void append(T &item)
    {
        auto *node = new Node<T>(item, last, nullptr);
        if (first == nullptr)
            first = node;
        if (last != nullptr)
            last->next = node;
        last = node;
        count++;
    }

    /// Добавляет элемент в начало списка
    void prepend(T &item)
    {
        auto *node = new Node<T>(item, nullptr, first);
        if (first != nullptr)
            first->prev = node;
        first = node;
        if (last == nullptr)
            last = node;
        count++;
    }


    /// вставка элемента по индексу
    void insert(T &item, int index)
    {
        if (index < 0 || index > getLength())
            throw out_of_range("Index out of range in function insert");
        if(index == 0)
        {
        	prepend(item);
        	return;
        }
        Node<T> *it = first;
        for (int i = 0; i < index - 1; i++)
            it = it->next;
        auto *node = new Node<T>(item, it, it->next);
        it->next = node;
        if (node->next == nullptr)
        {
            last = node;
        } else
        {
            node->next->prev = node;
        }
        count++;
    }
    /*
    /// Соединение двух строк
    Linked_List<T> *concat(Linked_List<T> *list) const;


    /// получение substr с begin до end
    Linked_List<T> *substr(int begin, int end) const;

    /// поиск первого вхождения подстроки в строке между begin и end
    int find(const Linked_List<T> &list, int begin = 0, int end = -1) const;

    /// поиск последнего вхождения подстроки в строке между begin и end
    int rfind(const Linked_List<T> &list, int begin = 0, int end = -1) const;

    /// замена всех вхождений подстроки на новую строку
    Linked_List<T> *replace(Linked_List<T> *a, Linked_List<T> *listB) const;
    */

    // Вывод последовательности на печать (в консоль)
    void print()
    {
        for (Node<T> *node = first; node != nullptr; node = node->next)
        {
            cout << node->value;
        }
    }
};
