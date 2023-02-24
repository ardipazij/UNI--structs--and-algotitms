#ifndef DYNAMIC_STACK_H
#define DYNAMIC_STACK_H
#define RAND_MAX = 32767;
typedef struct stack {
    int data;
    struct stack *next_stack;
} stack;
stack * create();
stack * push(stack ** prev, int data);
int pop(stack **prev);
void delete_stack(stack ** tmp);
void output(stack * temp);
void push_random(stack ** tmp, int n);
void destroy(stack ** root);
void menu(stack ** root);
int is_empty(stack * tmp);
#endif