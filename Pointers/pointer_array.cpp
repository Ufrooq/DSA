#include <iostream>
using namespace std;
int main()
{
    int arr[10] = {23, 45, 67, 23};
    int *aPointer = arr;
    for (int i = 0; i < 4; i++)
    {
        cout << *aPointer << endl;
        aPointer += 1;
    }

    // aPointer += 2;
    // cout << *aPointer << endl;
    // *aPointer += 3;
    // cout << *aPointer << endl;
    return 0;
};

//! dffffffff
//*sdsdsds
//? sdfsdfsd
// todo sdscsscdffs
