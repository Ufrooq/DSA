#include <iostream>
using namespace std;

struct Node
{
    int id;
    Node *left = NULL;
    Node *right = NULL;
};

Node *root = NULL;
void insert()
{
    Node *current = new Node;
    cout << "Enter id\n";
    cin >> current->id;

    // After code for node creation --->
    if (root == NULL)
        root = current;
    else
    {
        Node *traverse = root;
        Node *prev = NULL;
        while (traverse != NULL)
        {
            prev = traverse;
            if (current->id < traverse->id)
                traverse = traverse->left;
            else
                traverse = traverse->right;
        }

        if (current->id < prev->id)
        {
            prev->left = current;
            cout << "inserted in left" << endl;
        }
        else
        {
            prev->right = current;
            cout << "inserted in right" << endl;
        }
    }
}
void display()
{
    cout << "\nEnter id to display pattren : ";
    int x;
    cin >> x;
    Node *p = root;
    while (p != NULL && p->id != x)
    {
        cout << p->id << " ";
        if (x > p->id)
            p = p->right;
        else
            p = p->left;
    }
    if (p != NULL)
        cout << p->id;
}

void deleteNode(int x)
{
    Node *del = root;
    Node *prev = NULL;
    while (del != NULL && del->id != x)
    {
        prev = del;
        if (x > del->id)
            del = del->right;
        else
            del = del->left;
    }
    if (del != NULL)
    {
        if (x > prev->id)
            prev->right = NULL;
        else
            prev->left = NULL;
    }
    else
        cout << "id not found !!" << endl;
}

int main()
{
    int n;
    while (true)
    {
        cout << "\n\nEnter 1 to insert ---> " << endl;
        cout << "Enter 2 to dispaly --->" << endl;
        cout << "Enter 3 to delete Node --->" << endl;
        cout << "Enter 4 to find leaf Nodes --->" << endl;
        cout << "Enter 0 to break --->" << endl;
        cout << "Enter : ";
        cin >> n;
        if (n == 1)
            insert();
        else if (n == 2)
            display();
        else if (n == 3)
        {
            cout << "Enter node : " << endl;
            int x;
            cin >> x;
            deleteNode(x);
        }
        else if (n == 0)
            break;
    }

    return 0;
};