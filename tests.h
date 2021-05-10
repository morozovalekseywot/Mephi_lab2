#pragma once
#include "Cstring.hpp"
#include <chrono>
#include <utility>
#include <fstream>
#include <cassert>

using namespace std;
#define N 500
#define loop(i, n) for(int i=0;i<n;++i)
#define assert_eq(l, r) assert(l==r)

char *build(int n = N)
{
    char *str = new char[n];
    loop(i, n)
    {
        str[i] = 'a' + rand() % 26;
    }
    return str;
}

pair<double, double> test_concat()
{
    char *seq = new char[8];
    seq = "Sequence";
    Cstring<char> array(new ArraySequence<char>(seq, 8));
    Cstring<char> list(new Linked_List_Sequence<char>(seq, 8));
    Cstring<char> subList(new Linked_List_Sequence<char>(seq, 8));
    Cstring<char> subArray(new ArraySequence<char>(seq, 8));
    auto begin_array = chrono::steady_clock::now();
    loop(i, N/10)
    {
        //array = *array.concat(subArray);
        array.concat(subArray);
    }
    //cout << array.getLength() << "\n";
    auto end_array = chrono::steady_clock::now();
    auto elapsed_mcs_array = chrono::duration_cast<chrono::microseconds>(end_array - begin_array);
    //cout << "\nArray: --- " << elapsed_mcs_array.count() / 1e3 << " miliseconds ---\n";
    auto begin_list = chrono::steady_clock::now();
    loop(i, N/10)
    {
        //list = *list.concat(subList);
        list.concat(subList);
    }
    //cout << list.getLength() << "\n";
    auto end_list = chrono::steady_clock::now();
    auto elapsed_mcs_list = chrono::duration_cast<chrono::microseconds>(end_list - begin_list);
    //cout << "\nList: --- " << elapsed_mcs_list.count() / 1e3 << " miliseconds ---\n";
     //cout<<array.getLength()<<" "<<list.getLength()<<"\n";
    assert_eq(array.getLength(),list.getLength());
    return {elapsed_mcs_array.count(), elapsed_mcs_list.count()};
}

pair<double, double> test_insert()
{
    char *seq = new char[8];
    seq = "Sequence";
    Cstring<char> array(new ArraySequence<char>(seq, 8));
    Cstring<char> list(new Linked_List_Sequence<char>(seq, 8));
    auto begin_array = chrono::steady_clock::now();
    char p = 'I';
    loop(i, N / 10)
    {
        array.insert(p, array.getLength() / 2);
    }
    auto end_array = chrono::steady_clock::now();
    //cout << "\n" << array.getLength() << "\n" << array;
    auto elapsed_mcs_array = chrono::duration_cast<chrono::microseconds>(end_array - begin_array);
    //cout << "\nArray: --- " << elapsed_mcs_array.count() / 1e3 << " miliseconds ---\n";
    auto begin_list = chrono::steady_clock::now();
    loop(i, N / 10)
    {
        list.insert(p, list.getLength() / 2);
    }
    auto end_list = chrono::steady_clock::now();
    //cout << "\n" << list.getLength() << "\n" << list;
    auto elapsed_mcs_list = chrono::duration_cast<chrono::microseconds>(end_list - begin_list);
    //cout << "\nList: --- " << elapsed_mcs_list.count() / 1e3 << " miliseconds ---\n";
     //cout<<array.getLength()<<" "<<list.getLength()<<"\n";
    assert_eq(array.getLength(),list.getLength());
    return {elapsed_mcs_array.count(), elapsed_mcs_list.count()};
}

pair<double, double> test_prepend()
{
    char *seq = new char[8];
    seq = "Sequence";
    Cstring<char> array(new ArraySequence<char>(seq, 8));
    Cstring<char> list(new Linked_List_Sequence<char>(seq, 8));
    auto begin_array = chrono::steady_clock::now();
    char p = 'I';
    loop(i, N / 100)
    {
        array.prepend(p);
    }
    auto end_array = chrono::steady_clock::now();
    //cout << "\n" << array.getLength() << "\n" << array;
    auto elapsed_mcs_array = chrono::duration_cast<chrono::microseconds>(end_array - begin_array);
    //cout << "\nArray: --- " << elapsed_mcs_array.count() / 1e3 << " miliseconds ---\n";
    auto begin_list = chrono::steady_clock::now();
    loop(i, N / 100)
    {
        list.prepend(p);
    }
    auto end_list = chrono::steady_clock::now();
    //cout << "\n" << list.getLength() << "\n" << list;
    auto elapsed_mcs_list = chrono::duration_cast<chrono::microseconds>(end_list - begin_list);
    //cout << "\nList: --- " << elapsed_mcs_list.count() / 1e3 << " miliseconds ---\n";
    //cout<<array.getLength()<<" "<<list.getLength()<<"\n";
    assert_eq(array.getLength(),list.getLength());
    return {elapsed_mcs_array.count(), elapsed_mcs_list.count()};
}

