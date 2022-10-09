#include <iostream>
using namespace std;
class stackusingarray{

public:
int stack[10];
int top = -1;

void pop()
{
    if (top != -1)
    {
        top--;
    }
    else
        cout << "underflow error-->stack is empty" << endl;
}
void push(int data)
{
    if (top < 10 - 1)
    {
        top++;
        stack[top] = data;
    }
    else
        cout << "overflow error-->stack is full" << endl;
}
void displaystack()
{
    if (top != -1)
    {
        for (int i = 0; i <= top; i++)
        {
            cout << stack[i] << " ";
            cout << "\n";
        }
    }
    else
    cout<<"stack is empty"<<endl;

}
};
int main(){
    stackusingarray sa;
    sa.push(36);
    sa.push(46);
    sa.push(3);
    sa.push(9);
    sa.pop();
    sa.displaystack();




}
