#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next = NULL;
};

Node* deleteatbeg(Node * head){

    if(head==NULL){
        cout<<"No nodes"<<endl;
        return head;
    }

    Node *temp=head;
    head=head->next;
    delete temp;

    return head;
}

void display(Node* head){

    Node* temp=head;

    if(head==NULL){
        cout<<"No nodes"<<endl;
        return;
    }

    while(temp!=NULL){
        cout<<"The value at node is " << temp->data << endl;
        temp=temp->next;
    }
}

int main(){

    Node *head=NULL;

    Node *node1=new Node;
    Node *node2=new Node;
    Node *node3=new Node;
    Node *node4=new Node;

    // Assigning values
    node1->data=20;
    node2->data=30;
    node3->data=40;
    node4->data=50;

    // Correct linking
    head=node1;
    node1->next=node2;
    node2->next=node3;
    node3->next=node4;
    node4->next=NULL;

    display(head);

    head=deleteatbeg(head);

    cout<<"\nAfter deletion:\n";
    display(head);

    return 0;
}