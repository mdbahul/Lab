#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* createnode(int data){
    node* new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insertatend(node** head, int data){
    node* ptr = *head;
    node* temp = createnode(data);
    if(*head == NULL){
        *head = temp;
    }
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = temp;
    // return h;
}

void print(node* head){
    node *ptr = head;
    while(ptr != NULL){
        printf("%d->",ptr->data);
        ptr = ptr -> next;
    }
}

node* insert_beg(node* head ,int data){
    node* temp = createnode(data);
    temp->next = head;
    head = temp; 
    return head;
}

node* insertatk(node* head,int data,int k){
    node* ptr = head;
    node* new_node = createnode(data);
    if(k==1){
        return insert_beg(head,data);
        // new_node->next=head;
        // head = new_node;
        // return head;
    }
    for (int i = 1; i < k-1 && ptr->next!=NULL; i++){
        ptr = ptr->next;
    }
    if(ptr == NULL){
        printf("Out of bound inserting at end");
        ptr = new_node;
        return head;
    }

    new_node->next=ptr->next;
    ptr->next = new_node;
    return head;

}

node* deletehead(node* head){
    node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

node* deleteend(node* head){
    if(head == NULL){
        return NULL;
    }
    if(head->next == NULL){
        free(head);
        return NULL;
    }
    node* ptr = head;
    while(ptr->next->next != NULL){
        ptr = ptr->next;
    }
    free(ptr->next);
    ptr->next = NULL;
    return head;
}

node* deleteatk(node* head,int k){
    if(head == NULL){
        return NULL;
    }
    if(k==1){
        node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    node* ptr = head;
    for (int i = 1; i < k-1 && ptr->next != NULL; i++)
    {
            ptr=ptr->next;
    }
    if(ptr == NULL){
        printf("data not present");
        return head;
    }
    node* temp = ptr->next;
    ptr->next = temp->next;
    free(temp);
    return head;

    
}


int main(){
    node* head = malloc(sizeof(node));
    head = createnode(67);
    head->next = createnode(8);
     insertatend(&head,3);
    // head = insert_beg(head,-1);
    // head = insertatk(head,24,1);
    // head = deletehead(head);
    // head = deleteend(head);
    // head = deleteatk(head,4);
    print(head);
}