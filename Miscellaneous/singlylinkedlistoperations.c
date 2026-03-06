/*
 * Program: Singly Linked List Operations
 * Description: This program demonstrates the creation and representation of a singly linked list
 *              along with add and delete operations at beginning and end.
 * Operations Implemented:
 *   1. Create and display a linked list
 *   2. Add node at beginning
 *   3. Add node at end
 *   4. Delete node from beginning
 *   5. Delete node from end
 */

#include <stdio.h>
#include <stdlib.h>

// Structure definition for a node in the singly linked list
struct Node {
    int data;              // Data field to store the value
    struct Node* next;     // Pointer to the next node
};

// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the beginning of the list
struct Node* addAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;  // Point new node to current head
    head = newNode;        // Update head to point to new node
    printf("Node with data %d added at beginning.\n", data);
    return head;
}

// Function to add a node at the end of the list
struct Node* addAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    
    // If list is empty, new node becomes the head
    if(head == NULL) {
        printf("Node with data %d added at end.\n", data);
        return newNode;
    }
    
    // Traverse to the last node
    struct Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    
    // Add new node at the end
    temp->next = newNode;
    printf("Node with data %d added at end.\n", data);
    return head;
}

// Function to delete a node from the beginning
struct Node* deleteFromBeginning(struct Node* head) {
    // Check if list is empty
    if(head == NULL) {
        printf("List is empty! Cannot delete.\n");
        return NULL;
    }
    
    struct Node* temp = head;
    head = head->next;  // Move head to next node
    printf("Node with data %d deleted from beginning.\n", temp->data);
    free(temp);         // Free the memory of deleted node
    return head;
}

// Function to delete a node from the end
struct Node* deleteFromEnd(struct Node* head) {
    // Check if list is empty
    if(head == NULL) {
        printf("List is empty! Cannot delete.\n");
        return NULL;
    }
    
    // If only one node exists
    if(head->next == NULL) {
        printf("Node with data %d deleted from end.\n", head->data);
        free(head);
        return NULL;
    }
    
    // Traverse to the second last node
    struct Node* temp = head;
    while(temp->next->next != NULL) {
        temp = temp->next;
    }
    
    // Delete the last node
    printf("Node with data %d deleted from end.\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
    return head;
}

// Function to display the linked list
void display(struct Node* head) {
    // Check if list is empty
    if(head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    printf("Linked List: ");
    struct Node* temp = head;
    
    // Traverse and print each node
    while(temp != NULL) {
        printf("%d", temp->data);
        if(temp->next != NULL) {
            printf(" -> ");
        }
        temp = temp->next;
    }
    printf(" -> NULL\n");
}

// Main function to demonstrate all operations
int main() {
    struct Node* head = NULL;  // Initialize empty list
    int choice, data;
    
    printf("=== Singly Linked List Operations ===\n\n");
    
    while(1) {
        printf("\n--- Menu ---\n");
        printf("1. Add at Beginning\n");
        printf("2. Add at End\n");
        printf("3. Delete from Beginning\n");
        printf("4. Delete from End\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter data to add at beginning: ");
                scanf("%d", &data);
                head = addAtBeginning(head, data);
                break;
                
            case 2:
                printf("Enter data to add at end: ");
                scanf("%d", &data);
                head = addAtEnd(head, data);
                break;
                
            case 3:
                head = deleteFromBeginning(head);
                break;
                
            case 4:
                head = deleteFromEnd(head);
                break;
                
            case 5:
                display(head);
                break;
                
            case 6:
                printf("Exiting program...\n");
                // Free all nodes before exiting
                while(head != NULL) {
                    head = deleteFromBeginning(head);
                }
                exit(0);
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
