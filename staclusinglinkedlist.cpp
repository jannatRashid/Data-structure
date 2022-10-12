#include <iostream>
using namespace std;
struct snode
{
    int data;
    struct snode *next;
};
struct snode *top = NULL;

void push(int data )
{

    struct snode *temp = new snode;

    if (temp != NULL)
    {
        temp->data = data;

        temp->next = top;
        top = temp;
        
    }
    else
        cout<<"stack overflow error ";
}
void pop() {
   if(top==NULL)
   cout<<"Stack Underflow"<<endl;
   else {
      cout<<"The popped element is "<< top->data <<endl;
      top = top->next;
   }
}
void displaystack() {
   struct snode* nextptr;
   if(top==NULL)
   cout<<"stack is empty";
   else {
      nextptr = top;
      cout<<"Stack elements are: ";
      while (nextptr != NULL) {
         cout<< nextptr->data <<" ";
         nextptr = nextptr->next;
      }
   }
   cout<<endl;
}
int main()
{
    push(36);
    push(46);

    push(66);

    push(3);

    push(2);
    displaystack();
    pop();
    displaystack();
}