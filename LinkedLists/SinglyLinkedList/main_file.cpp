#include <iostream>
using namespace std;
struct Node
{
    int id;
    string nam;
    float marks;
    Node *next = NULL;
};
Node *head = NULL;
Node *tail = NULL;
//------------------------------------

// info from user :
Node *info()
{
    Node *current = new Node;
    cout << "Enter studet id : ";
    cin >> current->id;
    cout << "Enter studet Name : ";
    cin >> current->nam;
    cout << "Enter studet Marks : ";
    cin >> current->marks;
    return current;
}
//-----------------------
void insertEnd()
{
    Node *current = info();
    if (tail == NULL)
        head = tail = current;
    else
    {
        tail->next = current;
        tail = current;
    }
};

void insertStart()
{
    Node *current = info();
    if (head == NULL)
        head = tail = current;
    else
    {
        current->next = head;
        head = current;
    }
}

void insertById()
{
    if (head == NULL)
        cout << "No Records are present for NOW !!";
    else
    {
        Node *excess = head;
        int val;
        cout << "Enter Student Id to excess : ";
        cin >> val;
        while (excess != NULL)
        {
            if (excess->id == val)
            {
                Node *current = info();
                current->next = excess->next;
                excess->next = current;
                break;
            }
            excess = excess->next;
        }
    }
}

void deleteEnd()
{
    if (head == NULL)
        cout << "No Records are present for NOW !!";
    else
    {
        Node *prev = NULL;
        Node *temp = head;
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        // node changing for last node removal
        prev->next = NULL;
        tail = prev;
        delete temp;
        cout << "Element Deleted !!";
    }
}

void deleteById(int id)
{
    if (head == NULL)
        cout << "No Records are present for NOW !!";
    else
    {
        Node *prev = NULL;
        Node *temp = head;
        while (temp->id != id)
        {
            prev = temp;
            temp = temp->next;
        }
        // node changing for last node removal
        prev->next = temp->next;
        delete temp;
        cout << "Element Deleted !!";
    }
}
void deleteStart()
{
    Node *temp = head;
    head = head->next;
    delete temp;
    cout << "Element Deleted !!";
}

void removeDuplicates()
{

    Node *current = head;
    while (current != NULL)
    {
        Node *chk = current->next;
        while (chk != NULL)
        {
            if (chk->id == current->id)
            {
                current->next = current->next->next;
                Node *temp = chk;
                delete (temp);
            }
            chk = chk->next;
        }
        current = current->next;
    }
}

// !!!display //
void displayList()
{
    Node *prnt = head;
    if (prnt == NULL)
        cout << "No Records are present for NOW !!";
    else
    {
        while (prnt != NULL)
        {
            cout << "\n----------------------------------------" << endl;
            cout << "Id of Student is : " << prnt->id << endl;
            cout << "Name of student : " << prnt->nam << endl;
            cout << "Obtained Marks : " << prnt->marks << endl;
            cout << "----------------------------------------\n";
            prnt = prnt->next;
        }
    }
}

int main()
{
    int n;
    while (true)
    {
        cout << "\n\nPress 1 to insert END : " << endl;
        cout << "Press 2 to insert START : " << endl;
        cout << "Press 3 to after a Student id : " << endl;
        cout << "Press 4 to Delete END : " << endl;
        cout << "Press 5 to Delete START : " << endl;
        cout << "Press 6 to Delete a NODE : " << endl;
        cout << "Press 7 to ReMoVe Duplicates Elements from List : " << endl;
        cout << "Press 9 to display : " << endl;
        cout << "Press 0 to exit() : " << endl;
        cin >> n;
        if (n == 1)
            insertEnd();
        else if (n == 2)
            insertStart();
        else if (n == 3)
            insertById();
        else if (n == 4)
            deleteEnd();
        else if (n == 5)
            deleteStart();
        else if (n == 6)
        {
            int id;
            cout << "\nEnter id : ";
            cin >> id;
            deleteById(id);
        }
        else if (n == 7)
            removeDuplicates();
        else if (n == 9)
            displayList();
        else if (n == 0)
        {
            break;
        }
    }
    return 0;
};