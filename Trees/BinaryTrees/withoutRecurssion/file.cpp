#include <iostream>
#include <queue>
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
            if (temp->right)
                q.push(temp->right);
            if (temp->left)
                q.push(temp->left);
        }
    }
}

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
    if (temp->left == NULL && temp->right == NULL)
    {
        cnt++;
        return;
    }
    findLeafNodes(temp->left);
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
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

Node *deleteBSTnode(Node *root, int x)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (root->id == x)
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
        else if (root->right != NULL && root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right != NULL && root->left != NULL)
        {
            int min = findMin(root->right)->id;
            root->id = min;
            root->right = deleteBSTnode(root->right, min);
            return root;
        }
    }

    else if (x < root->id)
    {
        root->left = deleteBSTnode(root->left, x);
        return root;
    }
    else if (x > root->id)
    {
        root->right = deleteBSTnode(root->right, x);
        return root;
    }
}

int findHeight(Node *root)
{

    if (root == NULL)
    {
        return 0;
    }
    int left = findHeight(root->left);
    int right = findHeight(root->right);
    int ans = max(left, right) + 1;
    return ans;
}

int findDiameter(Node *root)
{
    if (root == NULL)
    {
        return 0;
        int opt1 = findDiameter(root->left);
        int opt2 = findDiameter(root->right);
        int opt3 = findHeight(root->left) + findHeight(root->right) + 1;
        int ans = max(max(opt1, opt2), opt3);
        return ans;
    }
}

bool isBalanced(Node *root)
{
    if (root == NULL)
    {
        return true;
    }
    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);
    return findHeight(root->left) - findHeight(root->right) <= 1;
}

int findDepth(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftDepth = findDepth(root->left);
    int rightDepth = findDepth(root->right);
    return (max(leftDepth, rightDepth) + 1);
}

Node *rotation(Node *root)
{

    if (root == NULL)
    {
        return NULL;
    }
    Node *rootLeft = rotation(root->left);
    Node *rootRight = rotation(root->right);
    bool isValidNode = isBalanced(root);
    if (!isValidNode && root != NULL)
    {
        cout << "Ambigious Node is : " << root->id << endl;
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
        cout << "Enter 7 to find Max Value   --->" << endl;
        cout << "Enter 8 for level traversal   --->" << endl;
        cout << "Enter 9  to find height of Tree --->" << endl;
        cout << "Enter 10  to find depth of Tree --->" << endl;
        cout << "Enter 11  to find diameter of Tree --->" << endl;
        cout << "Enter 12  to check Balanced AVL Tree --->" << endl;
        cout << "Enter 13  for rotation  --->" << endl;
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
            cout << "Leaf Nodes are " << cnt << endl;
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

        else if (n == 8)
        {
            levelOrderTraversal(root);
        }
        else if (n == 9)
        {
            cout << "Height of Tree is : " << findHeight(root) << endl;
        }
        else if (n == 10)
        {
            cout << "Height of Tree is : " << findDepth(root) << endl;
        }
        else if (n == 11)
        {
            cout << "Diameter of Tree is : " << findDiameter(root) << endl;
        }
        else if (n == 12)
        {
            if (isBalanced(root))
                cout << "Tree is balanced !!" << endl;
            else
                cout << "Tree is UN-balanced !!" << endl;
        }
        else if (n == 13)
        {
            cout << "Ambigious Node is : " << rotation(root)->id << endl;
        }
        else if (n == 0)
            break;
    }

    return 0;
};