#include <iostream>
using namespace std;

void merge(int *arr, int start, int end)
{
    int mid = start + end / 2;
    int len1 = mid - start + 1;
    int len2 = end - mid;

    int *firstArray = new int[len1];
    int *secondArray = new int[len2];
}
void mergeSort(int *arr, int start, int end)
{
    if (start > end)
    {
        return;
    }
    int mid = (start + end) / 2;
    // sort left part -->
    mergeSort(arr, start, mid);

    // sort right part -->
    mergeSort(arr, mid + 1, end);

    merge(arr, start, end);
}

void selectionSort(int arr[], int s)
{
    for (int i = 0; i < s - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < s; j++)
        {
            if (arr[j] < arr[min])
                swap(arr[j], arr[min]);
        }
    }
}

void insertionSort(int arr[], int size)
{

    for (int i = 1; i < size; i++)
    {
        int temp = arr[i];
        int j;
        for (j = i - 1; j >= 0; j++)
        {
            if (arr[j] > temp)
                arr[j + 1] = arr[j];
            else
                break;
        }
        arr[j + 1] = temp;
    }
}

void bubbleSort(int arr[], int s)
{
    for (int i = 0; i < s - 1; i++)
    {
        for (int j = 0; j < s - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main()
{

    int arr[10] = {34, 6, 4, 3, 7, 9, 14, 22, 23, 31};
    int size = 10;
    insertionSort(arr, size);
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
};