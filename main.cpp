#include "Cstring.hpp"
#include <chrono>

using namespace std;
#define N 30000
#define loop(i, n) for(int i=0;i<n;++i)

void test()
{
    char *seq = new char[8];
    seq = "Sequence";
    /*
    char *list_seq = new char[8];
    list_seq = "Sequence";
     */
    //auto *array = new ArraySequence<char>(seq, 14);
    //auto *list = new Linked_List_Sequence<char>(list_seq, 4);
    Cstring<char> array(new ArraySequence<char>(seq, 8));
    Cstring<char> list(new Linked_List_Sequence<char>(seq, 8));
    Cstring<char> subList(new Linked_List_Sequence<char>(seq, 8));
    Cstring<char> subArray(new ArraySequence<char>(seq, 8));
    auto begin_array = std::chrono::steady_clock::now();
    loop(i, 100*N)
    {
        //array = *array.concat(subArray);
        array.concat(subArray);
    }
    cout<<array.getLength()<<"\n";
    auto end_array = std::chrono::steady_clock::now();
    auto elapsed_mcs_array = std::chrono::duration_cast<std::chrono::microseconds>(end_array - begin_array);
    std::cout << "\nArray: --- " << elapsed_mcs_array.count() / 1e6 << " seconds ---\n";
    auto begin_list = std::chrono::steady_clock::now();
    loop(i, 100*N)
    {
        //list = *list.concat(subList);
        list.concat(subList);
    }
    cout<<list.getLength()<<"\n";
    auto end_list = std::chrono::steady_clock::now();
    auto elapsed_mcs_list = std::chrono::duration_cast<std::chrono::microseconds>(end_list - begin_list);
    std::cout << "\nList: --- " << elapsed_mcs_list.count() / 1e6 << " seconds ---\n";
}

int main()
{

    char *my = new char[6];
    my = "helpMe";
    char *Sub = new char[2];
    Sub = "help";
    Linked_List_Sequence<char> *array = new Linked_List_Sequence<char>(my, 6);
    Linked_List_Sequence<char> *sub = new Linked_List_Sequence<char>(Sub, 4);
    Cstring<char> s(array);
    Cstring<char> help(sub);
    cout << s << " " << s.getLength() << "\n" << help << " " << help.getLength();
    cout << "\n";
    Cstring<char> ans = *s.concat(help);
    cout << "concat: " << ans;
    cout << " " << ans.getLength() << " ";
    cout << "\nrfind \"help\": " << ans.rfind(help) << ", find \"help\" " << ans.find(help) << "\n";
    char *tu = new char[5];
    tu = "futur";
    Linked_List_Sequence<char> *fut = new Linked_List_Sequence<char>(tu, 5);
    Cstring<char> futur(fut);
    Cstring<char> rep = *ans.replace(help, futur);
    cout << R"(replace "help" on "futur": )" << rep;
    (*fut)[0] = 'a';
    cout<<"\n"<<futur;
    return 0;
}
