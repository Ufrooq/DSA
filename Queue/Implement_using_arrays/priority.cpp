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
        return (front == (rear + 1) % size) ? true : false;
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
            if (front == rear)
                front = rear = -1;
            else
                front = (front + 1) % size;
        }
    }

    void shiftRight(int *index)
    {
        int shift = rear;
        while (shift != *index)
        {
            arr[shift + 1 % size] = arr[shift];
            if (shift == 0)
                shift = size - 1;
            else
                shift--;
        }
        arr[(shift + 1) % size] = arr[shift];
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
            {
                if (elem < arr[front])
                {
                    if (front == 0)
                    {
                        front = size - 1;
                        arr[front] = elem;
                    }
                    else
                    {
                        arr[--front] = elem;
                    }
                }
                else if (elem > arr[rear])
                {
                    rear = (rear + 1) % size;
                    arr[rear] = elem;
                }
                else
                {
                    int index = front;
                    while (elem > arr[index])
                    {
                        index = (index + 1) % size;
                    }
                    shiftRight(&index);
                    arr[index] = elem;
                    rear = rear + 1 % size;
                }
            }
        }
    }

    void display()
    {
        if (isEmpty())
            cout << "Stack is empty ---->" << endl;
        else
        {
            int i = front;
            while (i != rear)
            {
                cout << arr[i] << " ";
                i = ((i + 1) % size);
            }
            cout << arr[i] << " ";
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