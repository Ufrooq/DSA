#include <iostream>
using namespace std;

struct studentsData
{

    string name;
    string regNo;
    float gpa;
};

void update(studentsData student[])
{
}
int main()
{

    studentsData student[10];
    for (int i = 0; i < 5; i++)
    {
        cout << "\nEnter Details of student " << i + 1 << " :\n";
        cout << "---------------------------------------";
        cout << "\nEnter student name : ";
        cin >> student[i].name;
        cout << "\nEnter student id : ";
        cin >> student[i].regNo;
        cout << "\nEnter student GPA : ";
        cin >> student[i].gpa;
    }
    update(student);
    // for (int i = 0; i < 5; i++)
    // {
    //     cout << "\n----------------------------------------------\n";
    //     cout << "\nDetails of student " << i + 1 << " :\n";
    //     cout << "Studet Name : " << student[i].name;
    //     cout << "Studet Name : " << student[i].regNo;
    //     cout << "Studet Name : " << student[i].gpa;
    //     cout << "\n----------------------------------------------\n";
    // }

    return 0;
};