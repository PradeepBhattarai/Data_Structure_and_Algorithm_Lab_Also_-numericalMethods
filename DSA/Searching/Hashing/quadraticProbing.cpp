#include <iostream>
using namespace std;

const int SIZE = 10;
/// Quadratic Probing
class HashTable
{
private:
    int *arr;
    int capacity;

public:
    HashTable()
    {
        capacity = SIZE;
        arr = new int[capacity];
        for (int i = 0; i < capacity; i++)
        {
            arr[i] = -1; // initialize all elements to -1
        }
    }

    int hash(int key)
    {
        return key % capacity;
    }

    void insert(int key)
    {
        int hashVal = hash(key);
        int i = 0;
        while (arr[(hashVal + i*i) % capacity] != -1)
        {
            i++;
        }
        arr[(hashVal + i*i) % capacity] = key;
    }

    bool search(int key)
    {
        int hashVal = hash(key);
        int i = 0;
        while (arr[(hashVal + i*i) % capacity] != key)
        {
            if (arr[(hashVal + i*i) % capacity] == -1)
            {
                return false;
            }
            i++;
        }
        return true;
    }

    void remove(int key)
    {
        int hashVal = hash(key);
        int i = 0;
        while (arr[(hashVal + i*i) % capacity] != key)
        {
            if (arr[(hashVal + i*i) % capacity] == -1)
            {
                return;
            }
            i++;
        }
        arr[(hashVal + i*i) % capacity] = -1;
    }

    void display()
    {
        cout << "\n"
             << "Key"
             << "\t"
             << "Value" << endl;
        cout << "________________" << endl;

        for (int i = 0; i < capacity; i++)
        {
            if (arr[i] == -1)
            {
                cout << i << "\t"
                     << "  " << endl;
                cout << "________________" << endl;
            }
            else
            {
                cout << i << "\t" << arr[i] << endl;
                cout << "________________" << endl;
            }
        }
        cout << endl;
    }
};

int main()
{
    HashTable hashTable;

    hashTable.insert(3);
    hashTable.insert(5);
    hashTable.insert(7);
    hashTable.insert(10);
    hashTable.insert(17);
    hashTable.insert(13);
    hashTable.insert(23);
    hashTable.insert(33);
    hashTable.display();

    if (hashTable.search(23))
    {
        cout << "Found 23" << endl;
    }
    else
    {
        cout << "10 not found" << endl;
    }

    hashTable.remove(33);
    hashTable.display();

    return 0;
}

//Similarlly double hashing can be done