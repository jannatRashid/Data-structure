#include <iostream>
using namespace std;

struct Queue {
    int first, position, capacity;
    int* queue;
    Queue(int c)
    {
        first = position = 0;
        capacity = c;
        queue = new int;
    }
 
    void enqueue( int data)
    {

        if (capacity == position)
        {
            cout << "overflow error" << endl;
            return;
        }
        else
        {
            queue[position] = data;
            position++;
        }
        return;
    }
    void dequeue()
    {
        if (first == position)
        {
            cout << "underflow error-->queue is empty" << endl;
            return;
        }
        else
        {
            for (int i = 0; i < position - 1; i++)
            {
                queue[i] = queue[i + 1];
            }
            position--;
        }
        return;
    }
    void displayqueue()
    {
        
        if (first == position)
        {
            printf("\nQueue is Empty\n");
            return;
        }
        else
        {

            // traverse front to rear and print elements
            for (int i = first; i < position; i++)
            {
                printf(" %d <-- ", queue[i]);
                // cout<<"<--"<<queue[i]<<endl;
            }
            return;
        }
    }

    void queueFront()
    {
        if (first == position)
        {
            printf("\nQueue is Empty\n");
            return;
        }
        printf("\nFront Element is: %d", queue[first]);
        return;
    }
};
int main()
{

   Queue q(5);

    // queueusingaray q;
    q.displayqueue();
    q.enqueue( 36);
    q.enqueue( 6);

    q.enqueue( 3);
    q.enqueue( 44);
    q.enqueue( 55);
    q.displayqueue();
    cout<<endl;
    q.enqueue( 66);

    q.dequeue();
    // q.displayqueue();
    q.dequeue();
    cout<<endl<<"after deleting 2 nodes"<<endl;
    q.displayqueue();
}