#include <iostream>
using namespace std;

void merge(int *arr, int start, int end)
{
    int mid = start + (end - start) / 2;
    int len1 = mid - start + 1;
    int len2 = end - mid;

    int *firstArray = new int[len1];
    int *secondArray = new int[len2];

    int f = start;
    for (int i = 0; i < len1; i++)
    {
        firstArray[i] = arr[f++];
    }
    int s = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        secondArray[i] = arr[s++];
    }

    int index1 = 0;
    int index2 = 0;

    int mainArrayIndex = start;
    while (index1 < len1 && index2 < len2)
    {
        if (firstArray[index1] < secondArray[index2])
        {
            arr[mainArrayIndex++] = firstArray[index1++];
        }
        else
        {
            arr[mainArrayIndex++] = secondArray[index2++];
        }
    }

    while (index1 < len1)
    {

        arr[mainArrayIndex++] = firstArray[index1++];
    }
    while (index2 < len2)
    {
        arr[mainArrayIndex++] = secondArray[index2++];
    }
}

void mergeSort(int *arr, int start, int end)
{
    if (start >= end)
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
            {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
}

void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int temp = arr[i];
        int j;
        for (j = i - 1; j >= 0; j--)
        {
            if (arr[j] > temp)
            {
                arr[j + 1] = arr[j];
            }
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
        for (int j = 0; j < s - i - 1; j++)
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

    int arr[7] = {6, 3, 1, 5, 71, 89, 8};
    int size = 7;
    // mergeSort(arr, 0, size - 1);
    // insertionSort(arr, size);
    selectionSort(arr, size);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
};