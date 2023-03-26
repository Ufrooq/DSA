#include <iostream>
using namespace std;
int main()
{

    int n = 7;
    int count = 5;
    for (int k = 0; k < n; k++)
    {
        if (k < 3)
        {
            for (int i = 0; i <= k; i++)
            {
                cout << "* ";
            }
        }
        else
        {
            for (int j = count; j > 1; j--)
            {
                cout << "* ";
            }
            count -= 1;
        }

        cout << endl;
    }
    return 0;
}
