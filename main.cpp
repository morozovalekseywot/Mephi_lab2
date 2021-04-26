#include "Cstring.hpp"

using namespace std;

int main()
{
    char *my = new char[3];
    my[0] = 'y';
    my[1] = 'e';
    my[2] = 's';

    Cstring<char> s(my, 3);

    return 0;
}
