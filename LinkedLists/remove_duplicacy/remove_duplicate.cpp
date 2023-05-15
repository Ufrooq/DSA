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

Node *reverse(Node *head)
{
    Node *current = tail;
    Node *sts = NULL;
    while (head->next != NULL)
    {
        Node *prev = head;
        while (prev->next != current)
        {
            prev = prev->next;
        }
        if (sts == NULL)
        {
            current->next = head;
            prev->next = NULL;
            sts = current;
            current = prev;
        }
        else
        {
            current->next = head;
            prev->next = NULL;
            sts->next = current;
            sts = sts->next;
            current = prev;
        }
    }
    Node *temp = head;
    head = tail;
    tail = temp;
}

int main()
{
    int n;
    while (true)
    {
        cout << "\n\nPress 1 to insert END : " << endl;
        cout << "Press 2 to ReMoVe Duplicates Elements from Sorted-List : " << endl;
        cout << "Press 3 to ReMoVe Duplicates Elements from Unsorted-List : " << endl;
        cout << "Press 4 to reverse List : " << endl;
        cout << "Press 9 to display : " << endl;
        cout << "Press 0 to exit() : " << endl;
        cin >> n;
        if (n == 1)
            insertEnd();
        else if (n == 2)
            remove_Duplicates_SortedList();
        else if (n == 3)
            remove_Duplicates_UnSortedList();
        else if (n == 4)
            reverse(head);
        else if (n == 9)
            display();
        else if (n == 0)
        {
            break;
        }
    }
    return 0;
};