#include <iostream>
using namespace std;
class LinearProbing
{
public:
    int *array;
    int size;
    LinearProbing(int x)
    {
        size = x;
        array = new int[size];
        startUp();
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << array[i] << " ";
        }
        cout << endl;
    }
    void startUp()
    {
        for (int i = 0; i < size; i++)
        {
            array[i] = -1;
        }
    }

    int nextEmptyPlace(int index)
    {
        int i = (index + 1) % size;
        while (array[i] != -1 && i != index)
        {
            i = (i + 1) % size;
        }
        return i;
    }

    int checkIfExist(int index, int no)
    {
        int toReturn = index;
        int i = (index + 1) % size;
        while (array[i] != no && i != index)
        {
            i = (i + 1) % size;
        }
        return i;
    }
    int noOfCollisions(int index)
    {
        int collisons = 0;
        int i = (index) % size;
        while (array[i] != -1)
        {
            collisons++;
            i = (i + 1) % size;
        }
        if (i != index)
        {
            collisons++;
        }
        return collisons;
    }
    void insertion(int value)
    {
        int index = value % size;
        if (array[index] == -1)
        {
            cout << "the number of collions occuring are : "
                 << noOfCollisions(index) << endl;
            array[index] = value;
        }
        else
        {
            int nextPlace = nextEmptyPlace(index);
            if (nextPlace == index)
            {
                cout << "no space available in array" << endl;
            }
            else
            {
                cout << "Total no of colliosons are : " << noOfCollisions(index) << endl;
                array[nextPlace] = value;
            }
        }
    }
    void searching(int n)
    {
        int index = n % size;
        if (array[index] == -1)
        {
            cout << "Value Does not  Exist" << endl;
        }
        else
        {
            if (array[index] == n)
            {
                cout << "Value is at index :" << index << endl;
            }
            else
            {
                int in = checkIfExist(index, n);
                if (in == index || array[in] == -1)
                {
                    cout << "Value Does not Exist" << endl;
                }
                else
                {
                    cout << "Value at index is :" << in << endl;
                    cout << "Value is :" << array[in] << endl;
                }
            }
        }
    }
};
int main()
{
    int size;
    cout << "Enter size of array : " << endl;
    cin >> size;
    LinearProbing l1(size);
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
            l1.insertion(value);
        }
        else if (n == 2)
        {
            l1.display();
        }
        else if (n == 3)
        {
            l1.searching(value);
        }
        else if (n == 0)
        {
            break;
        }
    }
}