#include <iostream>
#include <list>
using namespace std;
class HashTable
{
private:
    static const int table_size = 10; // size of the hash table
    list<int> table[table_size]; // array of lists for separate chaining

    int hash(int key)
    { 
        return key % table_size;
    }

public:
    void insert(int key)
    {
        int index = hash(key);       // compute index for key
        table[index].push_back(key); // add key to the list at index
    }

    void remove(int key)
    {
        int index = hash(key);    // compute index for key
        table[index].remove(key); // remove key from the list at index
    }

    bool search(int key)
    {
        int index = hash(key); // compute index for key
        for (auto it = table[index].begin(); it != table[index].end(); ++it)
        {
            if (*it == key)
            {
                return true; // key found in list at index
            }
        }
        return false; // key not found in table
    }

    void display()
    {
        for (int i = 0; i < table_size; ++i)
        {
            cout << i << ": ";
            for (auto it = table[i].begin(); it != table[i].end(); ++it)
            {
                cout << *it << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    HashTable ht;
    ht.insert(5);
    ht.insert(15);
    ht.insert(25);
    ht.insert(6);
    ht.insert(16);
    ht.insert(26);
    ht.insert(2);
    ht.insert(22);
    ht.display();
// output: 0: 10: 5 15 25
//         1: 6 16 26
//         2:
//         3:
//         4:
//         5:
//         6:
//         7:
//         8:
//         9:
    ht.remove(15);
    ht.remove(16);
    cout << "After removal" <<endl;
    cout << "____________" <<endl;
    ht.display();                            
// output: 0: 10: 5 25
//         1: 6 26
//         2:
//         3:
//         4:
//         5:
//         6:
//         7:
//         8:
//         9:
    cout << ht.search(5) <<endl;  // output: 1 (true)
    cout << ht.search(16) <<endl; // output: 0 (false)
    return 0;
}
