// Menu Driven Program - Array Operations
// Insertion, Deletion, Updating, Search, Display
#include <stdio.h>

#define MAX 100

int arr[MAX];
int n = 0;

void display(){
    if(n == 0){
        printf("Array is empty\n");
        return;
    }
    printf("Array elements: ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insert(){
    int pos, value;
    if(n == MAX){
        printf("Array is full\n");
        return;
    }
    printf("Enter position (1 to %d): ", n + 1);
    scanf("%d", &pos);
    if(pos < 1 || pos > n + 1){
        printf("Invalid position\n");
        return;
    }
    printf("Enter value: ");
    scanf("%d", &value);
    for(int i = n; i >= pos; i--){
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = value;
    n++;
    printf("Element %d inserted at position %d\n", value, pos);
}

void delete(){
    int pos;
    if(n == 0){
        printf("Array is empty\n");
        return;
    }
    printf("Enter position to delete (1 to %d): ", n);
    scanf("%d", &pos);
    if(pos < 1 || pos > n){
        printf("Invalid position\n");
        return;
    }
    printf("Deleted element: %d\n", arr[pos - 1]);
    for(int i = pos - 1; i < n - 1; i++){
        arr[i] = arr[i + 1];
    }
    n--;
}

void update(){
    int pos, value;
    if(n == 0){
        printf("Array is empty\n");
        return;
    }
    printf("Enter position to update (1 to %d): ", n);
    scanf("%d", &pos);
    if(pos < 1 || pos > n){
        printf("Invalid position\n");
        return;
    }
    printf("Enter new value: ");
    scanf("%d", &value);
    printf("Updated position %d: %d -> %d\n", pos, arr[pos - 1], value);
    arr[pos - 1] = value;
}

void search(){
    int key, found = 0;
    if(n == 0){
        printf("Array is empty\n");
        return;
    }
    printf("Enter element to search: ");
    scanf("%d", &key);
    for(int i = 0; i < n; i++){
        if(arr[i] == key){
            printf("Element %d found at position %d\n", key, i + 1);
            found = 1;
            break;
        }
    }
    if(!found){
        printf("Element %d not found\n", key);
    }
}

int main(){
    int choice;

    while(1){
        printf("\n--- ARRAY OPERATIONS MENU ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Update\n");
        printf("4. Search\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                update();
                break;
            case 4:
                search();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
