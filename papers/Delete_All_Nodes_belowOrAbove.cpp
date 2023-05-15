#include <iostream>
using namespace std;

struct Node
{
    int id;
    Node *next = NULL;
};
Node *head = NULL;
Node *tail = NULL;
//-----------------

void deleteElements()
{
    Node *prev = NULL;
    Node *trans = head;
    int val;
    cout << "\nEnter value : ";
    cin >> val;
    while (trans != NULL)
    {
        if (trans->id <= val)
        {
            Node *temp = trans;
            if (trans == head)
                head = trans->next;
            else if (trans == tail)
                tail = prev;
            trans = trans->next;
            if (prev != NULL)
            {
                prev->next = trans;
            }
            delete temp;
        }
        else
        {
            prev = trans;
            trans = trans->next;
        }
    }
}

void insertEnd()
{
    Node *current = new Node;
    cout << "Enter id : ";
    cin >> current->id;
    if (tail == NULL)
        head = tail = current;
    else
    {
        tail->next = current;
        tail = current;
    }
};

void display()
{
    Node *prnt = head;
    if (prnt == NULL)
        cout << "No Records are present for NOW !!";
    else
    {
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
        cout << "\n\nPress 1 to insert END : " << endl;
        cout << "Press 2 to  delete Elements from  : " << endl;
        cout << "Press 9 to display : " << endl;
        cout << "Press 0 to exit() : " << endl;
        cin >> n;
        if (n == 1)
            insertEnd();
        else if (n == 2)
            deleteElements();
        else if (n == 9)
            display();
        else if (n == 0)
        {
            break;
        }
    }
    return 0;
};