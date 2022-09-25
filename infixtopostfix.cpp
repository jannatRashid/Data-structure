#include<iostream>
#include<string.h>
using namespace std;

int precedence(char op) 
{ 
    if(op == '^') 
    return 3; 
    else if(op == '*' || op == '/') 
    return 2; 
    else if(op == '+' || op == '-') 
    return 1; 
    else
    return 0; 
} 

int main()

{
    char stack[10];
    int top=-1;
    int j=0;

    char infix[10];
    strcpy(infix,"a+b");

    char postfix[10];
    strcpy(postfix," ");

    for (int i = 0; i < strlen(infix); i++)
    {
        if (precedence(infix[i]==0))
        {
            postfix[j++]=infix[i];
        }
        else if (stack[++top]==infix[i])
        {
            
        }
        
    }
    postfix[j++]=stack[top--];
    postfix[j++]='\0';
    printf("%s",postfix);
    

        return 0;
}
