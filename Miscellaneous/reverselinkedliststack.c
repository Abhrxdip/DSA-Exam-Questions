/*
 * Program: Reverse a Singly Linked List (Stack Method)
 * Description: This program demonstrates how to reverse a singly linked list using a stack.
 *              The stack data structure (LIFO - Last In First Out) naturally reverses
 *              the order when we push all nodes and then pop them.
 * 
 * Algorithm:
 *   1. Create a stack (using array)
 *   2. Traverse the list and push all nodes onto the stack
 *   3. Pop nodes from the stack and rebuild the list in reverse order
 *   4. The last node pushed becomes the new head
 *   5. Set the last node's next pointer to NULL
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(n) for the stack
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 1000  // Maximum number of nodes in the list

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

// Function to reverse the linked list using stack
// Time Complexity: O(n), Space Complexity: O(n) for stack
struct Node* reverseListUsingStack(struct Node* head) {
    // Check if list is empty or has only one node
    if(head == NULL || head->next == NULL) {
        return head;
    }
    
    // Create a stack to store nodes (using array)
    struct Node* stack[MAX_NODES];
    int top = -1;
    
    // Step 1: Push all nodes onto the stack
    struct Node* temp = head;
    int count = 0;
    while(temp != NULL) {
        if(count >= MAX_NODES) {
            printf("Error: List exceeds maximum size of %d nodes!\n", MAX_NODES);
            return head;
        }
        stack[++top] = temp;
        temp = temp->next;
        count++;
    }
    
    printf("Pushed %d nodes onto the stack.\n", count);
    
    // Step 2: Pop from stack and rebuild the list
    // The last node becomes the new head
    head = stack[top--];
    temp = head;
    
    // Step 3: Link nodes in reverse order
    while(top >= 0) {
        temp->next = stack[top--];
        temp = temp->next;
    }
    
    // Step 4: Set the last node's next to NULL
    temp->next = NULL;
    
    return head;
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
    
    printf("Enter number of nodes (max %d): ", MAX_NODES);
    scanf("%d", &n);
    
    if(n <= 0) {
        printf("Invalid number of nodes!\n");
        return NULL;
    }
    
    if(n > MAX_NODES) {
        printf("Warning: Number of nodes exceeds maximum. Setting to %d.\n", MAX_NODES);
        n = MAX_NODES;
    }
    
    printf("Enter %d values:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &data);
        head = addAtEnd(head, data);
    }
    
    return head;
}

// Function to count nodes in the list
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* temp = head;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Main function to demonstrate linked list reversal using stack
int main() {
    struct Node* head = NULL;
    int choice;
    
    printf("=== Reverse a Singly Linked List (Stack Method) ===\n\n");
    
    // Create initial list
    head = createList();
    
    if(head == NULL) {
        return 1;
    }
    
    printf("\nOriginal List: ");
    display(head);
    printf("Number of nodes: %d\n", countNodes(head));
    
    // Menu for operations
    while(1) {
        printf("\n--- Menu ---\n");
        printf("1. Reverse the List (Using Stack)\n");
        printf("2. Display Current List\n");
        printf("3. Create New List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("\nReversing the list using stack...\n");
                head = reverseListUsingStack(head);
                printf("List after reversal: ");
                display(head);
                break;
                
            case 2:
                printf("\nCurrent List: ");
                display(head);
                printf("Number of nodes: %d\n", countNodes(head));
                break;
                
            case 3:
                freeList(head);
                printf("\n");
                head = createList();
                if(head != NULL) {
                    printf("New List: ");
                    display(head);
                    printf("Number of nodes: %d\n", countNodes(head));
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
