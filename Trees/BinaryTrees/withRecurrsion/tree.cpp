#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int id;
    Node *left = NULL;
    Node *right = NULL;
};

class Tree
{
public:
    Node *createNodes(Node *root)
    {
        cout << "Enter data : ";
        int data;
        cin >> data;
        root->id = data;
        if (data == -1)
            return NULL;
        cout << "\nEnter left-data of Node --->" << data << endl;
        root->left = createNodes(new Node);
        cout << "\nEnter right-data of Node --> " << data << endl;
        root->right = createNodes(new Node);
        cout << "---------> " << root->id << endl;
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
};

int main()
{
    Tree tr;
    Node *root = new Node;
    root = tr.createNodes(root);
    cout << "Your data after level-Order-traversal is : " << endl;
    tr.levelOrderTraversal(root);
    // Node *temp = root;
    // tr.display(temp);
    return 0;
};