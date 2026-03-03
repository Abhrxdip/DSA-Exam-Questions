#include <iostream>
using namespace std;

// Define Node structure
struct Node{
    int data;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;


// for enqueue, check:
// 1) Overflow (only if memory allocation fails)
// 2) queue empty
// 3) normal insertion
void enqueue(int x){

    Node* newnode = new Node;

    // 1) Overflow (rare case if memory full)
    if(newnode == NULL){
        cout << "Queue Overflow (Memory Full)" << endl;
        return;
    }

    newnode->data = x;
    newnode->next = NULL;

    // 2) queue empty
    if(front == NULL && rear == NULL){
        front = rear = newnode;
    }

    // 3) normal insertion
    else{
        rear->next = newnode;
        rear = newnode;
    }

    cout << "Element " << x << " inserted" << endl;
}


// for dequeue, check:
// 1) underflow
// 2) 1 element
// 3) normal deletion
void dequeue(){

    // 1) underflow
    if(front == NULL){
        cout << "Queue Underflow" << endl;
        return;
    }

    Node* temp = front;
    cout << "Dequeued element: " << temp->data << endl;

    // 2) 1 element
    if(front == rear){
        front = rear = NULL;
    }

    // 3) normal deletion
    else{
        front = front->next;
    }

    delete temp;
}


// Display queue elements
void display(){

    if(front == NULL){
        cout << "Queue is empty" << endl;
        return;
    }

    Node* temp = front;

    cout << "Queue elements are: ";

    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}


// Main function (Menu Driven)
int main(){

    int choice, value;

    while(true){

        cout << "\n--- QUEUE USING LINKED LIST ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){

            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                cout << "Invalid choice" << endl;
        }
    }

    return 0;
}