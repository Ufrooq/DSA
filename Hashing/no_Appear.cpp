#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;

class HashTable
{
public:
    int table[TABLE_SIZE];
    int count;
    HashTable()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            table[i] = -1;
        }
        count = 0;
    }

    int hashFun(int key)
    {
        return key % TABLE_SIZE;
    }

    void insert(int key)
    {
        if (count == TABLE_SIZE)
        {
            cout << "Hash table is full!" << endl;
            return;
        }

        int index = hashFun(key);
        while (table[index] != -1)
        {
            index = (index + 1) % TABLE_SIZE; // Linear probing: move to the next index
        }

        table[index] = key;
        count++;
    }

    void search(int key)
    {
        int index = hashFun(key);
        int originalIndex = index;

        while (table[index] != key)
        {
            if (table[index] == -1 || index == (originalIndex - 1) % TABLE_SIZE)
            {
                cout << "Element not found!" << endl;
                return;
            }

            index = (index + 1) % TABLE_SIZE; // Linear probing: move to the next index
        }

        cout << "Element found at index " << index << endl;
    }

    void display()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            if (table[i] != -1)
            {
                cout << "Index " << i << ": " << table[i] << endl;
            }
        }
    }
};

int main()
{
    HashTable hashTable;

    hashTable.insert(5);
    hashTable.insert(15);
    hashTable.insert(25);
    hashTable.insert(35);
    hashTable.insert(45);

    hashTable.display();

    hashTable.search(15);
    hashTable.search(35);
    hashTable.search(55);

    return 0;
}
