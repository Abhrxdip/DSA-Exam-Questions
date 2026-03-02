#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next = NULL;
};

Node* insertatmiddle(Node* head, int value, int position){

    Node* newnode = new Node;
    newnode->data = value;

    // insert at beginning
    if(position == 0){
        newnode->next = head;
        return newnode;
    }

    Node *temp = head;

    // move to position-1
    for(int i = 0; i < position-1 && temp != NULL; i++){
        temp = temp->next;
    }

    if(temp == NULL){
        cout<<"Invalid position\n";
        return head;
    }

    newnode->next = temp->next;
    temp->next = newnode;

    return head;
}

void display(Node *head){

    Node *ptr = head;

    while(ptr != NULL){
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

int main(){

    int position, value;

    Node* head = new Node;
    Node* node2 = new Node;
    Node* node3 = new Node;
    Node* node4 = new Node;

    // assigning data
    head->data = 10;
    node2->data = 20;
    node3->data = 30;
    node4->data = 40;

    // linking nodes
    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = NULL;

    cout<<"Enter position and value: ";
    cin>>position>>value;

    head = insertatmiddle(head,value,position);

    display(head);

    return 0;
}