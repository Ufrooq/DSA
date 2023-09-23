#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next = NULL;
};

class ChainProbing
{
public:
    int size;
    Node *array;
    ChainProbing(int x)
    {
        size = x;
        array = new Node[size];
    }

    void insertion(int value)
    {
        Node *current = new Node;
        current->data = value;
        int index = value % size;
        current->next = array[index].next;
        array[index].next = current;
    }
    void search(int value)
    {
        int index = value % size;
        Node *temp = array[index].next;
        while (temp != NULL && temp->data != value)
        {
            temp = temp->next;
        }
        if (temp != NULL)
        {
            cout << "the address of the Node is :" << temp << endl;
            cout << temp->data << endl;
        }
        else
        {
            cout << "not found" << endl;
        }
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << i << "--->";
            Node *temp = array[i].next;
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};
int main()
{

    int size;
    cout << "ENTER SIZE" << endl;
    cin >> size;
    ChainProbing c1(size);
    int n, value;

    while (n != 0)
    {
        cout << "Enter 1 to Insert In Array" << endl;
        cout << "Enter 2 to Display" << endl;
        cout << "Enter 3 to Search A Number" << endl;
        cout << "Enter 0 to Exit" << endl;
        cin >> n;
        if (n == 1)
        {
            cout << "Enter Value" << endl;
            cin >> value;
            c1.insertion(value);
        }
        else if (n == 2)
        {
            c1.display();
        }
        else if (n == 3)
        {
            cout << "enter value to be found" << endl;
            cin >> value;
            c1.search(value);
        }
        else if (n == 0)
        {
            break;
        }
    }
}