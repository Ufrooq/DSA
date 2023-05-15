#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

struct Node
{
    string uniName;
    string location;
    int rank;
    int score_overall;
    Node *next;
    Node *prev;
};

Node *head = nullptr;
Node *tail = nullptr;

// adding nodes
void addNode(string uniName, string location, int rank, int score_overall)
{
    // adding data to new node
    Node *new_node = new Node;
    new_node->uniName = uniName;
    new_node->location = location;
    new_node->rank = rank;
    new_node->score_overall = score_overall;
    new_node->next = nullptr;

    // empty list
    if (head == nullptr)
    {
        head = new_node;
        tail = new_node;
        new_node->prev = nullptr;
    }
    else
    {
        // non-empty
        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
    }
}

// printing info about all universities
void print()
{
    Node *ptr = head;
    cout << "University Name , Location , Rank , Score Overall" << endl;
    if (head != nullptr)
    {
        while (ptr)
        {
            cout << ptr->uniName << " , " << ptr->location << " , " << ptr->rank << " , " << ptr->score_overall << endl;
            ptr = ptr->next;
        }
    }
    else
    {
        cout << "List is empty" << endl;
    }
}

// printing universities info only from a specific location
void print(string location)
{
    Node *ptr = head;
    cout << "University Name , Location , Rank , Score Overall" << endl;
    if (head != nullptr)
    {
        while (ptr)
        {
            if (ptr->location == location)
            {
                cout << ptr->uniName << " , " << ptr->location << " , " << ptr->rank << " , " << ptr->score_overall << endl;
            }
            ptr = ptr->next;
        }
    }
    else
    {
        cout << "List is empty" << endl;
    }
}

// printing universities info with score overall greater than a specific value
void printScoreGreater(int score)
{
    Node *ptr = head;
    cout << "University Name , Location , Rank , Score Overall" << endl;
    if (head != nullptr)
    {
        while (ptr)
        {
            if (ptr->score_overall > score)
            {
                cout << ptr->uniName << " , " << ptr->location << " , " << ptr->rank << " , " << ptr->score_overall << endl;
            }
            ptr = ptr->next;
        }
    }
    else
    {
        cout << "List is empty" << endl;
    }
}
// printing uni overall score greater than specific score function ends here

// delete nodes having movie less than duration d
void deleteLess(int score)
{
    Node *ptr = head;
    while (ptr)
    {
        if (ptr->score_overall < score)
        {
            // deleting
            // one node and head or tail
            if ((ptr == head || ptr == tail) && head == tail)
            {
                head = NULL;
                tail = NULL;
            }
            // multiple nodes and head
            else if (ptr == head)
            {
                head = head->next;
                head->prev = NULL;
            }
            // multiple nodes and tail
            else if (ptr == tail)
            {
                tail = tail->prev;
                tail->next = NULL;
            }
            // neither head nor tail
            else
            {
                ptr->prev->next = ptr->next;
                ptr->next->prev = ptr->prev;
            }
        }
        ptr = ptr->next;
    }
} // deleting nodes function ends here

int main()
{
    // Reading data from file
    std::ifstream fin;
    fin.open("./2011_rankings.csv");
    std::string line, word;
    std::vector<std::string> lineData;
    int lines = 0;

    while (std::getline(fin, line))
    {
        std::stringstream s(line);

        while (std::getline(s, word, ','))
        {
            lineData.push_back(word);
        }

        if (lines != 0)
        {
            // Type casting duration from string to int
            std::stringstream s2(lineData[3]);
            int score_overall;
            s2 >> score_overall;
            std::stringstream s3(lineData[1]);
            int rank;
            s3 >> rank;

            // Adding data to linked list
            addNode(lineData[2], lineData[15], score_overall, rank);
        }

        // Clearing vector
        lineData.clear();
        lines++;
    }

    fin.close();

    // Rest of your code goes here

    // switch to ask user what to do
    int choice = 0;
    do
    {
        std::cout << "\n 1. Print information about all universities" << std::endl;
        std::cout << "2. Print information about universities from a country" << std::endl;
        std::cout << "3. Print information about universities having score overall more than specific score" << std::endl;
        std::cout << "4. Delete universities having score less than a specific score" << std::endl;
        std::cout << "Select an option (enter 0 to exit): ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            print();
            break;
        }
        case 2:
        {
            std::string location;
            std::cout << "Enter location name: ";
            std::cin >> location;
            print(location);
            break;
        }
        case 3:
        {
            int score;
            std::cout << "Enter score: ";
            std::cin >> score;
            printScoreGreater(score);
            break;
        }
        case 4:
        {
            int score;
            std::cout << "Enter score: ";
            std::cin >> score;
            deleteLess(score);
            break;
        }
        default:
        {
            std::cout << "Invalid choice!" << std::endl;
        }
        }
    } while (choice != 0);

    return 0;
}