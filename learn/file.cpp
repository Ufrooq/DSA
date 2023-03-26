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
    }
    else
    {
        tail->next = current;
        tail = tail->next;
    }
}

void display()
{
    if (tail = NULL)
        cout << "No data found !!";
    else
    {
        Node *prnt = head;
        while (prnt != NULL)
        {
            cout << prnt->id << " ";
            prnt = prnt->next;
        }
    }
}

int main()
{

    int n;
    while (true)
    {
        cout << "\nPress 1 to insert End : " << endl;
        cout << "Press 2 to display : " << endl;
        cout << "Press 3 to exit : " << endl;
        cout << "Enter : ";
        cin >> n;
        if (n == 1)
            insertEnd();
        else if (n == 2)
            display();
        else if (n == 3)
            break;
    }

    return 0;
};