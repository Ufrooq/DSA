#include <iostream>
using namespace std;

void firstGreater(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (array[i] < array[j])
            {
                cout << array[i] << "  -->  " << array[j] << endl;
                break;
            }
            else if (j == size - 1 && array[i] > array[j])
            {
                cout << array[i] << "  -->  -1" << endl;
                break;
            }
        }
        if (i == size - 1)
        {
            cout << array[i] << "  -->  -1" << endl;
        }
    }
}

void findGreatest(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        int current = array[i];
        int current_freq = 0;
        for (int j = 0; j < size - j; i++)
        {
            if (current == array[j])
            {
                current_freq++;
            }
        }

        if (i == size - 1)
        {
            cout << array[i] << "  -->  -1" << endl;
        }
    }
}

int main()
{
    int size = 4;
    int *array = new int[size];
    for (int i = 0; i < size; i++)
    {
        cout << "\nEnter :";
        cin >> array[i];
    }

    firstGreater(array, size);
    return 0;
};