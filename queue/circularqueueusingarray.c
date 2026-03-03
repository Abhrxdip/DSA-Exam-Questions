// Menu Driven Program - Circular Queue using Array
#include <stdio.h>

#define N 5

int queue[N];
int f = -1;
int r = -1;

void enqueue(int x){
    // Overflow
    if((r + 1) % N == f){
        printf("Queue Overflow\n");
        return;
    }
    // Queue empty
    if(f == -1){
        f = r = 0;
    } else {
        r = (r + 1) % N;
    }
    queue[r] = x;
    printf("Element %d inserted\n", x);
}

void dequeue(){
    // Underflow
    if(f == -1){
        printf("Queue Underflow\n");
        return;
    }
    printf("Dequeued element: %d\n", queue[f]);
    // Only one element
    if(f == r){
        f = r = -1;
    } else {
        f = (f + 1) % N;
    }
}

void display(){
    if(f == -1){
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = f;
    while(1){
        printf("%d ", queue[i]);
        if(i == r) break;
        i = (i + 1) % N;
    }
    printf("\n");
}

int main(){
    int choice, value;

    while(1){
        printf("\n--- CIRCULAR QUEUE (ARRAY) MENU ---\n");
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