pair<double, double> test_append()
{
    char *seq = new char[8];
    seq = "Sequence";
    Cstring<char> array(new ArraySequence<char>(seq, 8));
    Cstring<char> list(new Linked_List_Sequence<char>(seq, 8));
    auto begin_array = chrono::steady_clock::now();
    char p = 'I';
    loop(i, N / 10)
    {
        array.append(p);
    }
    auto end_array = chrono::steady_clock::now();
    //cout << "\n" << array.getLength() << "\n" << array;
    auto elapsed_mcs_array = chrono::duration_cast<chrono::microseconds>(end_array - begin_array);
    //cout << "\nArray: --- " << elapsed_mcs_array.count() / 1e3 << " miliseconds ---\n";
    auto begin_list = chrono::steady_clock::now();
    loop(i, N / 10)
    {
        list.append(p);
    }
    auto end_list = chrono::steady_clock::now();
    //cout << "\n" << list.getLength() << "\n" << list;
    auto elapsed_mcs_list = chrono::duration_cast<chrono::microseconds>(end_list - begin_list);
    //cout << "\nList: --- " << elapsed_mcs_list.count() / 1e3 << " miliseconds ---\n";
    assert_eq(array.getLength(),list.getLength());
    return {elapsed_mcs_array.count(), elapsed_mcs_list.count()};
}

pair<double, double> test_substr()
{
    char *seq = build(N/2);
    Cstring<char> array(new ArraySequence<char>(seq, N/2));
    Cstring<char> list(new Linked_List_Sequence<char>(seq, N/2));
    auto begin_array = chrono::steady_clock::now();
    loop(i, N / 100)
    {
        array.substr(N / 8, 3 * N / 8);
    }
    auto end_array = chrono::steady_clock::now();
    //cout << "\n" << array.getLength() << "\n" << array;
    auto elapsed_mcs_array = chrono::duration_cast<chrono::microseconds>(end_array - begin_array);
    //cout << "\nArray: --- " << elapsed_mcs_array.count() / 1e3 << " miliseconds ---\n";
    auto begin_list = chrono::steady_clock::now();
    loop(i, N / 100)
    {
        list.substr(N / 8, 3 * N / 8);
    }
    auto end_list = chrono::steady_clock::now();
    cout << "\n" << list.getLength() << "\n" << list;
    auto elapsed_mcs_list = chrono::duration_cast<chrono::microseconds>(end_list - begin_list);
    //cout << "\nList: --- " << elapsed_mcs_list.count() / 1e3 << " miliseconds ---\n";
    assert_eq(array.getLength(),list.getLength());
    return {elapsed_mcs_array.count(), elapsed_mcs_list.count()};
}

pair<double, double> test_find()
{
    char *seq = build();
    char *sub = build(N / 10);
    Cstring<char> array(new ArraySequence<char>(seq, N));
    Cstring<char> list(new Linked_List_Sequence<char>(seq, N));
    Cstring<char> subList(new Linked_List_Sequence<char>(sub, N/10));
    Cstring<char> subArray(new ArraySequence<char>(sub, N/10));
    auto begin_array = chrono::steady_clock::now();
    loop(i, N / 100)
    {
        array.find(subArray);
    }
    auto end_array = chrono::steady_clock::now();
    //cout << "\n" << array.getLength() << "\n" << array;
    auto elapsed_mcs_array = chrono::duration_cast<chrono::microseconds>(end_array - begin_array);
    //cout << "\nArray: --- " << elapsed_mcs_array.count() / 1e3 << " miliseconds ---\n";
    auto begin_list = chrono::steady_clock::now();
    loop(i, N / 100)
    {
        list.find(subList);
    }
    auto end_list = chrono::steady_clock::now();
    //cout << "\n" << list.getLength() << "\n" << list;
    auto elapsed_mcs_list = chrono::duration_cast<chrono::microseconds>(end_list - begin_list);
    //cout << "\nList: --- " << elapsed_mcs_list.count() / 1e3 << " miliseconds ---\n";
    assert_eq(array.getLength(),list.getLength());
    return {elapsed_mcs_array.count(), elapsed_mcs_list.count()};
}

pair<double, double> test_get()
{
    char *seq = build();
    Cstring<char> array(new ArraySequence<char>(seq, N));
    Cstring<char> list(new Linked_List_Sequence<char>(seq, N));
    auto begin_array = chrono::steady_clock::now();
    loop(i, N)
    {
        array[i];
    }
    auto end_array = chrono::steady_clock::now();
    //cout << "\n" << array.getLength() << "\n" << array;
    auto elapsed_mcs_array = chrono::duration_cast<chrono::microseconds>(end_array - begin_array);
    //cout << "\nArray: --- " << elapsed_mcs_array.count() / 1e3 << " miliseconds ---\n";
    auto begin_list = chrono::steady_clock::now();
    loop(i, N/10)
    {
        list[i];
    }
    auto end_list = chrono::steady_clock::now();
    //cout << "\n" << list.getLength() << "\n" << list;
    auto elapsed_mcs_list = 10*chrono::duration_cast<chrono::microseconds>(end_list - begin_list);
    //cout << "\nList: --- " << elapsed_mcs_list.count() / 1e3 << " miliseconds ---\n";
    assert_eq(array.getLength(),list.getLength());
    return {elapsed_mcs_array.count(), elapsed_mcs_list.count()};
}
