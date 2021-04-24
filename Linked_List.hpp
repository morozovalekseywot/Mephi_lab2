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
    {}

    ~Node()
    {
        delete prev;
        delete next;
        prev = nullptr;
        next = nullptr;
    }
};

template<class T>
class Linked_List
{
    Node<T> *first = nullptr;  // Первый элемент списка
    Node<T> *last = nullptr;   // Последний элемент списка
    int count;

public:
    // Создание объекта
    [[maybe_unused]] Linked_List(T *items, int Count);

    // Создать пустой список
    Linked_List();

    // Копирующий конструктор
    Linked_List(const Linked_List<T> &list);

    /// Деструктор
    ~Linked_List();

    T getFirst() const;

    T getLast() const;

    T get(int index) const;

    /// получение значения
    T operator[](int i) const;

    /// присвоение значения
    T &operator[](int i);


    // Получить длину списка
    [[nodiscard]] int getLength() const;

    // == Операции ==
    // Добавляет элемент в конец списка
    void append(T &item);

    /// Добавляет элемент в начало списка
    void prepend(T &item);

    /// Вставляет элемент в заданную позицию
    void resize(int size);

    /// вставка элемента по индексу
    void insert(T &item, int index);

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

    // Вывод последовательности на печать (в консоль)
    void print();
};