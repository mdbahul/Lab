#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Node;

bool isIdentical(Node* node1, Node* node2){
    // If both nodes are NULL,
    // they are identical
    if(node1 == NULL && node2 == NULL){
        return true;
    }
    // If only one of the nodes is
    // NULL, they are not identical
    if( node1== NULL || node2==NULL){
        return false;
    }
    // Check if the current nodes
    // have the same data value
    // and recursively check their
    // left and right subtrees
    return ((node1->data == node2->data)
        && isIdentical(node1->left, node2->left)
            && isIdentical(node1->right, node2->right));
}

Node* createNode(int data){
    Node* node = malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int main() {
    // Node1
    Node* root1 = createNode(1);
    root1->left = createNode(2);
    root1->right = createNode(3);
    root1->left->left = createNode(4);

    // Node2
    Node* root2 = createNode(1);
    root2->left = createNode(2);
    root2->right = createNode(3);
    root2->left->left = createNode(4);
    
    if (isIdentical(root1, root2)) {
        printf("The binary trees are identical.\n" );
    } else {
        printf("The binary trees are not identical.\n");
    }

    return 0;
}
                            
                        