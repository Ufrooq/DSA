#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int id;
    Node *left = NULL;
    Node *right = NULL;
    int height = 1;
};
Node *root = NULL;

int getHeight(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return root->height;
    }
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

Node *rightRotate(Node *x)
{
    Node *y = x->left;
    x->left = y->right;
    y->right = x;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    return y;
}
Node *leftRotate(Node *x)
{
    Node *y = x->right;
    x->right = y->left;
    y->left = x;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    return y;
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {

        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->id << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}

Node *createNode(int newData)
{
    Node *newNode = new Node;
    newNode->id = newData;
    return newNode;
}

Node *insert(Node *root, int data)
{
    //* Insertion Code ------------>
    if (root == NULL)
    {
        return (createNode(data));
    }
    if (data < root->id)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->id)
    {
        root->right = insert(root->right, data);
    }
    // *finding height and balance factor of nodes --->
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int balanceFactor = getBalanceFactor(root);

    // *Rotation ---->
    //  If the node gets unbalanced we'll incounter 4-cases :
    //  1. Left Left Case :
    if (balanceFactor > 1 && data < root->left->id)
        return rightRotate(root);

    // 2. Right Right Case :
    if (balanceFactor < -1 && data > root->right->id)
        return leftRotate(root);

    // 3. Left Right Case :
    if (balanceFactor > 1 && data > root->left->id)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    // 4. Right Left Case :
    if (balanceFactor < -1 && data < root->right->id)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    //* returning root --->
    return root;
}
void display(Node *temp)
{
    if (temp == NULL)
    {
        return;
    }
    display(temp->left);
    cout << temp->id << " ";
    display(temp->right);
}

int main()
{
    int n;
    while (true)
    {
        cout << "\n\nEnter 1 to insert ---> " << endl;
        cout << "Enter 2 for levelOrderTraversal  --->" << endl;
        cout << "Enter 3 for display  --->" << endl;
        cout << "Enter 0 to break --->" << endl;
        cout << "Enter : ";
        cin >> n;
        if (n == 1)
        {
            cout << "Enter data : ";
            int data;
            cin >> data;
            root = insert(root, data);
        }
        else if (n == 2)
        {
            levelOrderTraversal(root);
        }
        else if (n == 3)
        {
            display(root);
        }
    }
    return 0;
};