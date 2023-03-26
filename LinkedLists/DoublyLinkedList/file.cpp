#include <iostream>
using namespace std;

struct Node
{
    int id;
    Node *prev = NULL;
    Node *next = NULL;
};

Node *head = NULL;
Node *tail = NULL;

// -----------------------------------

// diplay Nodes metod :
void displayNodes()
{
    Node *prnt = head;
    if (prnt == NULL)
        cout << "No REcords Found !!  ";
    else
    {
        while (prnt != NULL)
        {
            cout << prnt->id << " ";
            prnt = prnt->next;
        }
    }
}

// insert Node metod
void insertEnd()
{
    Node *current = new Node;
    cout << "\nEnter Node id : ";
    cin >> current->id;
    if (tail == NULL)
        head = tail = current;
    else
    {
        tail->next = current;
        current->prev = tail;
        tail = tail->next;
    }
}
void insertStart()
{
    Node *current = new Node;
    cout << "\nEnter Node id : ";
    cin >> current->id;
    if (tail == NULL)
        head = tail = current;
    else
    {
        current->next = head;
        head->prev = current;
        head = current;
    }
}

void insertSpecific(Node *move)
{
    Node *current = new Node;
    cout << "\nEnter new Node id : ";
    cin >> current->id;
    current->next = move->next;
    current->prev = move;
    move->next = current;
    current->next->prev = current;
}

// deleteStart()
// {
// }
// deleteSpecific()
// {
//     if (tail == NULL)
//         cout << "No elements are present for now !";
//     else
//     {
//         Node *move = head;
//         bool valid = false;
//         cout << "Enter id to insert after : ";
//         int ck;
//         cin >> ck;
//         while (move != NULL)
//         {
//             if (move->id == ck)
//             {
//                 valid = true;
//                 tail = tail->prev;
//                 delete (tail->next);
//             }
//             move = move->next;
//         }
//         if (valid == false)
//             cout << "id not found !";
//     }
// }
void deleteEnd()
{
    if (tail == NULL)
        cout << "No elements are present for now !";
    else
    {
        tail = tail->prev;
        tail->next = NULL;
    }
}

void deleteStart()
{
    if (tail == NULL)
        cout << "No elements are present for now !";
    else
    {
        head = head->next;
        head->prev = NULL;
    }
}
void validation()
{
    Node *move = head;
    cout << "Enter id to insert after : ";
    int ck;
    cin >> ck;
    while (move != NULL)
    {
        if (move->id == ck)
        {
            insertSpecific(move);
            break;
        }
        move = move->next;
    }
}
int main()
{
    int n;
    while (true)
    {
        cout << "\n\nPress 1 to insert END : " << endl;
        cout << "Press 2 to insert START : " << endl;
        cout << "Press 3 to insert after Specific : " << endl;
        cout << "Press 4 to delete from END : " << endl;
        cout << "Press 5 to delete from START : " << endl;
        cout << "Press 6 to delete after Specific : " << endl;
        cout << "Press 9 to display : " << endl;
        cout << "Press 0 to exit() : " << endl;
        cin >> n;
        if (n == 1)
            insertEnd();
        else if (n == 2)
            insertStart();
        else if (n == 3)
            if (head == NULL)
                cout << "No data is present for now !! ";
            else
                validation();
        else if (n == 4)
            deleteEnd();
        else if (n == 5)
            deleteStart();
        else if (n == 9)
            displayNodes();
        else if (n == 0)
            break;
    }
    return 0;
};