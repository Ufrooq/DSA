#include <iostream>
using namespace std;

class Heap
{
public:
    int *arr;
    int size;
    Heap(int len)
    {
        arr = new int[len];
        size = 0;
    }

    void insertNode(int val)
    {
        arr[++size] = val;
        int index = size;
        while (index > 1)
        {
            int parent = index / 2;
            if (arr[index] > arr[parent])
            {
                swap(arr[index], arr[parent]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void deleteNode()
    {
        if (size == 0)
        {
            cout << "No data is present for now !!" << endl;
            return;
        }
        else
        {
            arr[1] = arr[size];
            size--;
            // Propogation of root node to its correct position in the Heap -->
            int i = 1;
            while (i < size)
            {
                int leftIndex = 2 * i;
                int rightIndex = (2 * i) + 1;

                if (leftIndex < size && arr[i] < arr[leftIndex])
                {
                    swap(arr[i], arr[leftIndex]);
                    i = leftIndex;
                }
                else if (rightIndex < size && arr[i] < arr[rightIndex])
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

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    Heap hp(100);
    hp.insertNode(50);
    hp.insertNode(55);
    hp.insertNode(53);
    hp.insertNode(52);
    hp.insertNode(54);
    hp.print();
    hp.deleteNode();
    hp.print();
    return 0;
};