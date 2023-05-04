#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    int *s;
};

int isEmpty(struct Stack *st)
{
    if (st->top == -1)
    {
        printf("Stack is empty!");
        return 1;
    }

    return 0;   // false (not empty)
}

int isFull(struct Stack **st)
{
    if (st->st->top == st->size)
    {
        printf("Stack is full");
        return 1;
    }

    return 0;
}

void push(struct Stack *st, int x)
{
    if (!isFull(&st))
    {
        st->top++;
        st->s[st->top] = x;
    }
}

int pop(struct Stack *st)
{

}

int main()
{
    struct Stack myStack;

    printf("Enter size of stack: ");
    scanf("%d", &myStack.size);
    myStack.s = (int *)malloc(myStack.size * sizeof(int));
    myStack.top = -1;

    push(&myStack, 3);
    push(&myStack, 5);
    push(&myStack, 8);
    push(&myStack, 1);

    free(&myStack);

    return 0;
}
