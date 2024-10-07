#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct Node{
	int data;
	struct Node* left;
	struct Node* right;
	int height;
}Node;

int height(Node* node){
	if(node == NULL) return 0;
	return node->height;
}

Node* newNode(int data) {
	Node* new = malloc(sizeof(Node));
	new->data= data;
	new->left = new->right = NULL;
	new->height = 1;
	return new;
}

Node* rightRotate(Node* x) {
	Node* y = x->left;
	Node* T2 = y->right;

	y->right = x;
	x->left = T2;

	return y;
}

Node* leftRotate(Node* x) {
	Node* y = x->right;
	Node* T2 = y->left;

	y->left = x;
	x->right = T2;

	return y;
}

int getBalance(Node* node) {
	if(node == NULL) return 0;
	return height(node->left) - height(node->right);
}

int minval(Node* root){
	int min;
	while(root->left){
		root=root->left;
	}
	return root->data;
}

Node* balanceAVL(Node* node) {
	int balance = getBalance(node);

	if(balance > 1 && getBalance(node->left) >= 0)
		return rightRotate(node);
	
	if(balance >1 && getBalance(node->left) < 0) {
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	if(balance < -1 && getBalance(node->right) <= 0)
		return rightRotate(node);

	if(balance < -1 && getBalance(node->right) > 0) {
		node->right = rightRotate(node->right);
		return leftRotate(node->left);
	}

	return node;

}

Node* insert(Node * node, int key) {
	if(node == NULL) 
		return newNode(key);
	if(key < node->data)
		node->left = insert(node->left,key);
	else if(key > node->data)
		node->right = insert(node->right,key);
	else 
		return node;
	node->height = 1 + fmax(height(node->left), height(node->right));
	return balanceAVL(node);
}

Node* delete(Node* root,int key) {
	if(root == NULL) 
		return root;
	if(root->data < key) 
		root->right = delete(root->right,key);
	else if(root->data > key) 
		root->left = delete(root->left,key);
	else {
		if(root->left == NULL || root->right == NULL) {
			Node* temp = root->left == NULL ? root->right : root->left;
			if(temp == NULL) {
				temp = root;
				root = NULL;
			}
			else 
				*root = *temp;

			free(temp);
		}
		else {
			int min = minval(root->right);
			root->data = min;
			root->right = delete(root->right,min);
		}
	}

	if(root == NULL)
		return root;

	root->height = 1+fmax(height(root->left),height(root->right));
	return balanceAVL(root);
}

void preOrder(struct Node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
  struct Node *root = NULL;

    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, -1);
    root = insert(root, 1);
    root = insert(root, 2);

    printf("Preorder traversal of the constructed AVL "
           "tree is \n");
    preOrder(root);

    root = delete(root, 10);

    printf("\nPreorder traversal after deletion of 10 \n");
    preOrder(root);

    return 0;
}