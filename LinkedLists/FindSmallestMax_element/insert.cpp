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

void insertNode(Node *current, Node *&head, Node *&tail)
{
    cout << "Enter id : ";
    cin >> current->id;
    cout << "Entered id is : " << current->id << endl;
    if (tail == NULL)
        head = tail = current;
    else
    {
        tail->next = current;
        tail = current;
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

void findLeast()
{
    Node *crt = head1;
    Node *least = head1;

    while (crt->next != NULL)
    {
        if (least->id > crt->next->id)
            least = crt->next;
        crt = crt->next;
    }
    cout << "\nLeast element is " << least->id << endl;
}

void findMost()
{
    Node *crt = head1;
    Node *most = head1;
    while (crt->next != NULL)
    {
        if (most->id < crt->next->id)
            most = crt->next;
        crt = crt->next;
    }
    cout << "\nHighest element is " << most->id << endl;
}

int main()
{
    while (true)
    {

        cout << "\nEnter 1 for Node1 : " << endl;
        cout << "Enter 2 for Node2 : " << endl;
        cout << "Enter 3 for display List1 : " << endl;
        cout << "Enter 4 for display List2 : " << endl;
        cout << "Enter 5 for Max Element : " << endl;
        cout << "Enter 6 for MIn Element : " << endl;
        cout << "\nEnter : ";
        int n;
        cin >> n;
        if (n == 1)
        {
            Node *current = new Node;
            insertNode(current, head1, tail1);
        }
        else if (n == 2)
        {
            Node *current = new Node;
            insertNode(current, head2, tail2);
        }
        else if (n == 3)
        {
            display(head1);
        }
        else if (n == 4)
        {
            display(head2);
        }
        else if (n == 5)
            findMost();
        else if (n == 6)
            findLeast();
        else if (n == 9)
        {
            cout << "\nExit ! ";
            break;
        }
    }
    return 0;
};
