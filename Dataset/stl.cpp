#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

struct Node
{
    string country;
    int deaths;
    int recovered;
    int active;
    Node *prv = NULL;
    Node *next = NULL;
};

Node *head = NULL;

class Stack
{
public:
    Node *createNode(string country, int deaths, int recovered, int active)
    {
        Node *newNode = new Node;
        newNode->country = country;
        newNode->deaths = deaths;
        newNode->recovered = recovered;
        newNode->active = active;
        return newNode;
    }
    void push(Node *newData)
    {
        if (head == NULL)
        {
            head = newData;
        }
        else
        {
            newData->next = head;
            head->prv = newData;
            head = newData;
        }
    }

    int size(int x)
    {
        if (head == NULL)
        {
            return 0;
        }
        Node *temp = front();
        pop();
        int sz = size(x) + 1;
        push(temp);
        return sz;
    }

    void pop()
    {
        if (head == NULL)
        {
            cout << "list is empty\n";
        }
        else
        {
            if (head->next == NULL)
            {
                head = NULL;
            }
            else
            {
                Node *temp = head;
                head = head->next;
                head->prv = NULL;
                temp->next = NULL;
            }
        }
    }
    Node *front()
    {
        return head ? head : NULL;
    }

    void print()
    {
        if (head == NULL)
        {
            cout << "No Data Found !!" << endl;
        }
        else
        {
            Node *temp = front();
            pop();
            cout << temp->country << "\t" << temp->deaths << "\t" << temp->recovered << "\t" << temp->active << endl;
            print();
            push(temp);
        }
    }

    void insertEnd(Node *temp)
    {
        if (head == NULL)
        {
            push(temp);
            return;
        }
        else
        {
            Node *a = front();
            pop();
            insertEnd(temp);
            push(a);
        }
    }
    void reverse()
    {
        if (head == NULL)
        {
            cout << "List is reversed !!" << endl;
        }
        else
        {
            Node *temp = front();
            pop();
            reverse();
            insertEnd(temp);
        }
    }

    Node *findMin(Node *trans, Node *&least)
    {
        if (trans == NULL)
        {
            return NULL;
        }
        else
        {
            Node *temp = front();
            if (temp->active < least->active)
            {
                least = temp;
            }
            pop();
            trans = front();
            findMin(trans, least);
            push(temp);
        }
    }
};

int main()
{
    Stack st;
    // reading data from file
    ifstream fin;
    fin.open("./country_wise_latest.csv");
    string line, word;
    vector<string> lineData;
    int lines = 0;
    while (!fin.eof())
    {
        // reading data and adding to vector
        getline(fin, line);
        stringstream s(line);
        while (getline(s, word, ','))
        {
            lineData.push_back(word);
        }
        // type casting deaths from string to int
        stringstream s1(lineData[1]);
        int deaths;
        s1 >> deaths;
        // type casting recovered from string to int
        stringstream s2(lineData[2]);
        int recovered;
        s2 >> recovered;
        // type casting active from string to int
        stringstream s3(lineData[4]);
        int active;
        s3 >> active;
        // adding data to linked list
        if (lines != 0)
        {
            Node *temp = st.createNode(lineData[0], deaths, recovered, active);
            st.push(temp);
        }
        // clearing vector
        lineData.clear();
        lines++;
    }
    int n;
    while (n != 0)
    {
        cout << "\nEnter 01 to print data : " << endl;
        cout << "Enter 02 to print the size of data : " << endl;
        cout << "Enter 03 to reverse : " << endl;
        cout << "Enter 04 to find Min : " << endl;
        cout << "Enter 05 to print_Countries_With_High_death_rates :" << endl;
        cout << "Enter : ";
        cin >> n;

        if (n == 1)
        {
            cout << "Countries : Deaths\tRecovered\tActive" << endl;
            cout << "----------------------------------------" << endl;
            st.print();
        }
        else if (n == 2)
        {
            int x = 0;
            cout << "Size of data is : " << st.size(x) << endl;
        }
        else if (n == 3)
        {
            st.reverse();
        }
        else if (n == 4)
        {
            Node *trans = head;
            st.findMin(head, trans);
            cout << "Minimum cases are in : " << trans->country << endl;
        }
    }
    //

    return 0;
};