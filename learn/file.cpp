#include <iostream>
using namespace std;

struct Node
{
    int id;
    Node *next = NULL;
};

Node *head = NULL;
Node *tail = NULL;

void insertEnd()
{
    Node *current = new Node;
    cout << "\nEnter id : ";
    cin >> current->id;
    if (head == NULL)
    {
        head = current;
        tail = current;
        tail->next = tail;
    }
    else
    {
        current->next = tail->next;
        tail->next = current;
        tail = tail->next;
    }
}

void display()
{
    Node *prnt = tail->next;
    while (prnt->next != tail->next)
    {
        cout << prnt->id << " ";
        prnt = prnt->next;
    }
    cout << prnt->id;
}

bool checkCircular()
{
    if (tail->next != NULL)
        return true;
    else
        return false;
}

int main()
{

    int n;
    while (true)
    {
        cout << "\nPress 1 to insert End : " << endl;
        cout << "Press 2 to display : " << endl;
        cout << "Press 3 to checkCircular : " << endl;
        cout << "Press 4 to exit : " << endl;
        cout << "Enter : ";
        cin >> n;
        if (n == 1)
            insertEnd();
        else if (n == 2)
            display();
        else if (n == 3)
            cout << checkCircular();
        else if (n == 4)
            break;
    }

    return 0;
};