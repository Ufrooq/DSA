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
        while (index > 0)
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
                while (i < top)
                {
                    if (leftIndex < top && arr[i] < leftIndex)
                    {
                        swap(arr[i], arr[leftIndex]);
                        i = leftIndex;
                    }
                    else if (rightIndex < top && arr[i] < rightIndex)
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
    hp.insertNode(60);
    hp.insertNode(50);
    hp.insertNode(55);
    hp.insertNode(59);
    hp.insertNode(75);
    hp.print();
    hp.deleteNode();
    hp.print();
    return 0;
};