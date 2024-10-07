#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;
// node *head = NULL;

int isEmpty(node* head) {
    return head == NULL;
}

//circular ll
// void insert_ll(node* head,int data){
// 	node *temp = malloc(sizeof(node));

// 	temp->data = data;
//     // temp->next = NULL; not necessary cuz mycode creates a node and links to itself

//     if(head == NULL){
//         head = temp;
//     }
//     else {
//         node *ptr = head;
//         while(ptr->next != head){
// 		    ptr=ptr->next;
// 	    }
// 	    ptr->next = temp;
//     }
//     temp->next = head;
// }

void insert_ll(node** head,int data){
	node *temp = malloc(sizeof(node));

	temp->data = data;
    // temp->next = NULL; not necessary cuz mycode creates a node and links to itself

    if(head == NULL){
        *head = temp;
    }
    else {
        node *ptr = *head;
        while(ptr->next != *head){
		    ptr=ptr->next;
	    }
	    ptr->next = temp;
    }
    temp->next = *head;
    
}

void display(node* head){
    node *temp = head;
    if(head == NULL){
        printf("Stack Empty\n");
        exit(1);
    }
    do {
        printf("%d->",temp->data);
        temp = temp->next;
    } while(temp != head);
    printf("NULL\n");
}

int countNodes(node* head){
    if(isEmpty(head)){
        return 0;
    }
    int count = 0;
    node *temp = head;
    do {
        count++;
        temp = temp->next;
    } while(temp != head);
    return count;
}

void insertAfterKthNode(node* head,int data, int k){
    node *temp = malloc(sizeof(node));
    temp->data = data;

    if(isEmpty(head)){
        printf("List is empty. Inserting at the head.\n");
        head = temp;
        temp->next = head;
        return;
    }

    if(countNodes(head)<k){
        printf("Inserting at the end");
    }
    node *ptr = head;
    for(int i = 1; i < k && ptr->next != head; i++){
        ptr = ptr->next;
    }
    
    temp->next = ptr->next;
    ptr->next = temp;
}

void deleteAfterKthNode(node* head, int k){
    if(isEmpty(head)){
        printf("List is empty.\n");
        return;
    }

    node *ptr = head;
    for(int i = 1; i < k && ptr->next != head; i++){
        ptr = ptr->next;
    }

    node *temp = ptr->next;
    if(temp == head){
        printf("Can't delete the head node in this manner.\n");
        return;
    }
    ptr->next = temp->next;
    printf("Deleted node with data: %d\n", temp->data);
    free(temp);
}

int main(){
    node* head = malloc(sizeof(node));
    head->data = 46;
    head->next = head;
    // head=NULL;
    // insert_ll(&head,1);
    // insert_ll(head,2);
    // insert_ll(head,3);
    // insert_ll(head,4);
    // insert_ll(head,5);
    // insert_ll(head,6);
    // insert_ll(head,7);
    display(head);
    // printf("%d",countNodes(head));
    // insertAfterKthNode(head,10,4);
    // display(head);
    // deleteAfterKthNode(head,6);
    // display(head);

}