#include <iostream>
using namespace std;

struct Node
{
    int id;
    Node *next = NULL;
};
Node *head = NULL;
Node *tail = NULL;
Node *head2 = NULL;
Node *tail2 = NULL;

void insert()
{
    Node *current = new Node;
    cout << "\nEnter id : ";
    cin >> current->id;
    if (tail == NULL)
    {
        head = tail = current;
    }
    else
    {
        tail->next = current;
        tail = tail->next;
    }
}

void displayList()
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

Node *findLeast()
{
    Node *least = head;
    Node *prev = NULL;
    Node *current = head->next;
    while (current != NULL)
    {
        if (least->id > current->id)
        {
            prev = current;
            least = current;
        }
        current = current->next;
    }
    if (least == head)
        head = head->next;
    else if (least == tail)
        tail = prev;
    else
        prev->next = least->next;
    return least;
}

void sort()
{
    while (head != NULL && tail != NULL)
    {
        if (tail2 == NULL)
        {
            head2 = tail2 = findLeast();
        }
        else
        {
            tail2->next = findLeast();
            tail2 = tail2->next;
        }
    }
}

int main()
{
    int n;
    while (true)
    {
        cout << "\nPress 1 to insert : " << endl;
        cout << "Press 2 to display : " << endl;
        cout << "Press 3 to sort List" << endl;
        cout << "Press 4 to find least :" << endl;
        cout << "Press 0 to exit() : " << endl;
        cout << "Enter : ";
        cin >> n;
        if (n == 1)
            insert();
        else if (n == 2)
            displayList();
        else if (n == 3)
            sort();
        else if (n == 4)
            cout << "Least value is : " << findLeast()->id << endl;
        else if (n == 0)
            break;
    }
    return 0;
};