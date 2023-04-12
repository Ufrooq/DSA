#include <iostream>
using namespace std;
class queue
{
public:
    int size;
    int front;
    int rear;
    int *array;
    queue(int x)
    {
        size = x;
        front = -1;
        rear = -1;
        array = new int[size];
    }
    bool isFull()
    {
        return front == ((rear + 1) % size);
    }
    bool isEmpty()
    {
        return front = rear == -1;
    }
    void enqueue(int x)
    {
        if (isEmpty())
        {
            front = rear = 0;
            array[rear] = x;
        }
        else
        {
            if (isFull())
            {
                cout << "no space available\n";
            }
            else
            {
                rear = (rear + 1) % size;
                array[rear] = x;
            }
        }
    }
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "dequeue not possible as queue is empty\n";
        }
        else
        {
            cout << "the following number is dequeued : " << array[front] << endl;
            if (front == rear)
            {
                front = rear = -1;
            }
            else
            {
                front = (front + 1) % size;
            }
        }
    }
    void display()
    {
        int i = front;
        cout << "\n";
        while (i != rear)
        {
            cout << array[i] + " ";
            i = (i + 1) % size;
        }
        cout << array[rear] << endl;
    }
}

;
int main()
{
    int size;
    cout << "enter size for the queue\n";
    cin >> size;
    int opt;
    queue q1(size);
    do
    {
        cout << "PRESS 0 TO EXIT\n1 TO ENQUEUE\n2 TO DEQUEUE\n3 TO DISPLAY\n";
        cin >> opt;
        switch (opt)
        {
        case 1:
            int a;
            cout << "ENTER THE INTEGER TO ENQUEUE TO THE QUEUE\n";
            cin >> a;
            q1.enqueue(a);
            cout << "front : " << q1.front << endl;
            cout << "rear : " << q1.rear << endl;
            break;
        case 2:
            q1.dequeue();
            cout << "front : " << q1.front << endl;
            cout << "rear : " << q1.rear << endl;
            break;
        case 3:
            q1.display();
            break;
        }
    } while (opt != 0);
}