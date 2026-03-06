/*
 * Program: Reverse a Singly Linked List
 * Description: This program demonstrates three different methods to reverse a singly linked list:
 *              1. Iterative method (using three pointers)
 *              2. Recursive method
 *              3. Using a stack
 * 
 * The iterative method is the most commonly used approach with O(n) time and O(1) space complexity.
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

// Method 1: Iterative method to reverse the linked list
// Time Complexity: O(n), Space Complexity: O(1)
struct Node* reverseIterative(struct Node* head) {
    struct Node* prev = NULL;    // Previous node pointer
    struct Node* current = head; // Current node pointer
    struct Node* next = NULL;    // Next node pointer
    
    // Traverse the list and reverse the links
    while(current != NULL) {
        next = current->next;    // Store next node
        current->next = prev;    // Reverse the link
        prev = current;          // Move prev forward
        current = next;          // Move current forward
    }
    
    head = prev;  // Update head to the new first node
    return head;
}

// Method 2: Recursive method to reverse the linked list
// Time Complexity: O(n), Space Complexity: O(n) due to recursion stack
struct Node* reverseRecursive(struct Node* head) {
    // Base case: if head is NULL or only one node
    if(head == NULL || head->next == NULL) {
        return head;
    }
    
    // Recursively reverse the rest of the list
    struct Node* newHead = reverseRecursive(head->next);
    
    // Reverse the link between current node and next node
    head->next->next = head;
    head->next = NULL;
    
    return newHead;  // Return the new head
}

// Method 3: Using stack to reverse the linked list
// Time Complexity: O(n), Space Complexity: O(n) for stack
struct Node* reverseUsingStack(struct Node* head) {
    // Check if list is empty or has only one node
    if(head == NULL || head->next == NULL) {
        return head;
    }
    
    // Create a stack to store nodes (using array)
    struct Node* stack[1000];  // Assuming maximum 1000 nodes
    int top = -1;
    
    // Push all nodes onto the stack
    struct Node* temp = head;
    while(temp != NULL) {
        stack[++top] = temp;
        temp = temp->next;
    }
    
    // Pop from stack and rebuild the list
    head = stack[top--];  // New head is the last node
    temp = head;
    
    while(top >= 0) {
        temp->next = stack[top--];
        temp = temp->next;
    }
    temp->next = NULL;  // Set the last node's next to NULL
    
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

// Main function to demonstrate different reversal methods
int main() {
    struct Node* head = NULL;
    int choice;
    
    printf("=== Reverse a Singly Linked List ===\n\n");
    
    // Create initial list
    head = createList();
    
    if(head == NULL) {
        return 1;
    }
    
    printf("\nOriginal List: ");
    display(head);
    
    // Menu to choose reversal method
    while(1) {
        printf("\n--- Reversal Methods ---\n");
        printf("1. Reverse using Iterative Method\n");
        printf("2. Reverse using Recursive Method\n");
        printf("3. Reverse using Stack Method\n");
        printf("4. Display Current List\n");
        printf("5. Create New List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("\nReversing using Iterative Method...\n");
                head = reverseIterative(head);
                printf("List after reversal: ");
                display(head);
                break;
                
            case 2:
                printf("\nReversing using Recursive Method...\n");
                head = reverseRecursive(head);
                printf("List after reversal: ");
                display(head);
                break;
                
            case 3:
                printf("\nReversing using Stack Method...\n");
                head = reverseUsingStack(head);
                printf("List after reversal: ");
                display(head);
                break;
                
            case 4:
                printf("\nCurrent List: ");
                display(head);
                break;
                
            case 5:
                freeList(head);
                printf("\n");
                head = createList();
                if(head != NULL) {
                    printf("New List: ");
                    display(head);
                }
                break;
                
            case 6:
                printf("Exiting program...\n");
                freeList(head);
                return 0;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
