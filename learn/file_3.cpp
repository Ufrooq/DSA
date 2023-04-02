#include <iostream>
using namespace std;

struct Node
{
    int Data;
    int data2;
    Node *nextp = NULL;

    ~Node()
    {
        int value = this->Data;
        if (this->nextp != NULL)
        {
            delete nextp;
            this->nextp = NULL;
        }
    }
};

Node *first = NULL;
Node *last = NULL;

void insertAtLast()
{
    Node *temp = new Node;
    cout << "Enter Value" << endl;
    cin >> temp->Data;
    // temp->nextp = NULL;
    if (first == NULL)
    {
        first = last = temp;
    }
    else
    {
        last->nextp = temp;
        // last= last -> nextp;
        last = temp;
    }
}

void insertAtFirst()
{
    Node *temp = new Node;
    cout << "Enter Value" << endl;
    cin >> temp->Data;
    temp->nextp = NULL;
    if (first == NULL)
    {
        first = last = temp;
    }
    else
    {
        temp->nextp = first;
        first = temp;
    }
}

// insert with position
void insertwithid()
{
    if (first == NULL)
    {
        cout << "No data found" << endl;
        return;
    }
    int val;
    cout << "Enter the id to access: ";
    cin >> val;
    Node *traverse = first;
    while (traverse != NULL)
    {
        if (traverse->Data == val)
        {
            Node *nodetoInsert = new Node();
            int nodeValue;
            cout << "Enter the value to insert in node: " << endl;
            cin >> nodeValue;
            nodetoInsert->Data = nodeValue;
            nodetoInsert->nextp = traverse->nextp;
            traverse->nextp = nodetoInsert;
            cout << "Node inserted successfully!" << endl;
            return;
        }
        traverse = traverse->nextp;
    }
    cout << "No node with the given value was found." << endl;
}
void reverseList()
{
    if (first == NULL || first->nextp == NULL)
    {
        cout << "No data found" << endl;
        return;
    }
    Node *curr = first;
    Node *prev = NULL;
    while (curr != NULL)
    {
        Node *nextp = curr->nextp;
        curr->nextp = prev;
        prev = curr;
        curr = nextp;
    }
    first = prev;
}

void deleteNode()
{
    cout << "Enter the position: " << endl;
    int position;
    cin >> position;
    if (position == 1)
    {
        Node *temp = first;
        first = first->nextp;
        delete temp;
    }
    else
    {
        Node *crr = first;
        Node *prev = NULL;
        int cnt = 1;
        while (cnt <= position)
        {
            prev = crr;
            crr = crr->nextp;
            cnt++;
        }
        prev->nextp = crr->nextp;
        delete crr;
    }
}
// EXTRA
void deleteNodeByValue()
{
    if (first == NULL)
    {
        cout << "list is empty" << endl;
        return;
    }
    int val;
    cout << "Enter the value: " << endl;
    cin >> val;
    Node *prev = NULL;
    Node *crr = first;

    while (crr != NULL)
    {
        if (crr == first && crr->Data == val)
        {
            Node *temp = first;
            first = first->nextp;
            delete temp;
            crr = first;
        }
        else if (crr != first && crr->Data == val)
        {
            prev->nextp = crr->nextp;
            Node *temp = crr;
            crr = crr->nextp;
            delete temp;
        }
        else
        {
            prev = crr;
            crr = crr->nextp;
        }
    }
}
void swapNode()
{
    cout << "Enter the value of x and y: " << endl;
    int x, y;
    cin >> x;
    cin >> y;
    if (first == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }
    else if (x == y)
        return;

    Node *currX = first;
    Node *prevX = NULL;
    while (currX != NULL && currX->Data != x)
    {
        prevX = currX;
        currX = currX->nextp;
    }

    Node *currY = first;
    Node *prevY = NULL;
    while (currY != NULL && currY->Data != y)
    {
        prevY = currY;
        currY = currY->nextp;
    }

    if (currX == NULL || currY == NULL)
    {
        cout << "One or both nodes not found." << endl;
        return;
    }

    if (prevX != NULL)
        prevX->nextp = currY;
    else
        first = currY;

    if (prevY != NULL)
        prevY->nextp = currX;
    else
        first = currX;

    Node *temp = currX->nextp;
    currX->nextp = currY->nextp;
    currY->nextp = temp;
}

void mergeListSort()
{
    Node *
}
void deleteNodeById()
{
    if (first == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }
    int val;
    cout << "Enter the value to delete: ";
    cin >> val;
    Node *curr = first;
    Node *prev = NULL;
    while (curr != NULL)
    {
        if (curr->Data == val)
        {
            if (prev == NULL)
            {
                // Deleting the first node
                first = curr->nextp;
            }
            else
            {
                prev->nextp = curr->nextp;
            }
            delete curr;
            cout << "Node with value " << val << " has been deleted." << endl;
            return;
        }
        prev = curr;
        curr = curr->nextp;
    }
    cout << "Node with value " << val << " not found." << endl;
}

void print()
{
    Node *printvalue = first;
    while (printvalue != NULL)
    {
        cout << printvalue->Data << " ";
        printvalue = printvalue->nextp;
    }
}

int main()
{
    int n = -1;
    while (n != 0)
    {
        cout << " " << endl;
        cout << "Enter 1 to insert a value at end" << endl;
        cout << "Enter 2 to insert a value at start" << endl;
        cout << "Enter 3 to insert a value at id" << endl;
        cout << "Enter 4 to show the values" << endl;
        cout << "Enter 5 to show reverse List" << endl;
        cout << "Enter 6 to delete any node by position/id" << endl;
        cout << "Enter 7 to swap nodes" << endl;
        cout << "Enter 8 to merge and sort list" << endl;
        cout << "Enter 0 to exit" << endl;
        cin >> n;
        if (n == 1)
        {
            insertAtLast();
        }
        else if (n == 2)
        {
            insertAtFirst();
        }
        else if (n == 3)
        {
            insertwithid();
        }
        else if (n == 4)
        {
            print();
        }
        else if (n == 5)
        {
            reverseList();
            print();
        }
        else if (n == 6)
        {
            deleteNodeById();
            // print();
        }
        else if (n == 7)
        {
            swapNode();
        }
        else if (n == 8)
        {
            mergeListSort();
        }
    }
    return 0;
}