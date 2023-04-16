#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class Tree
{
public:
    Node *buildTress(Node *root)
    {
        cout << "Enter data for Node : " << endl;
        int data;
        cin >> data;
        root = new Node(data);
    };
};

int main()
{
    Tree tr;
    Node *root = NULL;
    root = tr.buildTress(root);
    return 0;
};