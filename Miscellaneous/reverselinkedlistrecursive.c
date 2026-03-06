/*
 * Program: Reverse a Singly Linked List (Recursive Method)
 * Description: This program demonstrates how to reverse a singly linked list using recursion.
 *              The recursive approach reverses the list by recursively calling the function
 *              until the last node is reached, then reversing the links while returning.
 * 
 * Algorithm:
 *   1. Base case: If head is NULL or only one node, return head
 *   2. Recursively reverse the rest of the list (head->next onwards)
 *   3. Make the next node point back to current node: head->next->next = head
 *   4. Set current node's next to NULL: head->next = NULL
 *   5. Return the new head (last node of original list)
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(n) due to recursion stack
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

// Function to add a node at the end of the list
struct Node* addAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    
    // If list is empty, new node becomes the head
    if(head == NULL) {
        return newNode;
    }
    
    // Traverse to the last node
    struct Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    
    // Add new node at the end
    temp->next = newNode;
    return head;
}

// Function to display the linked list
void display(struct Node* head) {
    // Check if list is empty
    if(head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
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

// Function to reverse the linked list using recursive method
// Time Complexity: O(n), Space Complexity: O(n) due to recursion stack
struct Node* reverseListRecursive(struct Node* head) {
    // Base case: if head is NULL or only one node
    if(head == NULL || head->next == NULL) {
        return head;
    }
    
    // Recursively reverse the rest of the list
    // newHead will be the last node of the original list
    struct Node* newHead = reverseListRecursive(head->next);
    
    // Reverse the link between current node and next node
    // Make the next node point back to current node
    head->next->next = head;
    
    // Set current node's next to NULL
    head->next = NULL;
    
    return newHead;  // Return the new head
}

// Function to free the entire linked list
void freeList(struct Node* head) {
    struct Node* temp;
    while(head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Function to create a sample linked list from user input
struct Node* createList() {
    struct Node* head = NULL;
    int n, data;
    
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    
    if(n <= 0) {
        printf("Invalid number of nodes!\n");
        return NULL;
    }
    
    printf("Enter %d values:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &data);
        head = addAtEnd(head, data);
    }
    
    return head;
}

// Main function to demonstrate linked list reversal using recursion
int main() {
    struct Node* head = NULL;
    int choice;
    
    printf("=== Reverse a Singly Linked List (Recursive Method) ===\n\n");
    
    // Create initial list
    head = createList();
    
    if(head == NULL) {
        return 1;
    }
    
    printf("\nOriginal List: ");
    display(head);
    
    // Menu for operations
    while(1) {
        printf("\n--- Menu ---\n");
        printf("1. Reverse the List (Recursive)\n");
        printf("2. Display Current List\n");
        printf("3. Create New List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("\nReversing the list using recursion...\n");
                head = reverseListRecursive(head);
                printf("List after reversal: ");
                display(head);
                break;
                
            case 2:
                printf("\nCurrent List: ");
                display(head);
                break;
                
            case 3:
                freeList(head);
                printf("\n");
                head = createList();
                if(head != NULL) {
                    printf("New List: ");
                    display(head);
                }
                break;
                
            case 4:
                printf("Exiting program...\n");
                freeList(head);
                return 0;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
