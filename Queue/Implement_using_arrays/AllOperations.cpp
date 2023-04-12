#include <iostream>
using namespace std;

class Stack
{
    int size;
    int *arr;
    int front = -1;
    int rear = -1;

public:
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
    }

    bool isFull()
    {
        return (rear == size - 1) ? true : false;
    }
    bool isEmpty()
    {
        return (front == -1 && rear == -1) ? true : false;
    }

    void pop()
    {
        if (isEmpty())
            cout << "Queue is Empty -->";
        else
        {
            for (int i = 1; i <= rear; i++)
            {
                arr[i - 1] = arr[i];
            }
            rear--;
        }
        if (rear == -1)
            front = rear = -1;
    }
    void push(int elem)
    {
        if (isFull())
            cout << "Queue is Already Full --->" << endl;
        else
        {
            if (isEmpty())
            {
                front = rear = 0;
                arr[rear] = elem;
            }
            else
                arr[++rear] = elem;
        }
    }

    void display()
    {

        if (isEmpty())
            cout << "Stack is empty ---->" << endl;
        else
        {
            for (int i = front; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
        }
    }
};

int main()
{
    int n;
    Stack st(5);
    while (true)
    {
        cout << "\n\nPress 1 to push element -->" << endl;
        cout << "Press 2 to pop element -->" << endl;
        cout << "Press 9 to display element -->" << endl;
        cout << "Press 0 to exit -->" << endl;
        cout << "Enter : ";
        cin >> n;
        if (n == 1)
        {
            cout << "Enter id :  ";
            int id;
            cin >> id;
            st.push(id);
        }
        else if (n == 2)
            st.pop();
        else if (n == 9)
            st.display();
        else if (n == 0)
            break;
    }
    return 0;
};