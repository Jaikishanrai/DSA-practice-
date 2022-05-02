#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

struct Stack
{
    float arr[10];
    int tos;
};

void push(struct Stack *, float);
float pop(struct Stack *);
float solve(char[]);
int isoperand(char);
float calculate(float, float, char);

int main()
{
    char postfix[20];
    float ans;
    printf("\n Enter a valid postfix expression ");
    scanf("%s", postfix);
    ans = solve(postfix);
    printf("\n Solution of the given postfix is %f", ans);
    return 0;
    
}

float solve(char postfix[20])
{
    struct Stack S;
    S.tos = -1;
    float op1, op2, result;
    int i;
    char ch;
    
    for(i = 0; postfix[i]!='@'; i++)
    {    ch = postfix[i];
        if(isoperand(ch) == 1)
        {
            push(&S,ch-48);
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
    if(ch>= 48 && ch<= 57)
    return 1;
    else
    return 0;
}

float calculate(float op1, float op2, char op)
{
    switch (op)
    {
    case '+':
              return op1 + op2;
        
     case '-':
              return op2 - op1;

     case '*':
              return op1 * op2;

     case '/':
              return op2/op1;

     case '$':
              return pow(op1,op2);

     case '%':
              return fmod(op1,op2);                              

    default:
              return 0.0;
        
    }
}

void push(struct Stack *p, float x)
{
    if (p -> tos == 4)
    {
    printf("\n Stack overflow");
    return;
    }
    else
    {
        p-> tos = p->tos + 1;
        p->arr[p->tos] = x;
        printf("\n Pushed element %f",x);
    }
}

float pop(struct Stack *p)
{
    float x;

    if(p-> tos == -1)
    {
        printf("/n Stack underflow");
        return -1;

    }
    else
    {
      x = p->arr[p->tos];

      p-> tos = p->tos -1;
      return x;

    }
}