// Menu Driven Program - Circular Queue using Linked List
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *rear = NULL;

void enqueue(int x){
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = x;
    if(rear == NULL){
        rear = newnode;
        rear->next = rear;
    } else {
        newnode->next = rear->next;
        rear->next = newnode;
        rear = newnode;
    }
    printf("Element %d inserted\n", x);
}

void dequeue(){
    if(rear == NULL){
        printf("Queue Underflow\n");
        return;
    }
    struct Node *front = rear->next;
    printf("Dequeued element: %d\n", front->data);
    // Only one node
    if(front == rear){
        free(front);
        rear = NULL;
    } else {
        rear->next = front->next;
        free(front);
    }
}

void display(){
    if(rear == NULL){
        printf("Queue is empty\n");
        return;
    }
    struct Node *temp = rear->next; // front
    printf("Queue elements: ");
    do{
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != rear->next);
    printf("\n");
}

int main(){
    int choice, value;

    while(1){
        printf("\n--- CIRCULAR QUEUE (LINKED LIST) MENU ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
