#include <iostream>
#include <queue>
using namespace std;

class Stack
{
    int size;

public:
    queue<int> q;
    Stack(int size)
    {
        this->size = size;
    }
    void stackPush(int val)
    {

        if (q.empty())
        {
            q.push(val);
        }
        else
        {
            q.push(val);
            for (int i = 0; i < q.size() - 1; i++)
            {
                q.push(q.front());
                q.pop();
            }
        }
    }

    void stackPop()
    {
        if (q.empty())
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            q.pop();
        }
    }
    void display()
    {
        if (q.empty())
        {
            return;
        }
        cout << q.front() << " ";
        q.pop();
        display();
    }
};

int main()
{
    Stack st(5);
    st.stackPush(1);
    st.stackPush(2);
    st.stackPush(3);
    st.stackPush(4);
    st.stackPush(5);
    st.display();
    return 0;
};