#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node* left;
	struct Node* right;
}Node;

Node* createNode(int data) {
	Node* node = malloc(sizeof(Node));
	node->data = data;
	node->right = node->left = NULL;
	return node;
}

Node* createTree(char* post) {
	Node* stack[100];
	int top = -1;

	for(int i = 0;post[i]!='\0';i++) {
		if(isalnum(post[i])) {
			stack[++top] = createNode(post[i]);
		}
		else {
			Node* node = createNode(post[i]);
			node->right = stack[top--];
			node->left = stack[top--];
			stack[++top] = node;
		}
	}
	return stack[top];
}

void printInfix(Node* root) {
	if(root == NULL) return;
	if(root->left) {
		printf("(");
		printInfix(root->left);
	}
	printf("%c",root->data);
	if(root->left) {
		printInfix(root->right);
		printf(")");
	}
}
int main() {
	char post[] = "ab+cd-*";
	Node* root = createTree(post);
	printInfix(root);
}