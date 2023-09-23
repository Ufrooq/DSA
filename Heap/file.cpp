#include <iostream>
using namespace std;

class Heap
{
public:
    int *arr;
    int top;
    Heap(int len)
    {
        arr = new int[len];
        top = -1;
    }

    void insertNode(int val)
    {
        arr[++top] = val;
        int index = top;
        while (index >= 0)
        {
            int parent_of_i = (index - 1) / 2;
            if (arr[index] > arr[parent_of_i])
            {
                swap(arr[index], arr[parent_of_i]);
                index = parent_of_i;
            }
            else
            {
                return;
            }
        }
    }

    void deleteNode()
    {
        if (top == -1)
        {
            cout << "No data to delete for now !" << endl;
        }
        else
        {
            arr[0] = arr[top];
            top--;
            int i = 0;
            while (i < top)
            {
                int leftIndex = (2 * i) + 1;
                int rightIndex = (2 * i) + 2;
                int smallestIndex = min(arr[leftIndex], arr[rightIndex]);
                while (i < top)
                {
                    if ((arr[leftIndex] < arr[top]) && (arr[i] < arr[leftIndex]) && (arr[leftIndex] == smallestIndex))
                    {
                        swap(arr[i], arr[leftIndex]);
                        i = leftIndex;
                    }
                    else if ((arr[rightIndex] < arr[top]) && (arr[i] < arr[rightIndex]) && (arr[rightIndex] == smallestIndex))
                    {
                        swap(arr[i], arr[rightIndex]);
                        i = rightIndex;
                    }
                    else
                    {
                        return;
                    }
                }
            }
        }
    }

    void print()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    Heap hp(100);
    hp.insertNode(20);
    hp.insertNode(30);
    hp.insertNode(40);
    hp.insertNode(25);
    hp.print();
    hp.deleteNode();
    hp.print();
    return 0;
};