#pragma once

template<class T>
class Cstring
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
    virtual Cstring<T> *substr(int begin, int end) const = 0;

    /// Соединение двух строк
    virtual Cstring<T> *concat(Cstring<T> *second_str) = 0;

    /// Вывод строки
    virtual void print() = 0;

    /// поиск первого вхождения подстроки в строке между begin и end, если её нет вернёт -1
    virtual int find(Cstring<T> &subStr, int begin = 0, int end = -1) = 0;

    /// поиск последнего вхождения подстроки в строке между begin и end, если её нет вернёт -1
    virtual int rfind(Cstring<T> &subStr, int begin = 0, int end = -1) = 0;

    /// замена всех вхождений подстроки на новую строку
    virtual Cstring<T> *replace(Cstring<T> &oldStr, Cstring<T> &newStr) = 0;

    /// Деструктор
    virtual ~Cstring<T>() = default;
};


