#pragma once

template<class T>
class Sequence
{
public:
    /// получение первого элемента
    virtual T getFirst() const = 0;

    /// получение последнего элемента
    virtual T getLast() const = 0;

    /// получение элемента по индексу
    virtual T get(int index) const = 0;

    /// получение значения
    virtual T operator[](int i) const = 0;

    /// присвоение значения
    virtual T &operator[](int i) = 0;

    /// получить длину строки
    [[nodiscard]] virtual int getLength() const = 0;

    /// вставка элемента в конец
    virtual void append(T &item) = 0;

    /// вставка элемента в начало
    virtual void prepend(T &item) = 0;

    /// вставка элемента по индексу
    virtual void insert(T &item, int index) = 0;

    /// получение substr с begin до end
    virtual Sequence<T> *substr(int begin, int end) const = 0;

    /// Соединение двух строк
    virtual Sequence<T> *concat(Sequence<T> *second_str) = 0;

    /// Вывод строки
    virtual void print() = 0;

    /// поиск первого вхождения подстроки в строке между begin и end, если её нет вернёт end
    virtual int find(Sequence<T> &subStr, int begin, int end) const = 0;

    /// поиск последнего вхождения подстроки в строке между begin и end, если её нет вернёт end
    virtual int rfind(Sequence<T> &subStr, int begin, int end) const = 0;

    /// замена всех вхождений подстроки на новую строку
    virtual Sequence<T> *replace(Sequence<T> &oldStr, Sequence<T> &newStr) const = 0;

    /// Деструктор
    virtual ~Sequence<T>() = default;
};


