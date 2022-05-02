#include<stdio.h>
struct Stack
{
    int arr[5];
    int tos;
};

void push(struct Stack *, int);
int main()
{
    int x, i;
    struct Stack s;
    s.tos = -1;

    for(i = 1; i<=6; i++)
    {
        printf("\n Enter the element to push ");
        scanf("%d",&x);
        push(&s,x);
    }
   
    return 0;
}
 void push(struct Stac*p, int x )
{
        if(p-> tos == 4)
        {
            printf("stack overflow");
            return ;
        }
        p-> tos = p-> tos +1;
        p-> arr[p->tos] = x;
        printf("\n pushed element= %d",x);
    }