#include <iostream>
using namespace std;
int main()
{
    int x;
    cout << "Enter : " << endl;
    cin >> x;
    string y;
    if (x == 5)
    {
        y = "half";
    }
    else if (x > 5)
    {
        y = "greater";
    }
    else
    {
        y = "less";
    }
    cout << "Y is " << y << endl;
    return 0;
};