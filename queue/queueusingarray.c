#include <stdio.h>

#define N 5   // Size of queue

int queue[N];
int f = -1;
int r = -1;

// for enqueue, check:
// 1) Overflow
// 2) queue empty
// 3) normal insertion
void enqueue(int x){

    // 1) Overflow
    if(r == N - 1){
        printf("Queue Overflow\n");
        return;
    }

    // 2) queue empty
    if(f == -1 && r == -1){
        f = r = 0;
    }

    // 3) normal insertion
    else{
        r++;
    }

    queue[r] = x;
    printf("Element %d inserted\n", x);
}


// for dequeue, check:
// 1) underflow
// 2) 1 element
// 3) normal deletion
void dequeue(){

    // 1) underflow
    if(f == -1 || f > r){
        printf("Queue Underflow\n");
        return;
    }

    printf("Dequeued element: %d\n", queue[f]);

    // 2) 1 element
    if(f == r){
        f = r = -1;
    }

    // 3) normal deletion
    else{
        f++;
    }
}


// Display queue elements
void display(){

    if(f == -1 || f > r){
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements are:\n");
    for(int i = f; i <= r; i++){
        printf("%d ", queue[i]);
    }
    printf("\n");
}


// TODO: Implement queue using array (enqueue, dequeue, display)

int main(){

    int choice, value;

    while(1){

        printf("\n--- QUEUE MENU ---\n");
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
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}