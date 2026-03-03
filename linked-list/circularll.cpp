// Circular Linked List - Insertion and Deletion from ends
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

Node* insertAtBeg(Node *tail, int value){
    Node *newnode = new Node;
    newnode->data = value;
    if(tail == NULL){
        tail = newnode;
        tail->next = tail;
        return tail;
    }
    newnode->next = tail->next;
    tail->next = newnode;
    return tail;
}

Node* insertAtEnd(Node *tail, int value){
    Node *newnode = new Node;
    newnode->data = value;
    if(tail == NULL){
        tail = newnode;
        tail->next = tail;
        return tail;
    }
    newnode->next = tail->next;
    tail->next = newnode;
    tail = newnode;
    return tail;
}

Node* deleteAtBeg(Node *tail){
    if(tail == NULL){
        cout<<"List is empty"<<endl;
        return NULL;
    }
    Node *head = tail->next;
    if(head == tail){
        // Only one node
        cout<<"Deleted: "<<head->data<<endl;
        delete head;
        return NULL;
    }
    tail->next = head->next;
    cout<<"Deleted: "<<head->data<<endl;
    delete head;
    return tail;
}

Node* deleteAtEnd(Node *tail){
    if(tail == NULL){
        cout<<"List is empty"<<endl;
        return NULL;
    }
    Node *head = tail->next;
    if(head == tail){
        // Only one node
        cout<<"Deleted: "<<tail->data<<endl;
        delete tail;
        return NULL;
    }
    Node *temp = head;
    while(temp->next != tail){
        temp = temp->next;
    }
    temp->next = head;
    cout<<"Deleted: "<<tail->data<<endl;
    delete tail;
    return temp;
}

void display(Node *tail){
    if(tail == NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    Node *temp = tail->next; // head
    do{
        cout<<temp->data<<" -> ";
        temp = temp->next;
    } while(temp != tail->next);
    cout<<"(back to head)"<<endl;
}

int main(){
    Node *tail = NULL;

    tail = insertAtEnd(tail, 10);
    tail = insertAtEnd(tail, 20);
    tail = insertAtEnd(tail, 30);
    tail = insertAtBeg(tail, 5);

    cout<<"Circular Linked List: ";
    display(tail);

    tail = deleteAtBeg(tail);
    cout<<"After deleting at beginning: ";
    display(tail);

    tail = deleteAtEnd(tail);
    cout<<"After deleting at end: ";
    display(tail);

    return 0;
}
