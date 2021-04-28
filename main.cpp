#include "Cstring.hpp"

using namespace std;

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
    Cstring <char> futur(fut);
    Cstring<char> rep = *ans.replace(help, futur);
    cout << "replace \"help\" on \"futur\": " << rep;
    return 0;
}
