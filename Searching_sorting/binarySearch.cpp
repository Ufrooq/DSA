#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;
    int mid;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (key == arr[mid])
            return mid;

        else if (key < arr[mid])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}

int main()
{

    int myArray[7] = {12, 34, 45, 63, 78, 98, 114};
    int x;
    cout << "Enter the value to be searched: ";
    cin >> x;
    int ans = binarySearch(myArray, 10, x);
    cout << "------->  " << ans;
    return 0;
};