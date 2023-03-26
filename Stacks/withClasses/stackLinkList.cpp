#include <iostream>
using namespace std;

class Node
{
public:
    int id;
    Node *prev = NULL;
    Node *next = NULL;
};

class Stack
{
public:
    Node *top = NULL;
    void push(int x)
    {
        Node *newNode = new Node;
        newNode->id = x;
        if (top == NULL)
            top = newNode;
        else
        {
            top->next = newNode;
            newNode->prev = top;
            top = top->next;
        }
    }
    void pop()
    {
        if (top == NULL)
            cout << "No elements are present for now :|||" << endl;
        else
        {
            Node *temp = top;
            top = top->prev;
            delete (temp);
        }
    }
    void peek()
    {
        if (top == NULL)
            cout << "\nNo elements are present :|||" << endl;
        else
            cout << "\nId of top element is : " << top->id << endl;
    }
};

int main()
{

    int n;
    Stack st;
    while (true)
    {
        cout << "\nPress 1 to push element -->" << endl;
        cout << "Press 2 to pop element -->" << endl;
        cout << "Press 3 to display element -->" << endl;
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
        else if (n == 3)
            st.peek();
        else if (n == 0)
            break;
    }

    return 0;
};