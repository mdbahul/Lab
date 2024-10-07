//Write a program to check whether linear linked list has a loop or not.
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;
node *head = NULL;

int isEmpty() {
    return head == NULL;
}

void insert_ll(int data){
	node *temp = malloc(sizeof(node));

	temp->data = data;
	temp->next = NULL;

    if(isEmpty()){
        head = temp;
    }
    else {
        node *ptr = head;
        while(ptr->next != NULL){
		    ptr=ptr->next;
	    }
	    ptr->next = temp;
    }	
}

// void display(){
//     node *temp = head;
//     if(isEmpty()){
//         printf("Stack Empty\n");
//         exit(1);
//     }
//     while(temp){
//         printf("%d->",temp->data);
//         temp = temp->next;
//     }
//     printf("NULL\n");
// }

int detectloop()   {  
    node *s = head, *f=head;  
    while(s && f && f->next){  
        s=s->next;  
        f=f->next->next;  
        if(f==s){  
            printf("loop exists");  
            return 1;  
        }  
    }  
    return 0;  
}

void loop(){
    node *ptr = head;
    while(ptr->next!=NULL){
        ptr = ptr->next;
    }
    ptr->next = head->next->next; 
}

int main(){
    insert_ll(1);
    insert_ll(2);
    insert_ll(3);
    insert_ll(4);
    insert_ll(5);
    loop();
    detectloop();
}

