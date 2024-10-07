#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int val;
	struct Node* left;
	struct Node* right;
}Node;

struct Node* delNode(struct Node* root, int x);
struct Node* getSuccessor(struct Node* curr);

Node* newNode(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

Node* insertIntoBST(Node* root, int val) {
    if(root==NULL) return newNode(val);
    else if(val< root->val) root->left=insertIntoBST(root->left,val);
    else if(val> root->val) root->right=insertIntoBST(root->right,val);
    return root; 
}
void inorder(Node* root){
	if(root == NULL) return;
	inorder(root->left);
	printf("%d ",root->val);
	inorder(root->right);
}

int main(){
	Node* root = malloc(sizeof(Node));
	int arr[] = {14, 15, 4, 9, 7, 18, 3, 5, 16, 4, 20, 17, 9, 14, 5, 8, 6};
	int n= sizeof(arr)/sizeof(arr[0]);
	for(int i=0;i<n;i++){
		insertIntoBST(root,arr[i]);
	}
	inorder(root);
	root = delNode(root,14);
	printf("\n");
	inorder(root);
}


// Note that it is not a generic inorder successor
// function. It mainly works when the right child
// is not empty, which is  the case we need in
// BST delete.
struct Node* getSuccessor(struct Node* curr) {
    curr = curr->right;
    while (curr != NULL && curr->left != NULL)
        curr = curr->left;
    return curr;
}

// This function deletes a given val x from the
// given BST  and returns the modified root of 
// the BST (if it is modified)
struct Node* delNode(struct Node* root, int x) {
  
    // Base case
    if (root == NULL)
        return root;

    // If val to be searched is in a subtree
    if (root->val > x)
        root->left = delNode(root->left, x);
    else if (root->val < x)
        root->right = delNode(root->right, x);
    else {
        // If root matches with the given val

        // Cases when root has 0 children or 
        // only right child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }

        // When root has only left child
        if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // When both children are present
        struct Node* succ = getSuccessor(root);
        root->val = succ->val;
        root->right = delNode(root->right, succ->val);
    }
    return root;
}