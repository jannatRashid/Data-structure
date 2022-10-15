#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int IsOperator(char op)
{
    {
        if (op == '^')
            return 3;
        if (op == '*' || (op == '/') || (op == '%'))
            return 2;

        if (op == '+' || (op == '-'))
            return 1;

        if (op == '(' || (op == ')'))
            return 4;
    }

    return 0;
}
int main()
{ 
    char infix[15];
    // strcpy(infix, "b-c/d");
    cout<<"enter infix expression:";
    cin>>infix;
    char stack[15];
    int top = -1;
    int j = 0;
    char postfix[15];
    strcpy(postfix, "");

    for (int i = 0; i < strlen(infix); i++)
    {
        if (infix[i] == '(')
        {
            stack[++top] = '(';
           
            continue;
        }
      

        if (infix[i] == ')')
        {
         
            while (stack[top] != '(')
            
                postfix[j++] = stack[top--];
            top--;

            
            
            continue;
           
        }
        if (IsOperator(infix[i]) == 0) // operand
            // {top--;
            postfix[j++] = infix[i];
        else
        { // operator
            if (stack[top] == '(' || top == -1)
            {
                stack[++top] = infix[i];
                // top--;
                continue;
            }
            

            while (top != -1 && IsOperator(infix[i]) <= IsOperator(stack[top]))
                postfix[j++] = stack[top--];
            stack[++top] = infix[i];
            
        } // end of else
    }     // end of loop
    while (top >= 0)
        postfix[j++] = stack[top--];
    postfix[j++] = '\0';
    printf("%s", postfix);
}
