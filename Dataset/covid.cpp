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
Node *tail = NULL;
void addNodes(string country, int deaths, int recovered, int active)
{
    Node *newNode = new Node;
    newNode->country = country;
    newNode->deaths = deaths;
    newNode->recovered = recovered;
    newNode->active = active;

    if (tail == NULL)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prv = tail;
        tail = tail->next;
    }
}

void print()
{
    if (head == NULL)
    {
        cout << "No Data Found !!" << endl;
    }
    else
    {
        Node *trave = head;
        cout << "Countries : Deaths\tRecovered\tActive" << endl;
        cout << "----------------------------------------" << endl;
        while (trave != NULL)
        {
            cout << trave->country << " : " << trave->deaths << " " << trave->recovered << " " << trave->active << endl;
            trave = trave->next;
        }
    }
}

void print_Countries_With_High_death_rates()
{
    if (head == NULL)
    {
        cout << "No Data Found !!" << endl;
    }
    else
    {
        Node *trave = head;
        cout << "Countries\t\tDeaths" << endl;
        cout << "----------------------------------------" << endl;
        while (trave != NULL)
        {
            if (trave->deaths > 3000)
            {
                // cout << trave->country;
                printf("\t%-70i\n", trave->deaths);
            }

            trave = trave->next;
        }
    }
}

void deleteNode(int validation)
{

    Node *trave = head;
    while (trave != NULL)
    {
        if (trave->active < validation)
        {
            if (trave == head)
            {
                trave = trave->next;
                trave->prv = NULL;
            }
            else if (trave == tail)
            {
                trave = trave->prv;
                trave->next = NULL;
            }
            else
            {
                trave->prv->next = trave->next;
                trave->next->prv = trave->prv;
            }
        }

        trave = trave->next;
    }
}

int main()
{

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
        stringstream s3(lineData[3]);
        int active;
        s3 >> active;
        // adding data to linked list
        if (lines != 0)
        {
            addNodes(lineData[0], deaths, recovered, active);
        }
        // clearing vector
        lineData.clear();
        lines++;
    }
    int n;
    while (n != 0)
    {

        cout << "\nEnter 01 to print the number of deaths with country : " << endl;
        cout << "Enter 02 to print the number of recoveries with country : " << endl;
        cout << "Enter 03 to print the number of active cases with country : " << endl;
        cout << "Enter 04 to delete : " << endl;
        cout << "Enter 05 to print_Countries_With_High_death_rates :" << endl;
        cout << "Enter : ";
        cin >> n;

        if (n == 1)
        {
            print();
        }
        else if (n == 4)
        {
            cout << "Enter to delete record: ";
            int a;
            cin >> a;
            deleteNode(a);
        }
        else if (n == 5)
        {
            print_Countries_With_High_death_rates();
        }
    }
    //

    return 0;
};