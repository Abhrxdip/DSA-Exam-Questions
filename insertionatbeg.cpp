#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next=NULL;
};

Node * insertatbeg(Node *head,int value){
    Node* newnode = new Node;
    newnode->data = value;
    newnode->next = head;
    head = newnode;
    return head;
}

void display(Node * head){
    while(head!=NULL){
        cout<<"The value: "<<head->data<<endl;
        head=head->next;
    }
}

int main(){
    Node *head=NULL;

    head = insertatbeg(head,10);
    head = insertatbeg(head,20);
    head = insertatbeg(head,30);

    display(head);

    return 0;
}