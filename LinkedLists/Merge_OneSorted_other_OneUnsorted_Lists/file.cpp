#include <iostream>
using namespace std;

struct Node
{
    int id;
    Node *next = NULL;
};
Node *head1 = NULL;
Node *tail1 = NULL;
Node *head2 = NULL;
Node *tail2 = NULL;
Node *Dummy_Node = new Node;
Node *temp_point = Dummy_Node;

void insertNode1()
{
    Node *current = new Node;
    cout << "Enter : ";
    cin >> current->id;
    if (tail1 == NULL)
        head1 = tail1 = current;
    else
    {
        tail1->next = current;
        tail1 = current;
    }
}
void insertNode2()
{
    Node *current = new Node;
    cout << "Enter : ";
    cin >> current->id;
    if (tail2 == NULL)
        head2 = tail2 = current;
    else
    {
        tail2->next = current;
        tail2 = current;
    }
}
void display(Node *hd)
{
    Node *prnt = hd;
    while (prnt != NULL)
    {
        cout << prnt->id << "  ";
        prnt = prnt->next;
    }
}

void mergeNodes()
{
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->id < head2->id)
        {
            temp_point->next = head1;
            head1 = head1->next;
        }
        else
        {
            temp_point->next = head2;
            head2 = head2->next;
        }
        temp_point = temp_point->next;
    }
    temp_point->next = head1 ? head1 : head2;
}

int main()
{
    while (true)
    {

        cout << "\nEnter 1 for Node1 : " << endl;
        cout << "Enter 2 for Node2 : " << endl;
        cout << "Enter 3 for display1 : " << endl;
        cout << "Enter 4 for display2 : " << endl;
        cout << "Enter 5 for merge : " << endl;
        cout << "Enter 6 for mergeDisplay : " << endl;
        cout << "\nEnter : ";
        int n;
        cin >> n;
        if (n == 1)
            insertNode1();
        else if (n == 2)
            insertNode2();
        else if (n == 3)
            display(head1);
        else if (n == 4)
            display(head2);
        else if (n == 5)
            mergeNodes();
        else if (n == 6)
            display(Dummy_Node->next);
        else if (n == 9)
        {
            cout << "\nExit ! ";
            break;
        }
    }

    mergeNodes();
    return 0;
};
