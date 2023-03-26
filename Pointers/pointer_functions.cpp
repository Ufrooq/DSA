#include <iostream>
using namespace std;

void point(int *p)
{
    cout << "Before Update : " << p << endl;
}
void update(int *p)
{
    cout << "After Update : " << p + 1 << endl;
}
int main()
{
    int value = 5;
    int *p = &value;
    point(p);
    update(p);
    point(p);
    return 0;
};