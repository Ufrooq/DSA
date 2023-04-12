#include <iostream>
#include <queue>
using namespace std;
int main()
{
    queue<int> qu;
    qu.push(1);
    qu.push(2);
    qu.push(3);
    qu.push(4);
    qu.push(5);
    cout << "Size of queue is : " << qu.size() << endl;
    cout << "Front of queue is : " << qu.front() << endl;
    qu.pop();
    qu.pop();
    cout << "Size of queue is : " << qu.size() << endl;
    cout << "Front of queue is : " << qu.front() << endl;
    return 0;
};