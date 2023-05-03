#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

struct Node
{
    string movieName;
    string director;
    int duration;
    string country;
    Node *next;
    Node *prev;
};

struct Node *head = NULL;
struct Node *tail = NULL;

//adding nodes
void addNode(string movieName , string director , int duration , string country)
{
    //adding data to new node
    Node *new_node = new Node;
    new_node->movieName = movieName;
    new_node->director = director;
    new_node->duration = duration;
    new_node->country = country;
    new_node->next = NULL;
    //empty list
    if(head == NULL)
    {
        head = new_node;
        tail = new_node;
        new_node->next = NULL;
        return;
    }
    //non empty
    new_node->prev = tail;
    tail->next = new_node;
    tail = new_node;
}//adding node function ends here

//printing info about all movies
void print()
{
    Node *ptr = head;
    cout << "Movie Name , Director , Duration , Country" << endl;
    if (head!=NULL)
    {
       while (ptr)
       {
           cout<<ptr->movieName<<" , "<<ptr->director<<" , "<<ptr->duration<<" , "<<ptr->country<< endl;
           ptr=ptr->next;
       }
    }
   else
    {
       cout << "List is empty"<<endl;
    }
}//printing function ends here

//printing movies info only from a specific country
void print(string country)
{
    Node *ptr = head;
    cout << "Movie Name , Director , Duration , Country" << endl;
    if (head!=NULL)
    {
        while (ptr)
        {
            if(ptr->country==country)
            {
                cout<<ptr->movieName<<" , "<<ptr->director<<" , "<<ptr->duration<<" , "<<ptr->country<< endl;
            }
            ptr=ptr->next;
        }
    }
    else
    {
       cout << "List is empty"<<endl;
    }
}//printing movie of a country function ends here

//printing movies info with duration greater than d minutes
void printDurationGreater(int d)
{
    Node *ptr = head;
    cout << "Movie Name , Director , Duration , Country" << endl;
    if (head!=NULL)
    {
        while (ptr)
        {
            if(ptr->duration>d)
            {
                cout<<ptr->movieName<<" , "<<ptr->director<<" , "<<ptr->duration<<" , "<<ptr->country<< endl;
            }
            ptr=ptr->next;
        }
    }
    else
    {
       cout << "List is empty"<<endl;
    }
}//printing movie greater than duration function ends here

//delete nodes having movie less than duration d
void deleteLess(int d)
{
    Node *ptr = head;
    while (ptr)
    {
        if(ptr->duration<d)
        {
            //deleting
            //one node and head or tail
            if((ptr==head||ptr==tail) && head==tail)
            {
                head=NULL;
                tail=NULL;
            }
            //multiple nodes and head
            else if(ptr==head)
            {
                head=head->next;
                head->prev=NULL;
            }
            //multiple nodes and tail
            else if(ptr==tail)
            {
                tail=tail->prev;
                tail->next=NULL;
            }
            //neither head nor tail
            else
            {
                ptr->prev->next=ptr->next;
                ptr->next->prev=ptr->prev;
            }
        }
        ptr=ptr->next;
    }
}//deleting nodes function ends here

int main()
{
    //reading data from file
    ifstream fin;
    fin.open("IMDB_5000.csv");
    string line, word;
    vector<string> lineData;
    int lines = 0;
    while(!fin.eof()){
        //reading data and adding to vector
        getline(fin,line);
        stringstream s(line);
        while(getline(s,word,',')){
            lineData.push_back(word);
        }
        //type casting duration from string to int
        stringstream s2(lineData[3]);
        int duration;
        s2>>duration;
        //adding data to linked list
        if(lines!=0)
        {
            addNode(lineData[11],lineData[1],duration,lineData[20]);
        }
        //clearing vector
        lineData.clear();
        lines++;
    }
    //switch to ask user what to do
    int choice = 0;
    do
    {
        cout<<"\n 1.Print information about all movies"<<endl;
        cout<<"2.Print information about movies from a country"<<endl;
        cout<<"3.Print information about movies having duration more than specific time in minutes"<<endl;
        cout<<"4.Delete movies having duration less than a specific time in minutes"<<endl;
        cout<< "Select an option and 0 to exit:";
        cin>>choice;
        switch(choice)
        {
            case 1 :
            {
                print();
                break;
            }
            case 2 :
            {
                string country;
                cout<<"Enter country name:";
                cin>>country;
                print(country);
                break;
            }
            case 3 :
            {
                int duration;
                cout<<"Enter duration (minutes):";
                cin>>duration;
                printDurationGreater(duration);
                break;
            }
            case 4 :
            {
                int duration;
                cout<<"Enter duration (minutes):";
                cin>>duration;
                deleteLess(duration);
                break;
            }
            default :
            {
                cout<<"Invalid choice!"<<endl;
            }
        }
    }
    while(choice!=0);
    return 0;
}
