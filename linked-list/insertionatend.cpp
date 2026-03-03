// Singly Linked List - Insertion at End
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next = NULL;
};

Node* insertAtEnd(Node *head, int value){
    Node *newnode = new Node;
    newnode->data = value;
    newnode->next = NULL;
    if(head == NULL){
        return newnode;
    }
    Node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newnode;
    return head;
}

void display(Node *head){
    if(head == NULL){
        cout<<"No nodes"<<endl;
        return;
    }
    while(head != NULL){
        cout<<"The value: "<<head->data<<endl;
        head = head->next;
    }
}

int main(){
    Node *head = NULL;

    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);

    display(head);

    return 0;
}
