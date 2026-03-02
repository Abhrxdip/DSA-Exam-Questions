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
int main(){
    
    return 0;
}