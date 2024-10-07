#include <stdio.h>
#include <stdlib.h>

void calculateSpan(int prices[], int n, int span[]) {
    // Create a stack to store indices of the prices
    int *stack = (int *)malloc(n * sizeof(int));
    int top = -1;

    // Push the index of the first day onto the stack
    stack[++top] = 0;

    // The span for the first day is always 1
    span[0] = 1;

    for (int i = 1; i < n; i++) {
        // Pop elements from stack while stack is not empty and the current price is greater than price at the stack's top index
        while (top != -1 && prices[stack[top]] <= prices[i]) {
            top--;
        }

        // If stack is empty, it means the current price is the highest seen so far
        // Hence, the span is the number of days from day 0 to day i
        // Otherwise, it's the difference between the current day and the index of the last higher price
        span[i] = (top == -1) ? (i + 1) : (i - stack[top]);

        // Push the current day's index onto the stack
        stack[++top] = i;
    }

    // Free the stack memory
    free(stack);
}

// Function to print the span values
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Sample input prices
    int prices[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(prices) / sizeof(prices[0]);

    // Array to store the span of each day
    int span[n];

    // Calculate the span values
    calculateSpan(prices, n, span);

    // Print the result
    printf("Span values for the stock prices are:\n");
    printArray(span, n);

    return 0;
}
