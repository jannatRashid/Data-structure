#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int IsOperator(char op)
{
    {
        if (op == '^')
            return 3;
        if (op == '*' ||  (op == '/') ||  (op == '%'))
            return 2;
        
        if (op == '+' || (op == '-'))
            return 1;
       
        if (op == '(' || (op == '(') )
            return 4;
        
    }

    return 0;
}
int main()
{
    char infix[10];
    // strcpy(infix, "b-c/d");
    cout<<"enter infix expression:";
    cin>>infix;
    char stack[10];
    int top = -1;
    int j = 0;
    char postfix[10];
    strcpy(postfix, "");

    for (int i = 0; i < strlen(infix); i++)
    {
           if(infix[i] == '(')      
    {  stack[++top] = '(';    continue; }



        if(infix[i] == ')')      
    {    while(stack[top]!=')') 
           postfix[j++] =  stack[top--]; 
         top++;  // to remove ')'
        continue;
    }










        if (IsOperator(infix[i]) == 0)
            postfix[j++] = infix[i];
        else
        {   
            
            if(stack[top] == '(' || top==-1) 
             {  stack[++top] = infix[i] ; continue; }
             // operator



            while (top != -1 && IsOperator(infix[i]) <= IsOperator(stack[top]))
                postfix[j++] = stack[top--];

            stack[++top] = infix[i];
        }
        // if (top == -1 || stack[top] == '(')
        //     stack[top++] = infix[i];
        // else if (infix[i] == ')')
        // {
        //     while (stack[top] != '(')
        //         postfix[j++] = stack[top--];
        // }
    }
    while (top >= 0)
        postfix[j++] = stack[top--];
    postfix[j++] = '\0';
    printf("%s", postfix);
}
