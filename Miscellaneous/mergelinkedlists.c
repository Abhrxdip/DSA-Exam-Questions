/*
 * Program: Merge Two Singly Linked Lists
 * Description: This program merges two singly linked lists by appending the second list
 *              to the end of the first list.
 * 
 * Algorithm:
 *   1. Create two linked lists
 *   2. Traverse list1 to reach its last node
 *   3. Connect the last node of list1 to the head of list2
 *   4. Display the merged list
 * 
 * Time Complexity: O(n) where n is the length of list1
 * Space Complexity: O(1) - no extra space used
 */

#include <stdio.h>
#include <stdlib.h>

// Structure definition for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
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

// Function to insert a node at the end of the list
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    // If list is empty, new node is the head
    if(head == NULL) {
        return newNode;
    }

    // Traverse to the last node
    struct Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }

    // Link the new node at the end
    temp->next = newNode;
    return head;
}

// Function to display the linked list
void display(struct Node* head) {
    if(head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;
    while(temp != NULL) {
        printf("%d", temp->data);
        if(temp->next != NULL)
            printf(" -> ");
        temp = temp->next;
    }
    printf(" -> NULL\n");
}

// Function to merge two linked lists
// Appends list2 to the end of list1 and returns the head of merged list
struct Node* mergeLists(struct Node* list1, struct Node* list2) {
    // If list1 is empty, return list2
    if(list1 == NULL) return list2;

    // If list2 is empty, return list1
    if(list2 == NULL) return list1;

    // Traverse to the last node of list1
    struct Node* temp = list1;
    while(temp->next != NULL) {
        temp = temp->next;
    }

    // Connect the last node of list1 to list2
    temp->next = list2;

    return list1;  // Head of the merged list
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    int n, data;

    printf("=== Merge Two Linked Lists ===\n\n");

    // Create List 1
    printf("Enter number of nodes for List 1: ");
    scanf("%d", &n);
    printf("Enter %d values:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &data);
        list1 = insertAtEnd(list1, data);
    }

    // Create List 2
    printf("\nEnter number of nodes for List 2: ");
    scanf("%d", &n);
    printf("Enter %d values:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &data);
        list2 = insertAtEnd(list2, data);
    }

    // Display both lists before merging
    printf("\nList 1: ");
    display(list1);

    printf("List 2: ");
    display(list2);

    // Merge the two lists
    list1 = mergeLists(list1, list2);

    // Display merged list
    printf("\nMerged List: ");
    display(list1);

    return 0;
}
