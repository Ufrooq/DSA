#include <iostream>
using namespace std;

class Stack

{
public:
    int *arr;
    int top;
    int size;
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push()
    {
        if (size - top > 1)
        {
            cout << "Enter element : ";
            int element;
            cin >> element;
            arr[++top] = element;
        }
        else
            cout << "Stack is already full YOU stupid :)" << endl;
    }
    void pop()
    {
        if (top == -1)
            cout << "No elements are present for now :|||" << endl;
        else
            top--;
    }
    void peek()
    {
        if (top == -1)
            cout << "No elements are present :|||";
        else
            cout << "\nTop element is : " << arr[top] << endl;
    }
};

int main()
{
    Stack st(5);
    int n;
    while (true)
    {
        cout << "\nPress 1 to push element -->" << endl;
        cout << "Press 2 to pop element -->" << endl;
        cout << "Press 3 to display element -->" << endl;
        cout << "Press 0 to exit -->" << endl;
        cout << "Enter : ";
        cin >> n;
        if (n == 1)
            st.push();
        else if (n == 2)
            st.pop();
        else if (n == 3)
            st.peek();
        else if (n == 0)
            break;
    }

    return 0;
};