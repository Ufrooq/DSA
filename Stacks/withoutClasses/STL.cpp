#include <iostream>
#include <stack>
using namespace std;
int main()
{

    stack<int> s;
    for (int i = 6; i <= 10; i++)
        s.push(i);
    cout << s.size() << endl;
    cout << "Before POP " << s.top() << endl;
    s.pop();
    s.pop();
    s.pop();
    cout << "After POP " << s.top() << endl;
    cout << s.size() << endl;
    return 0;
};