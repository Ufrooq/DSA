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
void remove_Duplicates_UnSortedList()
{
    Node *current = head;
    while (current != NULL)
    {
        Node *chk = current;
        while (chk->next != NULL)
        {
            if (current->id == chk->next->id)
            {
                Node *temp = chk->next;
                chk->next = temp->next;
                delete (temp);
            }
            else
                chk = chk->next;
        }
        current = current->next;
    }
}

void remove_Duplicates_SortedList()
{
    Node *current = head;
    while (current != NULL)
    {
        Node *chk = current->next;
        while (chk->next != NULL)
        {
            if (current->id == chk->id)
            {
                Node *temp = chk->next;
                current->next = temp->next;
                chk->next = temp->next;
                delete (temp);
            }
            else
                chk = chk->next;
        }
        current = current->next;
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
        cout << "Press 2 to ReMoVe Duplicates Elements from Sorted-List : " << endl;
        cout << "Press 3 to ReMoVe Duplicates Elements from Unsorted-List : " << endl;
        cout << "Press 9 to display : " << endl;
        cout << "Press 0 to exit() : " << endl;
        cin >> n;
        if (n == 1)
            insertEnd();
        else if (n == 2)
            remove_Duplicates_SortedList();
        else if (n == 3)
            remove_Duplicates_UnSortedList();
        else if (n == 9)
            display();
        else if (n == 0)
        {
            break;
        }
    }
    return 0;
};