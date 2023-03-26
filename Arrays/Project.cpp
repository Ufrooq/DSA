#include <iostream>
using namespace std;
const int CAPACITY = 5;
struct studentsData
{

    string name;
    string regNo;
    float gpa;
};

// Student info taken function -->
void student_info(studentsData student[], int i)
{
    cout << "\nEnter Details of student : \n";
    cout << "---------------------------------------";
    cout << "\nEnter student name : ";
    cin >> student[i].name;
    cout << "\nEnter student id : ";
    cin >> student[i].regNo;
    cout << "\nEnter student GPA : ";
    cin >> student[i].gpa;
}
//----------------------------->
// Shift LEFT :
void shiftLeft(studentsData arr[], int start, int shifts)
{
    for (int i = start; i <= shifts; i++)
    {
        arr[i - 1] = arr[i];
    }
    cout << "\nElement shifted successfully --->\n";
}
// Shift RIGHT :
void shiftRight(studentsData arr[], int end, int shifts)
{
    for (int i = end; i >= shifts; i--)
    {
        arr[i + 1] = arr[i];
    }
    cout << "\nElement shifted successfully --->\n";
}

// Display Method :
void display(studentsData arr[], int start, int size)
{
    cout << "\nElements in array are : ";
    for (int i = start; i <= size; i++)
    {
        cout << "\n"
             << "Student " << arr[i].regNo << "\n";
    }
    cout << endl
         << "-----------------------" << endl;
}
// !<------------------------------------------------->
// Insert at END Method :
void insertEnd(studentsData arr[], int index_to_insert)
{
    student_info(arr, index_to_insert);
}

// // Insert at START Method :
// void insertStart(studentsData array[], int index_to_insert)
// {
//     cout << "\nEnter Value to insert : ";
//     cin >> array[index_to_insert];
// }

// // Insert at specific index :
// void insertSpecific(studentsData array[], int start, int end, int capacity, int *startAdr, int *EndAdr)
// {
//     bool approve = false;
//     int index;
//     cout << "\nEnter specific value Present in Array : ";
//     cin >> index;
//     for (int i = 0; i <= end; i++)
//     {
//         if (index == array[i])
//         {
//             int value;
//             cout << "\nEnter new value : ";
//             cin >> value;
//             if ((i - start) < (end - i) && start > 0 && end < CAPACITY - 1)
//             {
//                 shiftLeft(array, start, (i - start) + 1);
//                 *startAdr -= 1;
//                 array[i] = value;
//             }
//             else if (start == 0 && end < (CAPACITY - 1))
//             {
//                 shiftRight(array, end, i);
//                 *EndAdr += 1;
//                 array[i] = value;
//             }
//             else if (start > 0 && end == (CAPACITY - 1))
//             {
//                 shiftLeft(array, start, i);
//                 *startAdr -= 1;
//                 array[i] = value;
//             }
//             approve = true;
//             break;
//         }
//     }
//     if (approve != true)
//         cout << "Enter number is not present in te array -- >";
// }
// //!<-------------------------------------------------->

// // Delete at START Method :
// void deleteStart(int array[], int index_to_del, int capacity)
// {
//     array[index_to_del - 1] = index_to_del;
//     cout << "\n Element Deleted --->\n";
// }

// // Update Method :
// void update(studentsData array[])
// {
//     int index, newVal;
//     cout << "Enter index : ";
//     cin >> index;
//     cout << "Enter new Value : ";
//     cin >> newVal;
//     array[index] = newVal;
// }

int main()
{
    int end = -1;
    int start = -1;
    studentsData array[CAPACITY];
    int n;
    while (true)
    {
        cout << "\nPress 1 to insert at END : ";
        cout << "\nPress 2 to insert at START : ";
        cout << "\nPress 3 to insert after specific Value : ";
        cout << "\nPress 4 to delete at END : ";
        cout << "\nPress 5 to delete at START : ";
        cout << "\nPress 6 to delete at RANDOM : ";
        cout << "\nPress 7 to update : ";
        cout << "\nPress 8 to display : ";
        cout << "\nPress 9 to exit() : ";
        cout << "\nStart value is : " << start;
        cout << "\nEnd value is : " << end;
        cout << "\nEnter : ";
        cin >> n;
        if (n == 1)
        {
            if (start == 0 && end == CAPACITY - 1)
                cout << "\nARRAY IS FULL -->\n";
            else
            {
                if (start > 0)
                {
                    shiftLeft(array, start, (end - start) + 1);
                    start -= 1;
                    insertEnd(array, end);
                }
                else
                {
                    insertEnd(array, end + 1);
                    start = 0;
                    end += 1;
                }
            }
        }
        // else if (n == 2)
        // {
        //     if (start == 0 && end == CAPACITY - 1)
        //         cout << "\nARRAY IS FULL -->\n";
        //     else
        //     {
        //         if (start == 0 && end < CAPACITY - 1)
        //         {
        //             shiftRight(array, end, start);
        //             end += 1;
        //             insertStart(array, start);
        //         }
        //         else if (start > 0 && end < CAPACITY - 1)
        //         {
        //             insertStart(array, start - 1);
        //             start -= 1;
        //         }
        //         else if (start > 0 && end == CAPACITY - 1)
        //         {
        //             insertStart(array, start - 1);
        //             start -= 1;
        //         }
        //         else
        //         {
        //             insertStart(array, end + 1);
        //             start = 0;
        //             end += 1;
        //         }
        //     }
        // }
        // else if (n == 3)
        // {
        //     if (start == 0 && end == CAPACITY - 1)
        //         cout << "\nARRAY IS FULL -->\n";
        //     else
        //         insertSpecific(array, start, end, CAPACITY, &start, &end);
        // }

        // else if (n == 4)
        // {
        //     if (end < 0)
        //         cout << "\nARRAY IS EMPTY --->\n";
        //     else
        //     {
        //         end -= 1;
        //         if (end < 0)
        //             start = -1;
        //     }
        // }
        // else if (n == 5)
        // {
        //     if (start > CAPACITY - 1 || start < 0)
        //     {
        //         start = end = -1;
        //         cout << "\nARRAY IS EMPTY --->\n";
        //     }
        //     else
        //     {
        //         start += 1;
        //         cout << "\nElement DELETED --> from Start\n";
        //     }
        // }
        // else if (n == 7)
        // {
        //     if (end < 0)
        //         cout << "\nARRAY IS EMPTY --->\n";
        //     else
        //         update(array);
        // }
        else if (n == 8)
        {
            if (start < 0)
                cout << "\nARRAY IS EMPTY --->\n";
            else
                display(array, start, end);
        }
        else
            break;

        cout << "\nCurrent NO of elements in Array are : " << (end - start) + 1;
    }
    return 0;
};