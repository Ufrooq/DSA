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

// void mergeNodes()
// {
// }

// void findLeast()
// {
//     Node *prev = NULL;
//     Node *crt = head2;
//     Node *least = head2;
//     while (crt->next != NULL)
//     {
//         if (crt->id > crt->next->id)
//         {
//             least = crt->next;
//             if (least != head2)
//                 prev = head2;
//             while (prev->next != least)
//                 prev = prev->next;
//         }
//         crt = crt->next;
//     }
// }

void merge2Lists()
{
    Node *ctrl2 = head2;
    Node *temp = head2;
    while (ctrl2 != NULL)
    {
        cout << "Enter looop" << endl;
        Node *ctrl1 = head1;
        if (ctrl2->id < head1->id)
        {
            temp = ctrl2;
            ctrl2 = ctrl2->next;
            temp->next = head1;
            head1 = temp;
        }
        else
        {
            while ((ctrl1->next != NULL) && (ctrl1->next->id < ctrl2->id))
            {
                ctrl1 = ctrl1->next;
            }
            temp = ctrl2;
            ctrl2 = ctrl2->next;
            temp->next = ctrl1->next;
            ctrl1->next = temp;
        }
    }
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
            cout << "\nSorted List ---- >" << endl;
            display(head1);
        }
        else if (n == 4)
        {
            cout << "\nUnsorted List ---- >" << endl;
            display(head2);
        }
        else if (n == 5)
            merge2Lists();

        else if (n == 9)
        {
            cout << "\nExit ! ";
            break;
        }
    }
    return 0;
};
