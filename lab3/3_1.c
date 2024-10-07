//Lab 3
//Write a program to implement stack using array. In this program you have to implement the stack operation by using the arrays.
#include <stdio.h>
#include <stdbool.h>

// Define the maximim capacity of the stack
#define MAX_SIZE 100

typedef struct {
    int arr[MAX_SIZE];  
    int top;        
} Stack;

void initialize(Stack *st) {
    // Set top index to -1 to indicate an empty stack
    st->top = -1;  
}
bool isEmpty(Stack *st) {
    return st->top == -1;  
}
bool isFull(Stack *st) {
    return st->top == MAX_SIZE - 1;  
}
void push(Stack *st, int value) {
    if (isFull(st)) {
        printf("Stack Overflow\n");
        return;
    }
    // Increment top and add the value to the top of the stack
    st->arr[++st->top] = value;
    printf("Pushed %d onto the stack\n", value);
}

// Function to pop an element from the stack
int pop(Stack *st) {
    if (isEmpty(st)) {
        printf("Stack Underflow\n");
        return -1;
    }
    int popped = st->arr[st->top];
    st->top--;
    printf("Popped %d from the stack\n", popped);
    // return the popped element
    return popped;
}

// Function to peek the top element of the stack
int peek(Stack *st) {
    // Check if the stack is empty
    if (isEmpty(st)) {
        printf("Stack is empty\n");
        return -1;
    }
    // Return the top element without removing it
    return st->arr[st->top];
}

int main() {
    Stack stack;
    initialize(&stack);  

    // Push elements onto the stack and print the stack after each push
    push(&stack, 3);
    printf("Top element: %d\n", peek(&stack));

    push(&stack, 5);
    printf("Top element: %d\n", peek(&stack));

    push(&stack, 2);
    printf("Top element: %d\n", peek(&stack));

    push(&stack, 8);
    printf("Top element: %d\n", peek(&stack));

    // Pop elements from the stack and print the stack after each pop
    while (!isEmpty(&stack)) {
        printf("Top element: %d\n", peek(&stack));
        printf("Popped element: %d\n", pop(&stack));
    }

    return 0;
}
