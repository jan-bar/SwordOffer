#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct Stack_t
{
    int data;
    struct Stack_t *next;
}Stack;

int Stack_Pop(Stack **s);
int Stack_Push(Stack **s,int val);
bool Stack_Empty(Stack *s);
int Stack_Top(Stack *s);
void Stack_Print(Stack *s);

#endif // STACK_H_INCLUDED
