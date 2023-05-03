#include <iostream>
using namespace std;

struct Node
{
    int id;
    Node *next = NULL;
};
Node *head = NULL;
Node *tail = NULL;

void insert()
{
    Node *current = new Node;
    cout << "\nEnter id : ";
    cin >> current->id;
    if (tail == NULL)
    {
        head = tail = current;
        tail->next = head;
    }
    else
    {
        tail->next = current;
        tail = tail->next;
        tail->next = head;
    }
}

void displayList()
{
    Node *prnt = tail->next;
    if (prnt == NULL)
        cout << "No Records are present for NOW !!";
    else
    {
        while (prnt != tail)
        {
            cout << prnt->id << " ";
            prnt = prnt->next;
        }
        cout << prnt->id;
    }
}

bool check()
{

    return (tail->next != NULL) ? true : false;
}

int main()
{
    int n;
    while (true)
    {
        cout << "\nPress 1 to insert : " << endl;
        cout << "Press 2 to display : " << endl;
        cout << "Press 3 to check circular : " << endl;
        cout << "Press 0 to exit() : " << endl;
        cout << "Enter : ";
        cin >> n;
        if (n == 1)
            insert();
        else if (n == 2)
            displayList();
        else if (n == 2)
            check();
        else if (n == 0)
            break;
    }
    return 0;
};