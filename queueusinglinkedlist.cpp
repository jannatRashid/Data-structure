#include <iostream>
using namespace std;

struct Queuenode
{
    int data;
    Queuenode *next;
    Queuenode(int d)
    {
        data = d;
        next = NULL;
    }
};
struct queue
{
    Queuenode *first, *position;
    queue() { first = position = NULL; }

    void enqueue(int Data)
    {
        Queuenode *temp = new Queuenode(Data);

        if (position == NULL)
        {
            first = position = temp;
            return;
        }
        position->next = temp;
        position = temp;
    }
    void dequeue()
    {
        if (first == NULL)
            return;
        Queuenode *temp = first;
        first = first->next;
        if (first == NULL)
            position = NULL;

        delete (temp);
    }
    void Display()
    {
        struct Queuenode *temp;
        temp = first;
        if ((first == NULL) && (position == NULL))
        {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue elements are: ";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{

    queue q;
    q.enqueue(10);
    q.enqueue(20);
    // q.Display();
    // q.dequeue();
    // q.dequeue();
    q.Display();
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.Display();
    
    q.dequeue();
    q.Display();

    // q.printList(en);

    cout << "Queue first : " << (q.first)->data << endl;

    cout << "Queue position : " << (q.position)->data;
}