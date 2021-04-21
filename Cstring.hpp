#pragma once
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
template<class T>
class Cstring
{
public:
    virtual Cstring<T> *concat(Cstring<T> *a) const = 0;

    virtual int size() const = 0;

    virtual void resize(int size) = 0;

    virtual void push_back(const T &c) = 0;

    virtual void push_begin(const T &c) = 0;

    virtual void insert(const T &c, int &i) = 0;

    virtual Cstring<T> *substr(int &i, int &k) const = 0;

    /*
    virtual T get(int index) const = 0;

    virtual char Get_first() const = 0;

    virtual char Get_last() const = 0;
    */
    virtual T &operator[](int i) = 0;

    // возвращает индекс первого вхождение строки a в нашей строке, или -1
    virtual int find(T &a) = 0;

    // возвращает индекс последнего вхождения строки a в нашей строке, или -1
    virtual int rfind(T &a) = 0;

    virtual T *replace(T &a, T &b) = 0;

    virtual ~Cstring<T>() = default;
};

/* Реализовать класс строк CString, включая различные операции : конкатенацию, получение подстроки,
  поиск вхождений подстроки, разбиение на строки, замена подстроки на другую строку, и др.
  С помощью наследования и переопределения методов, представить два варианта реализации :
  на основе связанных списков и на основе динамических массивов.
 */