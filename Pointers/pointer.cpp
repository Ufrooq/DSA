#include <iostream>
using namespace std;
int main()
{
    int x = 8;
    int *xp = &x;
    cout << x << endl;
    cout << xp << endl;
    cout << *xp << endl;
    cout << &x << endl;
    cout << &xp << endl;
    xp++;
    cout << xp << endl;

    return 0;
};