#include <iostream>
#include <list>
// using namespace std::begin;
using namespace std;

class hashing
{
private:
    int size;
    int *array;

public:
    void hashtable(int n)
    {
        this->size = n;
        array = new int[n];
        cout << "array is of size:" << size << endl;
    }
    void makingArrayNull() // // array have garbage value so we initialize all values of array with -1
    {

        cout << "____WE ARE INITIALIZING ALL ARRAY VALUES TO -1____" << endl;

        for (int i = 0; i < size; i++)
        {
            array[i] = -1;
            cout << "array[" << i << "] => " << array[i] << endl;
        }
    }

    int hashindex(int key)
    {
        return key % size;
    }
    void insertdata(int value)
    {

        int ht = hashindex(value);

        if (array[ht] == -1) //  no collision
        {
            array[ht] = value;
        }
        //      collusion happened
        else
        {
            while (array[ht] != -1)
            { // if index is not empty

                ht = (ht + 1) % size; // move to empty inde
            }
            array[ht] = value;
            ht++;
        }
    }
    int display()
    {

            cout<<"________HASH TABLE  :: CLOSED HASHING________"<<endl;
        for (int i = 0; i < size; i++)
        {
            cout << i << " =>" << array[i] << endl;
        }
        // for (int i = 0; i <size; i++)
        // {
        //     cout << i << "--->";
        //     // array[]::array;
        //     for (int key = array[i].begin(); key!= array[i].end(); ++key)
        //     {
        //         cout << key << " ";
        //     }
        //     cout << endl;
        // }
        // // for (int i = 0; i < size; i++)
        // // {
        // //     cout << i;
        // //     for (auto x : array[i].begin())
        // //         cout << " --> " << x;
        // //     cout << endl;
        // // }

        return 0;
    }
};
int main()
{
    hashing ha;
    ha.hashtable(10);
    ha.makingArrayNull();

    ha.insertdata(101);
    ha.insertdata(1101);
    ha.insertdata(43);
    ha.insertdata(47);
    ha.insertdata(38);
    ha.insertdata(59);
    ha.insertdata(33);
    ha.insertdata(33);
    ha.insertdata(33);
    ha.insertdata(33);
    ha.display();

    return 0;
}