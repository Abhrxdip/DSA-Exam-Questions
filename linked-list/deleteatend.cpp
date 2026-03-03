#include <iostream>
using namespace std;

// Define structure of Node
struct Node{
    int data;
    Node* next;
};

// Insert node at end (for testing)
Node* insertAtEnd(Node* head, int value){

    // Create new node
    Node* newnode = new Node;
    newnode->data = value;
    newnode->next = NULL;

    // If list is empty
    if(head == NULL)
        return newnode;

    // Traverse to last node
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    // Attach new node at end
    temp->next = newnode;

    return head;
}

// Delete node at end
Node* deleteAtEnd(Node* head){

    // If list is empty
    if(head == NULL){
        cout << "List is empty. Nothing to delete.\n";
        return NULL;
    }

    // If only one node exists
    if(head->next == NULL){
        delete head;
        return NULL;
    }

    // Traverse to second last node
    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }

    // Delete last node
    delete temp->next;
    temp->next = NULL;

    return head;
}

// Display list
void display(Node* head){
    if(head == NULL){
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main(){

    Node* head = NULL;

    // Insert elements
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);

    cout << "Original List:\n";
    display(head);

    // Delete last node
    head = deleteAtEnd(head);

    cout << "After deleting last node:\n";
    display(head);

    return 0;
}