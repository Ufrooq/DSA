#include <iostream>
using namespace std;

struct Node
{
    int id;
    Node *next = NULL;
};
Node *head = NULL;
Node *tail = NULL;

void insertSorted()
{
    Node *current = new Node;
    cout << "\nEnter id : ";
    cin >> current->id;
    if (tail == NULL)
        head = tail = current;
    else
    {
        if (current->id < head->id)
        {
            current->next = head;
            head = current;
        }
        else if (current->id > tail->id)
        {
            tail->next = current;
            tail = tail->next;
        }
        else
        {
            if (head->next == NULL)
            {
                tail->next = current;
                tail = tail->next;
            }
            else
            {
                Node *ctrl = head;
                while ((ctrl->next != NULL) && (ctrl->next->id < current->id))
                {
                    ctrl = ctrl->next;
                }
                current->next = ctrl->next;
                ctrl->next = current;
            }
        }
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

int main()
{
    int n;
    while (true)
    {
        cout << "\nPress 1 to insert Sorted : " << endl;
        cout << "Press 2 to display : " << endl;
        cout << "Press 0 to exit() : " << endl;
        cout << "Enter : ";
        cin >> n;
        if (n == 1)
            insertSorted();
        else if (n == 2)
            displayList();
        else if (n == 0)
            break;
    }
    return 0;
};