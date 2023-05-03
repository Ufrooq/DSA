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
    cout << "Enter data : ";
    cin >> current->id;
    if (root == NULL)
    {
        root = current;
    }
    else
    {
        Node *traverse = root;
        Node *prev = NULL;
        while (traverse != NULL)
        {
            prev = traverse;
            if (current->id > traverse->id)
                traverse = traverse->right;

            else
                traverse = traverse->left;
        }
        if (current->id > prev->id)
        {
            prev->right = current;
            cout << "Inserted in right of node " << prev->id << endl;
        }
        else
        {
            prev->left = current;
            cout << "Inserted in left of node " << prev->id << endl;
        }
    }
}
// void display()
// {
//     cout << "\nEnter id to display pattren : ";
//     int x;
//     cin >> x;
//     Node *p = root;
//     while (p != NULL && p->id != x)
//     {
//         cout << p->id << " ";
//         if (x > p->id)
//             p = p->right;
//         else
//             p = p->left;
//     }
//     if (p != NULL)
//         cout << p->id;
// }

void displayInorder(Node *temp)
{
    if (temp == NULL)
    {
        return;
    }
    displayInorder(temp->left);
    cout << temp->id << " ";
    displayInorder(temp->right);
}

// ! code to delete fulll Node ----->
// void deleteNode(int x)
// {
//     Node *del = root;
//     Node *prev = NULL;
//     while (del != NULL && del->id != x)
//     {
//         prev = del;
//         if (x > del->id)
//             del = del->right;
//         else
//             del = del->left;
//     }
//     if (del != NULL)
//     {
//         if (x > prev->id)
//             prev->right = NULL;
//         else
//             prev->left = NULL;
//     }
//     else
//         cout << "id not found !!" << endl;
// }

// Node *findMin(Node *root)
// {
//     Node *temp = root;
//     while (temp->left != NULL)
//     {
//         temp = temp->left;
//     }
//     return temp;
// }
// Node *deleteBSTnode(Node *root, int val)
// {

//     if (root == NULL)
//         return root;

//     else if (root->id == val)
//     {
//         if (root->left == NULL && root->right == NULL)
//         {
//             delete root;
//             return NULL;
//         }
//         else if (root->left != NULL && root->right == NULL)
//         {
//             Node *temp = root->left;
//             delete root;
//             return temp;
//         }
//         else if (root->right != NULL && root->left == NULL)
//         {
//             Node *temp = root->right;
//             delete root;
//             return temp;
//         }
//         else if (root->right != NULL && root->left != NULL)
//         {
//             int min = findMin(root->right)->id;
//             root->id = min;
//             root->right = deleteBSTnode(root->right, min);
//             return root;
//         }
//     }
//     else if (val < root->id)
//     {
//         root->left = deleteBSTnode(root->left, val);
//         return root;
//     }
//     else if (val > root->id)
//     {
//         root->right = deleteBSTnode(root->right, val);
//         return root;
//     }
// }

Node *findMin(Node *root)
{
    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

int cnt = 0;
void findLeafNodes(Node *temp)
{
    if (temp == NULL)
    {
        return;
    }
    findLeafNodes(temp->left);
    cnt++;
    findLeafNodes(temp->right);
}

bool findX(int x)
{
    bool present = false;
    Node *traverse = root;
    while (traverse != NULL && traverse->id != x)
    {
        if (x > traverse->id)
            traverse = traverse->right;
        else
            traverse = traverse->left;
    }
    if (traverse != NULL)
        present = true;

    return present;
}

Node *findMax(Node *root)
{

    Node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}

Node *deleteBSTnode(Node *root, int val)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (root->id == val)
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        else if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->left != NULL && root->right != NULL)
        {
            int min = findMin(root->right)->id;
            cout << "Min value is : " << min << endl;
            root->id = min;
            root->right = deleteBSTnode(root->right, min);
            return root;
        }
    }
    else if (val < root->id)
    {
        root->left = deleteBSTnode(root->left, val);
        return root;
    }
    else if (val > root->id)
    {
        root->right = deleteBSTnode(root->right, val);
        return root;
    }
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
        cout << "Enter 5 to find X  --->" << endl;
        cout << "Enter 6 to find Min Value   --->" << endl;
        cout << "Enter 7 to find Max Value   --->" << endl;
        cout << "Enter 0 to break --->" << endl;
        cout << "Enter : ";
        cin >> n;
        if (n == 1)
            insert();
        else if (n == 2)
            displayInorder(root);
        else if (n == 3)
        {
            cout << "Enter node : " << endl;
            int x;
            cin >> x;
            deleteBSTnode(root, x);
        }
        else if (n == 4)
        {
            findLeafNodes(root);
            cout << "Leaf Nodes are " << cnt / 2 << endl;
        }
        else if (n == 5)
        {
            int x;
            cout << "Enter X : ";
            cin >> x;
            if (findX(x))
                cout << "X is present in the Tree\n";
            else
                cout << "X is NOT-present in the Tree\n";
        }
        else if (n == 6)
            cout << "The min value is : " << findMin(root)->id << endl;
        else if (n == 7)
            cout << "The max value is : " << findMax(root)->id << endl;
        else if (n == 0)
            break;
    }

    return 0;
};