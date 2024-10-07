//stack using ll
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;
node *head = NULL;

int isEmpty() {
    return head == NULL;
}

void push(int data) {
  
    node* temp = malloc(sizeof(node));
    temp->data = data;

    temp->next = head;
    head = temp;
}

int pop() {
    node *temp = head;
    if (isEmpty()) {
        printf("\nStack Underflow\n");
        exit(1);
    }
    int top = head->data;
    head = head->next;
    free(temp);
    return top;
}

int top() {
    if (isEmpty()){
        printf("\nStack is empty");
        exit(1);
    }
    return head->data;
}

void display(){
    node *temp = head;
    if(isEmpty()){
        printf("Stack Empty\n");
        exit(1);
    }
    while(temp){
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {

    push(11);
    push(22);
    push(33);
    push(44);
    display();

    // Print top element of the stack
    printf("Top element is %d\n", top());

    printf("Removing two elements...\n");
    pop();
    pop();
    display();
    printf("Top element is %d\n", top());
    printf("%d",(-49)%50);
    return 0;
}