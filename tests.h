#pragma once

#include "Cstring.hpp"
#include <chrono>
#include <utility>
#include <fstream>
#include <cassert>
#include <ctime>

using namespace std;
#define N 30000
#define loop(i, n) for(int i=0;i<n;++i)
#define assert_eq(l, r) assert(l==r)

char *build(int n = N)
{
    //srand(time(NULL));
    char *str = new char[n];
    loop(i, n)
    {
        str[i] = 'a' + rand() % 26;
    }
    return str;
}

pair<double, double> test_concat()
{
    char *seq = build(N / 10);
    Cstring<char> array(new ArraySequence<char>(seq, N / 10));
    Cstring<char> list(new Linked_List_Sequence<char>(seq, N / 10));
    Cstring<char> subList(new Linked_List_Sequence<char>(seq, N / 10));
    Cstring<char> subArray(new ArraySequence<char>(seq, N / 10));
    auto begin_array = chrono::steady_clock::now();
    loop(i, N / 1000)
    {
        //array = *array.concat(subArray);
        array.concat(subArray);
    }
    //cout << array.getLength() << "\n";
    auto end_array = chrono::steady_clock::now();
    auto elapsed_mcs_array = chrono::duration_cast<chrono::microseconds>(end_array - begin_array);
    //cout << "\nArray: --- " << elapsed_mcs_array.count() / 1e3 << " miliseconds ---\n";
    auto begin_list = chrono::steady_clock::now();
    loop(i, N / 1000)
    {
        //list = *list.concat(subList);
        list.concat(subList);
    }
    //cout << list.getLength() << "\n";
    auto end_list = chrono::steady_clock::now();
    auto elapsed_mcs_list = chrono::duration_cast<chrono::microseconds>(end_list - begin_list);
    Cstring<char> subAr = *array.concat(subArray);
    Cstring<char> subLs = *list.concat(subList);
    for (int i = 0; i < subAr.getLength() / 2; i++)
        assert(subAr[i] == array[i]);
    for (int i = subAr.getLength() / 2; i < subAr.getLength(); i++)
        assert(subAr[i] == subArray[i - subAr.getLength() / 2]);
    for (int i = 0; i < subLs.getLength() / 2; i++)
        assert(subLs[i] == list[i]);
    for (int i = subLs.getLength() / 2; i < subLs.getLength(); i++)
        assert(subLs[i] == subLs[i - subLs.getLength() / 2]);
    assert_eq(array.getLength(), list.getLength());
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
    auto elapsed_mcs_array = chrono::duration_cast<chrono::microseconds>(end_array - begin_array);
    auto begin_list = chrono::steady_clock::now();
    loop(i, N / 10)
    {
        list.insert(p, list.getLength() / 2);
    }
    auto end_list = chrono::steady_clock::now();
    auto elapsed_mcs_list = chrono::duration_cast<chrono::microseconds>(end_list - begin_list);
    for (int i = 4; i < array.getLength() - 4; i++)
        assert(array[i] == p);
    for (int i = 8; i < list.getLength() - 4; i++)
        assert(list[i] == p);
    assert_eq(array.getLength(), list.getLength());
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
    loop(i, N / 2)
    {
        array.prepend(p);
    }
    auto end_array = chrono::steady_clock::now();
    auto elapsed_mcs_array = chrono::duration_cast<chrono::microseconds>(end_array - begin_array);
    auto begin_list = chrono::steady_clock::now();
    loop(i, N / 2)
    {
        list.prepend(p);
    }
    auto end_list = chrono::steady_clock::now();
    auto elapsed_mcs_list = chrono::duration_cast<chrono::microseconds>(end_list - begin_list);
    for (int i = 0; i < array.getLength() - 8; i++)
        assert(array[i] == p);
    for (int i = 8; i < list.getLength() - 8; i++)
        assert(list[i] == p);
    assert_eq(array.getLength(), list.getLength());
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
    auto elapsed_mcs_array = chrono::duration_cast<chrono::microseconds>(end_array - begin_array);
    auto begin_list = chrono::steady_clock::now();
    loop(i, N / 10)
    {
        list.append(p);
    }
    auto end_list = chrono::steady_clock::now();
    auto elapsed_mcs_list = chrono::duration_cast<chrono::microseconds>(end_list - begin_list);
    for (int i = 8; i < array.getLength(); i++)
        assert(array[i] == p);
    for (int i = 8; i < list.getLength(); i++)
        assert(list[i] == p);
    assert_eq(array.getLength(), list.getLength());
    return {elapsed_mcs_array.count(), elapsed_mcs_list.count()};
}

