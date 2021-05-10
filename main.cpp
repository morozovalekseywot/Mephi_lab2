#include "tests.h"

using namespace std;
#define N 30000
#define loop(i, n) for(int i=0;i<n;++i)

void write(pair<double, double> time, const char *funcname)
{
    ofstream file("Compare.txt", std::ios_base::app);
    file << funcname << "\n";
    file << time.first << " " << time.second << " ";
    if (time.first < time.second)
        file << "\nArray better is " << ceil(time.second / time.first) << " times faster than a Linked_List\n";
    else
        file << "\nLinked_List better is " << ceil(time.first / time.second) << " times faster than a Array\n";
    file.close();
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
    cout<<endl;
    char p='w';
    futur.insert(p,0);
    futur.insert(p,1);
    futur.insert(p,futur.getLength());
    cout<<futur;
    /*
    ofstream file("Compare.txt", ios_base::trunc);
    file << "time array,time Linked_List\n";
    file.close();
    write(test_concat(), "Concat");
    write(test_insert(), "Insert");
    write(test_prepend(), "Prepend");
    write(test_append(), "Append");
    write(test_substr(), "Substr");
    //write(test_find(), "Find");
    //write(test_get(),"Get");
    */
    return 0;
}
