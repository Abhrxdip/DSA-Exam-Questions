#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *prev;
    Node *next;

};
Node*head=NULL;
Node* insertatbegining(Node *head, int value){
    Node *newnode=new Node;
    newnode->data=value;
    newnode->prev=NULL;
    newnode->next=NULL;
    if(head==NULL){
        cout<<"Node is empty";
        return newnode;
    }
    newnode->next=head;
    head->prev=newnode;
    head=newnode;
    return head;
}
void display(Node * head){
    int i=1;
    if(head==NULL){
        cout<<"No Nodes";
        return;
    }
    Node *ptr=head;
    while(ptr!=NULL){
        cout<<"The "<<i<<"th node is: "<<ptr->data<<endl;
        ptr=ptr->next;
        i++;
    }
}
int main(){
    int value;
    Node * node1=new Node;
    Node * node2=new Node;
    Node * node3=new Node;
    Node * node4=new Node;
    Node * node5=new Node;
    //Assigning data
    node1->data=10;
    node2->data=20;
    node3->data=30;
    node4->data=40;
    //Connecting
    head=node1;
    node1->prev=NULL;
    node1->next=node2;
    node2->prev=node1;
    node2->next=node3;
    node3->prev=node2;
    node3->next=node4;
    node4->prev=node3;
    node4->next=NULL;
    display(head);
    cout<<"Please eneter the value to insert: ";
    cin>>value;
    head=insertatbegining(head,value);
    display(head);
    return 0;
}