#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Node structure for the expression tree
typedef struct Node {
    char data;
    struct Node *left;
    struct Node *right;
} Node;

// Function to create a new node
Node* newNode(char val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Function to construct the expression tree
Node* constructTree(char* postfix) {
    Node* stack[100];
    int top = -1;

    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isalnum(postfix[i])) {
            // Operand, create a new node
            stack[++top] = newNode(postfix[i]);
        } else {
            // Operator, create a new node with children from stack
            Node* op = newNode(postfix[i]);
            op->right = stack[top--];
            op->left = stack[top--];
            stack[++top] = op;
        }
    }

    return stack[top];
}

// Function to print infix expression with brackets
void printInfix(Node* root) {
    if (root != NULL) {
        if (root->left) {
            printf("(");
            printInfix(root->left);
        }
        printf("%c", root->data);  // Print the root data only once
        if (root->right) {
            printInfix(root->right);
            printf(")");
        }
    }
}


int main() {
    char postfix[] = "ab+c+d*e/";  // Example postfix expression

    printf("Infix expression: ");
    Node* root = constructTree(postfix);
    printInfix(root);
    printf("\n");

    return 0;
}