#include <iostream>
using namespace std;

struct Node
{
    int id;
    Node *next = NULL;
};
Node *head = NULL;
Node *tail = NULL;

// void swap(int x, int y)
// {
//     Node *px = NULL;
//     Node *py = NULL;
//     Node *cx = head;
//     Node *cy = head;

//     if (head == NULL)
//         cout << "No Records are present for NOW !!";
//     else
//     {

//         // Traversing through Linked list to get cx px :
//         while (cx->id != x && cx != NULL)
//         {
//             px = cx;
//             cx = cx->next;
//         }
//         //--------------------------------
//         // Traversing through Linked list to get cy py :
//         while (cy->id != y && cy != NULL)
//         {
//             py = cy;
//             cy = cy->next;
//         }
//         //--------------------------------

//         if (cx == NULL || cy == NULL)
//         {
//             cout << "One or both nodes not found." << endl;
//             return;
//         }

//         if (px != NULL)
//             px->next = cy;
//         else
//             head = cy;

//         if (py != NULL)
//             py->next = cx;
//         else
//             head = cx;

//         Node *temp = cx->next;
//         cx->next = cy->next;
//         cy->next = temp;
//     }
// }

void swap(int x, int y)
{
    Node *px = NULL;
    Node *py = NULL;
    Node *cx = head;
    Node *cy = head;

    if (head == NULL)
        cout << "No Records are present for NOW !!";
    else
    {
        while (cx != NULL && cx->id != x)
        {
            px = cx;
            cx = cx->next;
        }
        while (cy != NULL && cy->id != y)
        {
            py = cy;
            cy = cy->next;
        }
        if (cx == NULL || cy == NULL)
        {
            cout << "One or both nodes not found." << endl;
            return;
        }
        else
        {
            if (px != NULL)
                px->next = cy;
            else
                head = cy;

            if (py != NULL)
                py->next = cx;
            else
                head = cx;

            Node *temp = cx->next;
            cx->next = cy->next;
            cy->next = temp;
        }
    }
}

void insertEnd()
{
    Node *current = new Node;
    cout << "Enter : ";
    cin >> current->id;
    if (tail == NULL)
        head = tail = current;
    else
    {
        tail->next = current;
        tail = current;
    }
}

void display()
{
    Node *prnt = head;
    while (prnt != NULL)
    {
        cout << prnt->id << "  ";
        prnt = prnt->next;
    }
}
int main()
{
    int n = -1;
    while (n != 0)
    {
        cout << " " << endl;
        cout << "Enter 1 to insert a value at end" << endl;
        cout << "Enter 2 to swap nodes" << endl;
        cout << "Enter 3 to display nodes" << endl;
        cout << "Enter 0 to exit" << endl;
        cin >> n;
        if (n == 1)
        {
            insertEnd();
        }
        else if (n == 2)
        {
            cout << "Enter indexs to swap : " << endl;
            int a, b;
            cout << "Enter x : ";
            cin >> a;
            cout << "\nEnter y : ";
            cin >> b;
            swap(a, b);
        }
        else if (n == 3)
        {
            display();
        }
    }
    return 0;
}