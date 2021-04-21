#pragma once

#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdexcept>

using namespace std;

// Элемент двусвязного списка: значение + указатели на предыдущий и следующий
template<class T>
struct Node
{               // struct - всё будет доступно извне, по-умолчанию public
    T value;                  // Значение элемента
    Node<T> *prev = nullptr;  // Указатель на предыдущий элемент
    Node<T> *next = nullptr;  // Указатель на следующий элемент
    Node(T value, Node<T> *prev, Node<T> *next) : value(value), prev(prev), next(next)
    {}

    ~Node()
    {
        delete prev;
        delete next;
        prev = nullptr;
        next = nullptr;
        delete value;
    }
};

template<class T>
class Linked_List
{
    Node<T> *first = nullptr;  // Первый элемент списка
    //Node<T> *med = nullptr;
    Node<T> *last = nullptr;   // Последний элемент списка
    //int count;

public:
    // Создание объекта
    [[maybe_unused]] Linked_List(T *items, int count);

    // Создать пустой список
    Linked_List();

    // Копирующий конструктор
    Linked_List(const Linked_List<T> &list);

    // == Деструктор - очистка памяти ==
    ~Linked_List();

    // == Декомпозиция ==
    // Может выбрасывать исключения: − IndexOutOfRange (если список пуст)
    T getFirst() const;

    // Получить последний элемент в списке
    // Может выбрасывать исключения: − IndexOutOfRange (если список пуст)
    T getLast() const;

    // Получить элемент по индексу
    // Может выбрасывать исключения:
    // − IndexOutOfRange (если индекс отрицательный или больше/равен числу элементов)
    T &get(int index) const;

    // Перегруженные операторы
    T operator[](int i) const;

    T &operator[](int i);

    // Получить список из всех элементов, начиная с begin и заканчивая end.
    // Может выбрасывать исключения:
    // − IndexOutOfRange (если хотя бы один из индексов отрицательный или больше/равен числу элементов)
    Linked_List<T> *substr(int begin, int end);

    // Получить длину списка
    int getLength() const;

    // == Операции ==
    // Добавляет элемент в конец списка
    void append(T item);

    // Добавляет элемент в начало списка
    void prepend(T item);

    // Вставляет элемент в заданную позицию
    void resize(int size);

    // Может выбрасывать исключения:
    // − IndexOutOfRange (если индекс отрицательный или больше/равен числу элементов)
    void insert(T item, int index);

    // Сцепляет два списка
    Linked_List<T> *Concat(Linked_List<T> *list);

    // Удаление элемента по индексу
    void removeAt(int index);

    // Вывод последовательности на печать (в консоль)
    void print();;
};