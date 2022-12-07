#include <stdio.h>
#include<stdlib.h>
#define size 10
int ar[size],top=-1;
void push()
{
    int item;
    printf("Enter element\t");
    scanf("%d", &item);
    if (top == size-1)
    {
        printf("Stack is overflow\n");
    }
    else
    {
        top++;
        ar[top] = item;
        printf("item pushed successfully\n");
    }
}

void pop()
{
    if (top == -1)
    {
        printf("stack is underflowed\n");
    }
    else
    {
        int temp;
        temp = ar[top];
        top--;
        printf("%d is popped successfully\n", temp);
    }
}
void peek()
{
    if (top == -1)
    {
        printf("Stack is underflow\n");
    }
    else
    {
        for (int i = top ; i >= 0; i--)
        {
            printf("%d\t", ar[i]);
        }
    }
}
void main()
{
    int c;
    while (1)
    {
        printf("Enter---> 1 for push\t2 for pop\t3for peek\t4 for exit\t");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            printf("Program end\t");
            exit(0);
        default:
            printf("Wrong input\n");
        }
    }
}