pair<double, double> test_substr()
{
    char *seq = build(N / 2);
    Cstring<char> array(new ArraySequence<char>(seq, N / 2));
    Cstring<char> list(new Linked_List_Sequence<char>(seq, N / 2));
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
    //cout << "\n" << list.getLength() << "\n" << list;
    auto elapsed_mcs_list = chrono::duration_cast<chrono::microseconds>(end_list - begin_list);
    Cstring<char> subArray = *array.substr(N / 8, 3 * N / 8);
    Cstring<char> subList = *list.substr(N / 8, 3 * N / 8);
    for (int i = 0; i < subArray.getLength(); i++)
        assert(subArray[i] == array[i + N / 8]);
    for (int i = 0; i < subList.getLength(); i++)
        assert(subList[i] == list[i + N / 8]);
    //cout << "\nList: --- " << elapsed_mcs_list.count() / 1e3 << " miliseconds ---\n";
    assert_eq(array.getLength(), list.getLength());
    return {elapsed_mcs_array.count(), elapsed_mcs_list.count()};
}

pair<double, double> test_find()
{
    char *seq = build(N / 2);
    //char *sub = build(N / 10);
    Cstring<char> array(new ArraySequence<char>(seq, N / 2));
    Cstring<char> list(new Linked_List_Sequence<char>(seq, N / 2));
    Cstring<char> subArray = *array.substr(N / 8, 3 * N / 8);
    Cstring<char> subList = *list.substr(N / 8, 3 * N / 8);
    assert(subArray.getLength() == subList.getLength());
    auto begin_array = chrono::steady_clock::now();
    loop(i, N / 1000)
    {
        array.find(subArray);
    }
    auto end_array = chrono::steady_clock::now();
    auto elapsed_mcs_array = chrono::duration_cast<chrono::microseconds>(end_array - begin_array);
    auto begin_list = chrono::steady_clock::now();
    loop(i, N / 1000)
    {
        list.find(subList);
    }
    auto end_list = chrono::steady_clock::now();
    auto elapsed_mcs_list = chrono::duration_cast<chrono::microseconds>(end_list - begin_list);
    int ar = array.find(subArray);
    int ls = list.find(subList);
    for (int i = 0; i < subArray.getLength(); i++)
        assert(subArray[i] == array[i + ar]);
    for (int i = 0; i < subList.getLength(); i++)
        assert(subList[i] == list[i + ls]);
    assert_eq(array.getLength(), list.getLength());
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
    loop(i, N / 10)
    {
        list[i];
    }
    auto end_list = chrono::steady_clock::now();
    //cout << "\n" << list.getLength() << "\n" << list;
    auto elapsed_mcs_list = 10 * chrono::duration_cast<chrono::microseconds>(end_list - begin_list);
    //cout << "\nList: --- " << elapsed_mcs_list.count() / 1e3 << " miliseconds ---\n";
    assert_eq(array.getLength(), list.getLength());
    return {elapsed_mcs_array.count(), elapsed_mcs_list.count()};
}

pair<double, double> test_replace()
{
    int n = 1000;
    char *seq = new char[n];
    for (int i = 0; i < n; i++)
    {
        seq[i++] = 'h';
        seq[i++] = 'e';
        seq[i++] = 'l';
        seq[i] = 'p';
    }
    Cstring<char> array(new ArraySequence<char>(seq, n));
    Cstring<char> list(new Linked_List_Sequence<char>(seq, n));
    char *Sub = new char[2];
    Sub = "help";
    Cstring<char> help1(new ArraySequence<char>(Sub, 4));
    Cstring<char> help2(new Linked_List_Sequence<char>(Sub, 4));
    char *hell = new char[4];
    hell = "hell";
    Cstring<char> hell1(new ArraySequence<char>(hell, 4));
    Cstring<char> hell2(new Linked_List_Sequence<char>(hell, 4));
    auto begin_array = chrono::steady_clock::now();
    Cstring<char> resAr = *array.replace(help1, hell1);
    auto end_array = chrono::steady_clock::now();
    auto elapsed_mcs_array = chrono::duration_cast<chrono::microseconds>(end_array - begin_array);
    auto begin_list = chrono::steady_clock::now();
    Cstring<char> resLs = *list.replace(help2, hell2);
    auto end_list = chrono::steady_clock::now();
    auto elapsed_mcs_list = chrono::duration_cast<chrono::microseconds>(end_list - begin_list);
    //cout<<resAr<<"\n"<<resLs<<"\n";
    assert(resAr.find(help1) == -1);
    assert(resLs.find(help2) == -1);
    assert_eq(array.getLength(), list.getLength());
    assert(resAr.getLength() == array.getLength());
    assert(resLs.getLength() == list.getLength());
    return {elapsed_mcs_array.count(), elapsed_mcs_list.count()};
}