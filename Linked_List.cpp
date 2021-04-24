#include "Linked_List.hpp"

template<class T>
[[maybe_unused]] Linked_List<T>::Linked_List(T *items, int Count):count(Count)
{
    for (int i = 0; i < Count; i++)
    {
        append(items[i]);
    }
}

template<class T>
Linked_List<T>::Linked_List() : first(nullptr), last(nullptr), count(0)
{}

template<class T>
Linked_List<T>::Linked_List(const Linked_List<T> &list) : first(nullptr), last(nullptr), count(list.count)
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

template<class T>
Linked_List<T>::~Linked_List()
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

template<class T>
void Linked_List<T>::resize(int size)
{
    if (size < 0)
        throw bad_array_new_length();
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
        count = size;
        return;
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
T Linked_List<T>::get(int index) const
{
    if (index < 0 || index >= getLength())
        throw out_of_range("Index out of range");
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
Linked_List<T> *Linked_List<T>::substr(int begin, int end) const
{
    if (begin < 0 || end < 0 || begin > end)
    {
        if (begin > end)
            throw invalid_argument("In function substring begin < end");
        else
            throw out_of_range("In function substring begin or end < 0");
    }
    if (end > count)
        throw out_of_range("In function substring end>size");
    Node<T> *now = first;
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
    return count;
}

template<class T>
void Linked_List<T>::append(T &item)
{
    auto *node = new Node<T>(item, last, nullptr);
    if (first == nullptr)
        first = node;
    if (last != nullptr)
        last->next = node;
    last = node;
    count++;
}

template<class T>
void Linked_List<T>::prepend(T &item)
{
    auto *node = new Node<T>(item, nullptr, first);
    if (first != nullptr)
        first->prev = node;
    first = node;
    if (last == nullptr)
        last = node;
    count++;
}

template<class T>
void Linked_List<T>::insert(T &item, int index)
{
    if (index < 0 || index >= getLength())
        throw out_of_range("Index out of range");
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

template<class T>
Linked_List<T> *Linked_List<T>::concat(Linked_List<T> *list) const
{
    auto *res = new Linked_List<T>(*this);
    for (Node<T> *it = list->first; it != nullptr; it = it->next)
    {
        res->append(it->value);
    }
    return res;
}

template<class T>
void Linked_List<T>::print()
{
    for (Node<T> *node = first; node != nullptr; node = node->next)
    {
        cout << node->value;
    }
}

template<class T>
int Linked_List<T>::find(const Linked_List<T> &list, int begin, int end) const
{
    if (end == -1)
        end = count;
    else
        end = min(end, count);
    if (list.getLength() > end - begin || list.getLength() == 0)
        return end;
    Node<T> *it;
    int index;
    for (index = 0; index < begin; index++)
        it = it->next;
    for (index = begin; index < end; index++)
    {
        int j = 0, i = index;
        Node<T> *iter = Node<T>(it->value, it->prev, it->next);
        while (j < list.getLength() && i < end && iter->value == list[j])
        {
            iter = iter->next;
            i++;
            j++;
        }
        it = it->next;
        if (j == list.getLength())
            return index;
    }
    return end;
}

template<class T>
int Linked_List<T>::rfind(const Linked_List<T> &list, int begin, int end) const
{
    if (end == -1)
        end = count;
    else
        end = min(end, count);
    if (list.getLength() > end - begin || list.getLength() == 0)
        return end;
    Node<T> *it;
    int index;
    for (index = count - 1; index >= end; index++)
        it = it->prev;
    for (index = end - 1; index >= begin; index--)
    {
        Node<T> *iter = Node<T>(it->value, it->prev, it->next);
        int j = list.getLength(), i = index;
        while (j >= 0 && i >= begin && iter->value == list[j])
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

template<class T>
Linked_List<T> *Linked_List<T>::replace(Linked_List<T> *listA, Linked_List<T> *listB) const
{
    if (listA->getLength() == 0)
        return *this;
    auto *Str = new Linked_List<T>(*this);
    Str->resize(count * listB->m_size / listA->m_size + count);
    int it = 0;
    Node<T> *now = first;
    for (int index = 0; index < count;)
    {
        int i = find(listA, index);
        for (int j = index; j < i; j++)
        {
            Str[it++] = now->value;
            now = now->next;
        }
        for (int j = 0; j < listB->count; j++)
        {
            Str[it++] = listB[j];
        }
        index += listA->count;
    }
    Str->resize(it + 1);
    return Str;
}


