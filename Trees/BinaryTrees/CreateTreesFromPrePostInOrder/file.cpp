#include <iostream>
using namespace std;

struct Node
{
    int id;
    Node *left = NULL;
    Node *right = NULL;
};
int index = 0;
Node *buildTree(int preOrder[], int inOrder[], int start, int end)
{

    int currentIndex = preOrder[index++];
    Node *newNode = new Node();
    newNode->id = currentIndex;

    int position = search(inOrder, start, end, currentIndex);
    newNode->left = buildTree(preOrder, inOrder, start, position - 1);
    newNode->right = buildTree(preOrder, inOrder, position + 1, end);
}
int main()
{

    int preOrder[] = {1, 2, 4, 3, 5};
    int inOrder[] = {4, 2, 1, 5, 3};

    return 0;
};