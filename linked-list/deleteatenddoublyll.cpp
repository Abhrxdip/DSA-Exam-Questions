// Doubly Linked List - Deletion at End
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *prev;
    Node *next;
};

Node* deleteAtEnd(Node *head){
    if(head == NULL){
        cout<<"List is empty"<<endl;
        return NULL;
    }
    // If only one node
    if(head->next == NULL){
        cout<<"Deleted: "<<head->data<<endl;
        delete head;
        return NULL;
    }
    Node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->prev->next = NULL;
    cout<<"Deleted: "<<temp->data<<endl;
    delete temp;
    return head;
}

void display(Node *head){
    if(head == NULL){
        cout<<"No Nodes"<<endl;
        return;
    }
    int i = 1;
    Node *ptr = head;
    while(ptr != NULL){
        cout<<"The "<<i<<"th node is: "<<ptr->data<<endl;
        ptr = ptr->next;
        i++;
    }
}

int main(){
    Node *head = NULL;

    Node *node1 = new Node;
    Node *node2 = new Node;
    Node *node3 = new Node;
    Node *node4 = new Node;

    // Assigning data
    node1->data = 10;
    node2->data = 20;
    node3->data = 30;
    node4->data = 40;

    // Connecting
    head = node1;
    node1->prev = NULL;
    node1->next = node2;
    node2->prev = node1;
    node2->next = node3;
    node3->prev = node2;
    node3->next = node4;
    node4->prev = node3;
    node4->next = NULL;

    cout<<"Before deletion:"<<endl;
    display(head);

    head = deleteAtEnd(head);

    cout<<"\nAfter deletion at end:"<<endl;
    display(head);

    return 0;
}
