#include <iostream>
using namespace std;

class Stack
{
public:
    int size;
    int *arr;
    int top1;
    int top2;
    Stack(int size)
    {
        this->size = size;
        top1 = -1;
        top2 = (size / 2) - 1;
        arr = new int[size];
    }

    int peek1()
    {
        return arr[top1];
    }
    int peek2()
    {
        return arr[top2];
    }

    void pop1()
    {
        if (top1 == -1)
            cout << "Array is empty !" << endl;
        else
        {
            top1--;
        }
    }
    void pop2()
    {
        if (top2 == (size / 2) + 1)
            cout << "Array is empty !" << endl;
        else
        {
            top2--;
        }
    }

    void push1(int val)
    {
        if (top1 == (size / 2) - 1)
            cout << "Stack is full !" << endl;
        else
        {
            arr[++top1] = val;
        }
    }
    void push2(int val)
    {
        if (top2 == size - 1)
            cout << "Stack is full !" << endl;
        else
        {
            arr[++top2] = val;
        }
    }

    void display1()
    {
        cout << "Stack 1: ";
        for (int i = 0; i <= top1; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void display2()
    {
        cout << "Stack 2: ";
        for (int i = (size / 2) + 1; i <= top2; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack st(6);
    int n;
    while (true)
    {
        cout << "\nPress 1 to push1 element -->" << endl;
        cout << "Press 2 to push2 element -->" << endl;
        cout << "Press 3 to pop1 -->" << endl;
        cout << "Press 4 to pop2 -->" << endl;
        cout << "Press 5 to display1 element -->" << endl;
        cout << "Press 6 to display2 element -->" << endl;
        cout << "Press 0 to exit -->" << endl;
        cout << "Enter : ";
        cin >> n;
        if (n == 1)
        {
            cout << "\nEnter value : ";
            int val;
            cin >> val;
            st.push1(val);
        }
        else if (n == 2)
        {
            cout << "\nEnter value : ";
            int val;
            cin >> val;
            st.push2(val);
        }
        else if (n == 3)
            st.pop1();
        else if (n == 4)
            st.pop2();
        else if (n == 5)
            st.display1();
        else if (n == 6)
            st.display2();
    }
    return 0;
};