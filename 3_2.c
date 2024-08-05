#include <stdio.h>
#define MAX_SIZE 10

typedef struct {
    int stack[MAX_SIZE];
    int top1;
    int top2;
} TwoStacks;

void initialize(TwoStacks* ts) {
    ts->top1 = -1;
    ts->top2 = MAX_SIZE;
}

int isFull(TwoStacks* ts) {
    return ts->top2 - ts->top1 == 1;
}

int isEmpty1(TwoStacks* ts) {
    return ts->top1 == -1;
}

int isEmpty2(TwoStacks* ts) {
    return ts->top2 == MAX_SIZE;
}

void push1(TwoStacks* ts, int item) {
    if (isFull(ts)) {
        printf("Stack 1 overflow! Cannot push more elements.\n");
    } else {
        ts->stack[++ts->top1] = item;
    }
}

void push2(TwoStacks* ts, int item) {
    if (isFull(ts)) {
        printf("Stack 2 overflow! Cannot push more elements.\n");
    } else {
        ts->stack[--ts->top2] = item;
    }
}
//POP : int item = ts->stack[ts->top2++];
       // printf("Popped %d from Stack 2.\n", item);
       // return item;
int pop1(TwoStacks* ts) {
    if (isEmpty1(ts)) {
        printf("Stack 1 underflow! Cannot pop from an empty stack.\n");
        return -1;
    } else {
        ts->top1--;
        return 1;
    }
}

int pop2(TwoStacks* ts) {
    if (isEmpty2(ts)) {
        printf("Stack 2 underflow! Cannot pop from an empty stack.\n");
        return -1;
    } else {
        ts->top2++;
        return 1;
    }
}

void display1(TwoStacks* ts) {
    if (isEmpty1(ts)) {
        printf("Stack 1 is empty!\n");
    } else {
        printf("Stack 1 elements from top to bottom:\n");
        for (int i = ts->top1; i >= 0; --i) {
            printf("%d\n", ts->stack[i]);
        }
    }
}

// Function to display Stack 2
void display2(TwoStacks* ts) {
    if (isEmpty2(ts)) {
        printf("Stack 2 is empty!\n");
    } else {
        printf("Stack 2 elements from top to bottom:\n");
        for (int i = ts->top2; i < MAX_SIZE; ++i) {
            printf("%d\n", ts->stack[i]);
        }
    }
}

int main() {
    TwoStacks ts;
    initialize(&ts);

    // Push elements into both stacks
    push1(&ts, 10);
    push1(&ts, 20);
    push1(&ts, 30);

    push2(&ts, 40);
    push2(&ts, 50);
    push2(&ts, 60);

    // Display both stacks
    display1(&ts);
    display2(&ts);

    // Pop elements from both stacks
    pop1(&ts);
    pop2(&ts);

    // Display both stacks again
    display1(&ts);
    display2(&ts);

    return 0;
}
