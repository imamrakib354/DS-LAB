#include<stdio.h>
#include<string.h>
#define MAX 100
char stack[MAX];
int top = -1;

int isEmpty()
{
    if(top == -1)
        return 1;
    else
        return 0;
}
void push(char data)
{
    if(top == MAX-1)
    {
        printf("stack overflow\n");
        return;
    }
    stack[++top]=data;
}
char pop()
{
    if(isEmpty()){
        printf("stack underflow\n");
        exit(1);
    }
    int value = stack[top--];
    return value;
}
int matching_bracket(char a, char b)
{
    if(a=='[' && b==']')
        return 1;
    if(a=='{' && b=='}')
        return 1;
    if(a=='(' && b==')')
        return 1;
    return 0;
}
int check(char* s)
{
    int i; char temp;
    for(i=0; i<strlen(s); i++)
    {
        if(s[i]=='[' || s[i]=='{' || s[i]=='(')
            push(s[i]);
        if(s[i]==']' || s[i]=='}' || s[i]==')')
        {
            if(isEmpty())
            {
                printf("\nInvalid expression\n");
                return 0;
            }
            else
            {
                temp = pop();
                if(!matching_bracket(temp, s[i]))
                   {
                       printf("\nInvalid expression\n");
                       return 0;
                   }
            }
        }
    }
    if(top==-1)
        return 1;
    else
        return 0;
}

int main(){

    char exp[MAX];
    printf("Enter expression: ");
    gets(exp);

    int result = check(exp);
    if(result==1)
        printf("\nValid expression\n");


    return 0;
}
