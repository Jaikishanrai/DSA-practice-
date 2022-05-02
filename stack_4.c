#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

struct Stack
{
    float arr[10];
    int tos;
};

void push(struct Stack*, float);
float pop(struct Stack*);
float solve(char[]);
int isoperand( char);
float calculate(float, float , char);

int main()
{
    char prefix[20];
    float ans;
    printf("\n Enter a valid Prefix -");
    scanf("%s",prefix);
    ans = solve(prefix);
    printf("\n Solution of the given Prefix is %f", ans);
    return 0;
}

float solve(char prefix[])
{
    struct Stack S ;
    S.tos =-1;
    int i;
    float op1, op2, result;
    char ch;

    for(i =strlen(prefix)-1; i>=0; i--)
    {    ch = prefix[i];
        if (isoperand(ch) == 1)
        {
            push(&S, ch-48);
        }
        else
        {
            op1 = pop(&S);
            op2 = pop(&S);
            result = calculate(op1, op2, ch);
            push(&S,result);
        }
        

    }
    result = pop(&S);
    return result;
    
}

int isoperand(char ch)
{
    if(ch>=48 && ch<=57)
    return 1;
    else
    return 0;
}

float calculate(float op1, float op2, char op)
{
    switch(op)
    {
        case '+':
                 return op1 + op2;

         case '-':
                 return op1 - op2;

        case '*':
                 return op1 * op2;

         case '/':
                 return op1 / op2;

         case '$':
                 return pow(op1,op2);

         case '%':
                 return fmod(op1,op2);

        default :
                 return 0.0;         

    }
}

void push(struct Stack *p, float x)
{
    if(p->tos == 4)
    {
        return;
    }
    else
    p->tos = p->tos+1;
    p->arr[p->tos] = x;
}

float pop(struct Stack *p)
{   int x;
    if(p->tos == -1)
    {
        printf("\nStack Underflow");
        return -1;

    }
    else
    x = p->arr[p->tos];
    p->tos = p->tos-1;
    return x;
}

