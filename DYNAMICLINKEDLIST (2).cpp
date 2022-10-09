#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};

void printList(Node *n)
{
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
}
int main()
{
    int value;
    
    struct Node *head;
    head = NULL;
    struct Node *temp;
    for (int i = 0; i < 5; i++)
    {
        cout << "enter data";
        cin >> value;
        temp = new Node;
        temp->data = value;
        // temp->next = NULL;

        temp->next = head;
        head = temp;
        
    }
        
    printList(temp);
    return 0;
};