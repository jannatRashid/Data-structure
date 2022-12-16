#include <iostream>
using namespace std;
#define S 9

struct node
{
    int d;
    struct node *next;
};

struct node *chain[S];
void array() //initializing array  with null
{
    int i;
    for (int i = 0; i < S; i++)
    {
        chain[i] = NULL;
    }
}
void insert(int value)
{
    struct node *newnode = new node;
    newnode->d = value;
    newnode->next = NULL;

    int key = value % S;

    if (chain[key] == NULL)
    {
        chain[key] = newnode;
    }
    else
    {
        struct node *temp = chain[key];
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}
void dispaly()
{
    for (int i = 0; i < S; i++)
    {
        struct node *temp = chain[i];
        printf("chain[%d]-->", i);
        while (temp)
        {
            printf("%d-->", temp->d);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
int main()
{
    struct node *chain[6];

    array();
    insert(4);
    insert(2);
    insert(16);
    insert(9);
    insert(10);
    insert(19);
    insert(18);
    insert(23);
    dispaly();
    return 0;
}