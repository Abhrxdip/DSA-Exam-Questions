#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
Node* deleteanywhere(Node* head, int position){

    if(head == NULL){
        cout<<"Head is null\n";
        return head;
    }

    // delete first node
    if(position == 1){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node *temp = head;

    // move to (position-1)
    for(int i=0; i<position-2 && temp->next!=NULL; i++){
        temp = temp->next;
    }

    if(temp->next == NULL){
        cout<<"Invalid position\n";
        return head;
    }

    Node *ptr = temp->next;   // node to delete
    temp->next = ptr->next;
    delete ptr;

    return head;
}
void display(Node* head){
    Node* temp=head;
    int i=1;
    while(temp!=NULL){
        cout<<"The"<<i<<"th node is"<<temp->data<<endl;
        temp=temp->next;
        i++;
    }
}
int main(){
    Node *head=NULL;
    int position;
    //Initialising nodes
    Node* node1=new Node;
    Node *node2=new Node;
    Node *node3=new Node;
    Node*  node4=new Node;
//Assigning values and connecting them
    head=node1;
    node1->data=10;
    node1->next=node2;
    node2->data=20;
    node2->next=node3;
    node3->data=30;
    node3->next=node4;
    node4->data=40;
    node4->next=NULL;
    display(head);
    cout<<"enter the position of the linked list to be deleted(starting from 1)";
    cin>>position;
    head=deleteanywhere(head,position);
    display(head);
    return 0;
}