#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>


struct Stack
{
    char arr[10];
    int tos ;
};

void push(struct Stack *,char);
char pop(struct Stack*);
void convert(char[], char[]);
int isoperand(char);
int isempty(struct Stack);
int precedence(char, char);

int main()
{
    char infix[10];
    char postfix[10];
    printf("Enter the valid infix ");
    scanf("%s",infix);
    convert(infix, postfix);
    printf("the Postfix result is %s",postfix);
    return 0;
}
void convert(char infix[], char postfix[])
{
  int i ,j;
  int result;
  struct Stack S;
  S.tos = -1;
  char ch;

  for(i = 0; infix[i]!= '#'; i++)
  { ch = infix[i];
    if (isoperand(ch)==1)
    {
        postfix[j] == ch;
        j++;
    }
    else
    {
        while(isempty(S) == 0)
        {
            result = precedence(ch, S.arr[S.tos]);
            if(result == 0)
            {
                postfix[j] = pop(&S);
                j++;
            }
            else
            break;
        }
        push(&S, ch);
    }

  } 
    
    while(isempty(S) == 0)
    {
        postfix[j] = pop(&S);
        j++;
    }
    postfix[j] = '#';
    return;
  }

  int isoperand(char ch)
  {
      if((ch >=48 && ch<=57)||(ch >=97 && ch<=122)||(ch>=65 && ch<= 90))
      {
          return 1;

      }
      else
      return 0;
  }

  int isempty(struct Stack S)
  {
      if (S.tos == -1);
      return 1;
    return 0;

  }

  int precedence(char op1, char op2)
  {
      if(op2 == '$')
      return 0;
      else if (op1 == '$')
      return 1;
      else if (op2 =='/'|| op2 == '*'|| op2 == '%')
      return 0;
      else if(op1 =='/'|| op1 == '*'|| op1 == '%')
      return 1;
      else if (op2 =='+'|| op2 =='-')
      return 0;
      else 
      return 1; 
  }

  void push(struct Stack *p, char x)
  {
        if (p->tos == 4)
        {
            return;
        } 
        else
          p->tos = p->tos+1;   
          p->arr[p->tos] = x;

      
  }

  char pop(struct Stack*p)
  {
     int x;
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
