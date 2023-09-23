#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
};
Node *root = NULL;

Node *createNode(int x)
{
    Node *newNode = new Node;
    newNode->data = x;
    return newNode;
}

int getHeight(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return root->height;
}
int getBalanceFactor(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return (getHeight(root->left) - getHeight(root->right));
    }
}

Node *rotateRight(Node *x)
{
    Node *y = x->left;
    x->left = y->right;
    y->right = x;
    x->height = max(getHeight(x->left), getHeight(x->right));
    y->height = max(getHeight(y->left), getHeight(y->right));
    return y;
}
Node *rotateLeft(Node *x)
{
    Node *y = x->right;
    x->right = y->left;
    y->left = x;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}

Node *insert(Node *root, int x)
{

    if (root == NULL)
    {
        return (createNode(x));
    }
    else if (x > root->data)
    {
        root->right = insert(root->right, x);
    }
    else
    {
        root->left = insert(root->left, x);
    }
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int bf = getBalanceFactor(root);

    // LL
    if (bf < -1 && x < root->left->data)
    {
        return rotateRight(root);
    }
    // LR
    else if (bf < -1 && x > root->left->data)
    {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    else if (bf > 1 && x > root->right->data)
    {
        return rotateLeft(root);
    }
    else if (bf > 1 && x < root->right->data)
    {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }
}

Node *findMin(Node *root, int NodeToDel)
{

    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}
Node *
deletion(int x, Node *root)
{
    if (root == NULL)
    {
        return root;
    }
    else if (root->data == x)
    {

        // no child --->
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // left child only --->
        else if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        // right child only --->
        else if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        // have both childs --->
        else if (root->left == NULL && root->right == NULL)
        {
            int min = findMin(root->right, x)->data;
            root->data = min;
            root->right = deletion(min, root->right);
            return root;
        }
    }
    else if (x > root->data)
    {
        root->right = deletion(x, root->right);
        return root;
    }
    else if (x < root->data)
    {
        root->left = deletion(x, root->left);
        return root;
    }
}

int main()
{
    int n;
    while (true)
    {
        cout << "\n\nEnter 1 to insert ---> " << endl;
        cout << "Enter 0 to break --->" << endl;
        cout << "Enter : ";
        cin >> n;
        if (n == 1)
        {
            int x;
            cout << "Enter data : ";
            cin >> x;
            insert(root, x);
        }
        else
        {
            break;
        }
    }
    return 0;
};