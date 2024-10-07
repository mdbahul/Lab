#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node* next;
}node;
node* reverse(node* head);
// {
// 	node* prev = NULL;
// 	node* curr = head;
// 	while(curr){
// 		node* front = curr->next;
// 		curr->next = prev;
// 		prev = curr;
// 		curr = front;
// 	}
// 	return prev;
// }
node* createNode(int data) {
    node* newNode = new node();
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    
    cout << "Original list: ";
    printList(head);
    
    head = reverse(head);
    
    cout << "Reversed list: ";
    printList(head);
    
    return 0;
}
node* reverse(node* head) {
    if(node == NULL) return NULL;
    node* prev = NULL;
    node* curr = head;
    while(curr) {
        node* front = curr->next;
        curr->next = prev;
        prev = curr;
        curr = front;
    }
    rerurn prev;
}