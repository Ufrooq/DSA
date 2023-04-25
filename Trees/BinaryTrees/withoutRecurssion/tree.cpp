#include <iostream>
using namespace std;
class bst
{
public:
    int id;
    bst *right;
    bst *left;
    bst()
    {
        id = 0;
        right = NULL;
        left = NULL;
    }
    void setID(int x)
    {
        id = x;
    }
};

bst *root = NULL;

bst *nodeCreation()
{
    bst *temp = new bst;
    cout << "enter id\n";
    cin >> temp->id;
    return temp;
}
void insertion()
{
    bst *current = nodeCreation();
    if (root == NULL)
    {
        cout << "start null working\n";
        root = current;
    }
    else
    {
        bst *transverse = root;
        bst *prev = NULL;
        while (transverse != NULL)
        {
            cout << "loop working\n";
            prev = transverse;
            if (current->id > root->id)
            {
                cout << "if working\n";
                transverse = transverse->right;
            }
            else
            {
                cout << "else working\n";
                transverse = transverse->left;
            }
        }
        if (current->id > prev->id)
        {
            prev->right = current;
        }
        else
        {
            prev->left = current;
        }
    }
}

// void display()
// {
//     bst *p = root;
//     int id;
//     cout << "enter id to see the pattern\n";
//     cin >> id;
//     while (p != NULL)
//     {
//         cout << p->id << " ";
//         if (id > p->id)
//         {
//             p = p->right;
//         }
//         else
//         {
//             p = p->left;
//         }
//     }
// }

void preorder(bst *temp)
{
    if (temp != NULL)
    {
        cout << temp->id << " ";
        preorder(temp->left);
        preorder(temp->right);
    }
}
void postorder(bst *temp)
{
    if (temp != NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        cout << temp->id << " ";
    }
}
void inorder(bst *temp)
{
    if (temp != NULL)
    {
        inorder(temp->left);
        cout << temp->id << " ";
        inorder(temp->right);
    }
}
int main()
{
    int opt;
    do
    {
        cout << "press 1 to insert\n2 to display in preorder\n3 to display in inorder\n4 to display in postorder\n";
        cin >> opt;
        switch (opt)
        {
        case 1:
            insertion();
            break;
        case 2:
            preorder(root);
            break;
        case 3:
            inorder(root);
            break;
        case 4:
            postorder(root);
            break;
        }
    } while (opt != 0);
}