//Josephus problem

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


    if(isEmpty()){
        head = temp;
    }
    else {
        node *ptr = head;
        while(ptr->next != head){
		    ptr=ptr->next;
	    }
	    ptr->next = temp;
    }
    temp->next = head;
}

void display(){
    node *temp = head;
    if(isEmpty()){
        printf("Stack Empty\n");
        exit(1);
    }
    do {
        printf("%d->",temp->data);
        temp = temp->next;
    } while(temp != head);
    printf("NULL\n");
}

int survivor(int k){
    node *p, *q;
    int i;
 
    q = p = head;
    while (p->next != p)
    {
        for (i = 0; i < k - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        printf("%d has been killed.\n", p->data);
        free(p);
        p = q->next;
    }
    head = p;
 
    return (p->data);
}

int main(){
    insert_ll(1);
    insert_ll(2);
    insert_ll(3);
    insert_ll(4);
    insert_ll(5);
    insert_ll(6);
    insert_ll(7);
    display();
    int left = survivor(3);
    display();
    printf("%d",left);
}