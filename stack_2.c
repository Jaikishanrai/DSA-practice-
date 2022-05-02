#include<stdio.h>
#include<stdlib.h>

struct Stack
{
    int arr[5];
    int tos;
};
void push(struct Stack*, int);
int pop(struct Stack*);

int main()
{   struct Stack s;
    int x;
    int choice;
    s.tos = -1;

    do
    {
        printf("\n Select an operation : ");
        printf("\n1. Push\n2. Pop\n3. Quit");
        printf("\n Enter your choice : ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter element to push : ");
            scanf("%d",&x);
            push(&s,x);
            break;

         case 2:
            x = pop(&s);
            printf("\n Popped element = %d",x);
            break;

        case 3:
            printf("\nThank you for using this app");
            break;    
        
        default:
            printf("\nWrong choice ! Try again..........");
            break;
        }
    }
    while(choice != 3);
    return 0;
}

void push(struct Stack*p, int x)
{
    if(p ->tos == 4)
    {
        printf("\nStack Overflow");
        return;
    }
    p ->arr[++p ->tos] = x;
    printf("\nPushed Element %d at index %d :",x, p ->tos);
}

int pop(struct Stack*p)
{
    if(p ->tos == -1)
    {
        printf("\n Stack Underflow");
    }
    return p ->arr[p ->tos--];
}
