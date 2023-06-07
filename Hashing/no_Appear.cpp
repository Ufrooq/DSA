#include <iostream>
using namespace std;
int main()
{

    int n;
    cout << "Enter size of Array : ";
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int *hash = new int[n + 1];
    fill(hash, hash + n, 0);
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]] += 1;
    }

    for (int i = 0; i < n; i++)
    {
        if (hash[i] != 0)
        {
            cout << i << " appears --> " << hash[i] << " times" << endl;
        }
    }

    return 0;
};