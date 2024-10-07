//Write a program  to implement queue using two stacks.
#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum size of the queues

typedef struct {
    int items[MAX];
    int front;
    int rear;
} Queue;

// Function to initialize a queue
void initializeQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is full
int isFull(Queue* q) {
    return (q->rear == MAX - 1);
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return (q->front == -1 || q->front > q->rear);
}

// Function to enqueue an element into the queue
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Cannot enqueue %d\n", value);
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->items[++q->rear] = value;
    }
}

// Function to dequeue an element from the queue
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue\n");
        return -1;
    } else {
        int item = q->items[q->front++];
        if (q->front > q->rear) {
            q->front = q->rear = -1;  // Reset the queue
        }
        return item;
    }
}

// Function to implement stack's push operation
void push(Queue* queue1, Queue* queue2, int value) {
    if (isFull(queue1)) {
        printf("Stack is full! Cannot push %d\n", value);
    } else {
        enqueue(queue1, value);
        printf("Pushed %d\n", value);
    }
}

// Function to implement stack's pop operation
int pop(Queue* queue1, Queue* queue2) {
    if (isEmpty(queue1)) {
        printf("Stack is empty! Cannot pop\n");
        return -1;
    } else {
        while (queue1->front != queue1->rear) {
            enqueue(queue2, dequeue(queue1));
        }
        int item = dequeue(queue1);
        printf("Popped %d\n", item);

        // Swap the roles of queue1 and queue2
        Queue* temp = queue1;
        queue1 = queue2;
        queue2 = temp;

        return item;
    }
}

// Function to display the stack
void displayStack(Queue* queue1, Queue* queue2) {
    printf("Stack: ");
    for (int i = queue1->front; i <= queue1->rear; i++) {
        printf("%d ", queue1->items[i]);
    }
    printf("\n");
}

int main() {
    Queue queue1, queue2;
    initializeQueue(&queue1);
    initializeQueue(&queue2);

    push(&queue1, &queue2, 10);
    push(&queue1, &queue2, 20);
    push(&queue1, &queue2, 30);
    push(&queue1, &queue2, 40);
    push(&queue1, &queue2, 50);
    push(&queue1, &queue2, 60);  // This should display a message that the stack is full

    displayStack(&queue1, &queue2);

    pop(&queue1, &queue2);
    pop(&queue1, &queue2);

    displayStack(&queue1, &queue2);

    push(&queue1, &queue2, 60);

    displayStack(&queue1, &queue2);

    return 0;
}

------------------------------------------------------------------


#include <stdio.h>
#include<stdlib.h>

#define N 100			// size for arrays representing stack1 and stack2

int stack1[N], stack2[N];	// array representing stacks of size N

int top_stack1 = -1;		// top for stack1
int top_stack2 = -1;		// top for stack2

int count = 0;			// For keeping the count of element present in queue

void push_stack1 (int data)
{
  if (top_stack1 == N - 1)
    {
      printf ("Stack1 is overflow");
      return;
    }

  else
    {
      top_stack1++;
      stack1[top_stack1] = data;
    }

  return;
}

void push_stack2 (int data)
{
  if (top_stack2 == N - 1)
    {
      printf ("Stack2 is overflow");
      return;
    }

  else
    {
      top_stack2++;
      stack2[top_stack2] = data;
    }

  return;

}

int pop_stack1 ()
{
  if (top_stack1 == -1)
    {
      printf ("Stack1  underflow\n");
      return -1;
    }

  return stack1[top_stack1--];
}

int pop_stack2 ()
{

  if (top_stack2 == -1)
    {
      printf ("Stack2 is underflow\n");
      return -1;
    }

  return stack2[top_stack2--];

}

void enqueue (int data)
{
  push_stack1 (data);
  count++;

}

void dequeue ()
{
  if (top_stack1 == -1 && top_stack2 == -1)
    printf ("Queue is empty\n");

  else
    {
      for (int i = 0; i < count; i++)
	{

	  int temp = pop_stack1 ();
	  push_stack2 (temp);
	}

      int x = pop_stack2 ();

      printf ("Dequeued element is %d\n", x);
      count--;

      for (int i = 0; i < count; i++)
	{

	  int temp = pop_stack2 ();
	  push_stack1 (temp);

	}
    }
}

void display ()
{
  if (top_stack1 == -1)
    {
      printf ("Queue is empty \n");
      return;
    }

  for (int i = 0; i < top_stack1; i++)
    printf ("%d ", stack1[i]);

  printf ("\n");

}

void top ()
{
  printf ("Top element of queue is %d ", stack1[0]);
}

int main ()
{

  enqueue (3);
  enqueue (45);
  enqueue (-1);

  display ();

  dequeue ();

  display ();

  return 0;

}