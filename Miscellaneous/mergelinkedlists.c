/*
 * Program: Merge Two Linked Lists
 * Description: This program demonstrates different methods to merge two singly linked lists.
 * 
 * Methods implemented:
 *   1. Append: Merge by appending second list to the end of first list
 *   2. Alternating: Merge by alternating nodes from both lists
 *   3. Sorted Merge: Merge two sorted lists into one sorted list (maintaining order)
 * 
 * Time Complexity: O(n + m) where n and m are lengths of the two lists
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

// Function to count nodes in a list
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* temp = head;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Method 1: Merge by appending second list to the end of first list
// Original lists remain unchanged; creates a new merged list
struct Node* mergeByAppend(struct Node* list1, struct Node* list2) {
    // If first list is empty, return second list
    if(list1 == NULL) return list2;
    
    // If second list is empty, return first list
    if(list2 == NULL) return list1;
    
    // Create a new list by copying nodes from both lists
    struct Node* mergedHead = NULL;
    struct Node* temp = NULL;
    
    // Copy all nodes from first list
    temp = list1;
    while(temp != NULL) {
        mergedHead = addAtEnd(mergedHead, temp->data);
        temp = temp->next;
    }
    
    // Copy all nodes from second list
    temp = list2;
    while(temp != NULL) {
        mergedHead = addAtEnd(mergedHead, temp->data);
        temp = temp->next;
    }
    
    return mergedHead;
}

// Method 2: Merge by alternating nodes from both lists
// Takes nodes alternately from list1 and list2
struct Node* mergeAlternating(struct Node* list1, struct Node* list2) {
    // If one list is empty, return the other
    if(list1 == NULL) return list2;
    if(list2 == NULL) return list1;
    
    struct Node* mergedHead = NULL;
    struct Node* temp1 = list1;
    struct Node* temp2 = list2;
    
    // Alternate between the two lists
    while(temp1 != NULL || temp2 != NULL) {
        // Add node from first list
        if(temp1 != NULL) {
            mergedHead = addAtEnd(mergedHead, temp1->data);
            temp1 = temp1->next;
        }
        
        // Add node from second list
        if(temp2 != NULL) {
            mergedHead = addAtEnd(mergedHead, temp2->data);
            temp2 = temp2->next;
        }
    }
    
    return mergedHead;
}

// Method 3: Merge two sorted linked lists into one sorted list
// Assumes both input lists are already sorted in ascending order
struct Node* mergeSorted(struct Node* list1, struct Node* list2) {
    // If one list is empty, return the other
    if(list1 == NULL) return list2;
    if(list2 == NULL) return list1;
    
    struct Node* mergedHead = NULL;
    struct Node* temp1 = list1;
    struct Node* temp2 = list2;
    
    // Compare nodes from both lists and add in sorted order
    while(temp1 != NULL && temp2 != NULL) {
        if(temp1->data <= temp2->data) {
            mergedHead = addAtEnd(mergedHead, temp1->data);
            temp1 = temp1->next;
        } else {
            mergedHead = addAtEnd(mergedHead, temp2->data);
            temp2 = temp2->next;
        }
    }
    
    // Add remaining nodes from first list
    while(temp1 != NULL) {
        mergedHead = addAtEnd(mergedHead, temp1->data);
        temp1 = temp1->next;
    }
    
    // Add remaining nodes from second list
    while(temp2 != NULL) {
        mergedHead = addAtEnd(mergedHead, temp2->data);
        temp2 = temp2->next;
    }
    
    return mergedHead;
}

// Optimized Method 3: Merge two sorted lists (in-place, without creating new nodes)
// This is more memory efficient as it reuses existing nodes
struct Node* mergeSortedOptimized(struct Node* list1, struct Node* list2) {
    // If one list is empty, return the other
    if(list1 == NULL) return list2;
    if(list2 == NULL) return list1;
    
    struct Node* mergedHead = NULL;
    struct Node* tail = NULL;
    
    // Initialize merged list with the smaller head
    if(list1->data <= list2->data) {
        mergedHead = list1;
        list1 = list1->next;
    } else {
        mergedHead = list2;
        list2 = list2->next;
    }
    
    tail = mergedHead;
    
    // Merge the remaining nodes
    while(list1 != NULL && list2 != NULL) {
        if(list1->data <= list2->data) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }
    
    // Attach remaining nodes
    if(list1 != NULL) {
        tail->next = list1;
    } else {
        tail->next = list2;
    }
    
    return mergedHead;
}

// Function to create a list from user input
struct Node* createList(int listNumber) {
    struct Node* head = NULL;
    int n, data;
    
    printf("Enter number of nodes for List %d: ", listNumber);
    scanf("%d", &n);
    
    if(n <= 0) {
        printf("No nodes to add.\n");
        return NULL;
    }
    
    printf("Enter %d values for List %d:\n", n, listNumber);
    for(int i = 0; i < n; i++) {
        scanf("%d", &data);
        head = addAtEnd(head, data);
    }
    
    return head;
}

// Function to free a linked list
void freeList(struct Node* head) {
    struct Node* temp;
    while(head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Main function to demonstrate merging of linked lists
int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    struct Node* merged = NULL;
    int choice;
    
    printf("=== Merge Two Linked Lists ===\n\n");
    
    // Create first list
    printf("Creating List 1:\n");
    list1 = createList(1);
    
    // Create second list
    printf("\nCreating List 2:\n");
    list2 = createList(2);
    
    // Display both lists
    printf("\nList 1: ");
    display(list1);
    
    printf("List 2: ");
    display(list2);
    
    // Menu for merge operations
    while(1) {
        printf("\n--- Merge Methods ---\n");
        printf("1. Merge by Append (List2 appended to List1)\n");
        printf("2. Merge by Alternating nodes\n");
        printf("3. Merge Sorted Lists (assumes both lists are sorted)\n");
        printf("4. Display Lists\n");
        printf("5. Create New Lists\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("\nMerging by Append...\n");
                merged = mergeByAppend(list1, list2);
                printf("Merged List: ");
                display(merged);
                freeList(merged);
                merged = NULL;
                break;
                
            case 2:
                printf("\nMerging by Alternating...\n");
                merged = mergeAlternating(list1, list2);
                printf("Merged List: ");
                display(merged);
                freeList(merged);
                merged = NULL;
                break;
                
            case 3:
                printf("\nMerging Sorted Lists...\n");
                merged = mergeSorted(list1, list2);
                printf("Merged Sorted List: ");
                display(merged);
                freeList(merged);
                merged = NULL;
                break;
                
            case 4:
                printf("\nList 1: ");
                display(list1);
                printf("List 2: ");
                display(list2);
                break;
                
            case 5:
                freeList(list1);
                freeList(list2);
                if(merged != NULL) freeList(merged);
                
                printf("\nCreating List 1:\n");
                list1 = createList(1);
                
                printf("\nCreating List 2:\n");
                list2 = createList(2);
                
                printf("\nList 1: ");
                display(list1);
                printf("List 2: ");
                display(list2);
                break;
                
            case 6:
                printf("Exiting program...\n");
                freeList(list1);
                freeList(list2);
                if(merged != NULL) freeList(merged);
                return 0;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
