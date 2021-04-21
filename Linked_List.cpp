#include "Linked_List.hpp"

template<class T>
[[maybe_unused]] Linked_List<T>::Linked_List(T *items, int count)
{
    for (int i = 0; i < count; i++)
    {
        append(items[i]);
    }
}

template<class T>
Linked_List<T>::Linked_List() : first(nullptr), last(nullptr)
{}

template<class T>
Linked_List<T>::Linked_List(const Linked_List<T> &list) : first(nullptr), last(nullptr)
{
    for (Node<T> *it = list.first; it != nullptr; it = it->next)
    {
        auto *node = new Node<T>(it->value, last, nullptr);
        if (first == nullptr)
            first = node;
        if (last != nullptr)
            last->next = node;
        last = node;  // Последний элемент
    }
}

template<class T>
Linked_List<T>::~Linked_List()
{
    while (first != nullptr)
    {
        Node<T> *node = first;
        first = first->next;
        delete node;
    }
    last = nullptr;
}

template<class T>
void Linked_List<T>::resize(int size)
{
    if (size < 0)
        throw bad_array_new_length("Linked_List::resize error,new size<0");
    if (size <= getLength())
    {
        int j = getLength();
        while (j != size)
        {
            Node<T> *node = last;
            last = last->prev;
            delete node;
            j--;
        }
        last->next = nullptr;
        return;
    } else
    {
        int old_size = getLength();
        Node<T> *it = last;
        while (size != old_size)
        {
            auto *node = new Node<T>(NULL, last, nullptr);
            last->next = node;
            last = node;
        }
        return;
    }
}

template<class T>
T Linked_List<T>::getFirst() const
{
    if (first == nullptr)
        throw out_of_range("List is empty");
    return first->value;
}

template<class T>
T Linked_List<T>::getLast() const
{
    if (last == nullptr)
        throw out_of_range("List is empty");
    return last->value;
}

template<class T>
T &Linked_List<T>::get(int index) const
{
    if (index < 0 || index >= getLength())
        throw out_of_range("Index out of range");
    // Пробегаем по элементам от первого до последнего и увеличиваем счётчик размера
    int j = 0;
    for (Node<T> *n = first; n != nullptr; n = n->next)
    {
        if (j == index)
            return n->value;
        j++;
    }
}

template<class T>
T Linked_List<T>::operator[](int i) const
{
    return get(i);
}

template<class T>
T &Linked_List<T>::operator[](int i)
{
    return get(i);
}

template<class T>
Linked_List<T> *Linked_List<T>::substr(int begin, int end)
{
    if (begin < 0 or end < 0 or begin > end)
    {
        if (begin > end)
            throw invalid_argument("In function substring begin < end");
        else
            throw out_of_range("In function substring begin or end < 0");
    }

    Node<T> *now = first;
    // Пропускаем все элементы до begin
    for (int i = 0; i < begin && now != nullptr; i++)
        now = now->next;
    auto *subList = new Linked_List<T>();
    for (int i = begin; i <= end; i++)
    {
        subList->append(now->value);
        now = now->next;
    }
    return subList;
}

template<class T>
int Linked_List<T>::getLength() const
{
    int size = 0;
    // Пробегаем по элементам от первого до последнего и увеличиваем счётчик размера
    for (Node<T> *now = first; now != nullptr; now = now->next)
    {
        size++;
    }
    return size;
}

template<class T>
void Linked_List<T>::append(T item)
{
    auto *node = new Node<T>(item, last, nullptr);
    // Начало и конец списка
    if (first == nullptr)
        first = node;
    if (last != nullptr)
        last->next = node;
    last = node;
}

template<class T>
void Linked_List<T>::prepend(T item)
{
    auto *node = new Node<T>(item, nullptr, first);
    // Начало и конец списка
    if (first != nullptr)
        first->prev = node;
    first = node;
    if (last == nullptr)
        last = node;
}

template<class T>
void Linked_List<T>::insert(T item, int index)
{
    if (index < 0 || index >= getLength())
        throw out_of_range("Index out of range");
    // Находим элемент после которого надо вставить
    Node<T> *it = first;
    for (int i = 0; i < index - 1; i++)
        it = it->next;
    // Создаём новый элемент
    auto *node = new Node<T>(item, it, it->next);
    it->next = node;
    if (node->next == nullptr)
    {
        last = node;
    } else
    {
        node->next->prev = node;  // Чтобы следующий элемент ссылался на текущий
    }
}

template<class T>
Linked_List<T> *Linked_List<T>::Concat(Linked_List<T> *list)
{
    auto *res = new Linked_List<T>(*this);
    for (Node<T> *it = list->first; it != nullptr; it = it->next)
    {
        res->append(it->value);
    }
    return res;
}

template<class T>
void Linked_List<T>::removeAt(int index)
{
    Node<T> *toDelete = first;
    for (int i = 0; i < index; i++)
    {
        toDelete = toDelete->next;
    }
    if (toDelete == first)
    {
        first = toDelete->next;
    } else
    {
        toDelete->prev->next = toDelete->next;
    }
    if (toDelete == last)
    {
        last = toDelete->prev;
    } else
    {
        toDelete->next->prev = toDelete->prev;
    }
    delete toDelete;
}

template<class T>
void Linked_List<T>::print()
{
    wcout << L"Linked_List (size = " << getLength() << ")";
    for (Node<T> *n = first; n != nullptr; n = n->next)
    {
        T value = n->value;
        cout << value;
    }
    cout << endl;
}


