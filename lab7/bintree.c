#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef struct node{
    int data;
    struct node* left;
    struct node*right;
}node;
node* newnode(int data) {
    node* temp = malloc(sizeof(node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
int countnodes(node* root){
    if(root == NULL) return 0;
    return 1 + countnodes(root->left) + countnodes(root->right);
}
void preorder(node* root) {
    if(root == NULL) return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(node* root) {
    if(root == NULL) return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
void postorder(node* root) {
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}
int isfullbin(node* root){
    if(root == NULL) return 1; 
    if(root->left == NULL && root->right == NULL) return 1;
    if(root->left && root->right){
        return isfullbin(root->left) && isfullbin(root->right); 
    }
    return 0;
}
int iscomplete(node* root,int index,int totalnodes){
    if(root == NULL) return 1;
    if(index >= totalnodes)
        return 0;
    return iscomplete(root->left,2*index+1,totalnodes)&&iscomplete(root->right,2*index+2,totalnodes);
}
int iscompletebinary(node* root){
    int totalnodes = countnodes(root);
    return iscomplete(root,0,totalnodes);
}

int countleaf(node* root){
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return 1;
    return countleaf(root->left) + countleaf(root->right); 
}

int bintreesum(node* root){
    if(root == NULL) return 0;
    return root->data + bintreesum(root->left) + bintreesum(root->right);
}

int findmax(node* root){
    if(root == NULL) return INT_MIN;
    int leftmax = findmax(root->left);
    int rightmax = findmax(root->right);
    int max = root-> data;
    if(leftmax > max) max = leftmax;
    if(rightmax > max) max = rightmax;
    return max;
}

int height(node* root){
    if(root == NULL) return -1;
    int leftheight = height(root->left);
    int rightheight = height(root->right);
    return (leftheight > rightheight ? leftheight : rightheight) + 1;
}

int main() {
    node* root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    root->right->left = newnode(6);
    root->right->right = newnode(7);
    root->left->left->left = newnode(8);
    root->left->left->right = newnode(9);
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    printf("Full binary tree: %s\n",(isfullbin(root))?"Yes":"No");
    printf("No. of nodes: %d\n",countnodes(root));
    printf("complete binary tree : %d\n",iscompletebinary(root));
    printf("no. of leaf nodes :%d\n",countleaf(root));
    printf("sum :%d\n",bintreesum(root));
    printf("max element :%d\n",findmax(root));
    printf("height :%d\n",height(root));
}