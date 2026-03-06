/*
 * Program: Depth First Search (DFS) Implementation
 * Description: This program implements Depth First Search algorithm for graph traversal.
 *              DFS explores as far as possible along each branch before backtracking.
 *              It can be implemented using recursion or an explicit stack.
 * 
 * Algorithm (Recursive):
 *   1. Mark current vertex as visited
 *   2. Visit all unvisited adjacent vertices recursively
 * 
 * Algorithm (Iterative using Stack):
 *   1. Push starting vertex onto stack
 *   2. While stack is not empty:
 *      a. Pop a vertex
 *      b. If not visited, mark as visited
 *      c. Push all unvisited adjacent vertices onto stack
 * 
 * Time Complexity: O(V + E) where V = vertices, E = edges
 * Space Complexity: O(V) for recursion stack/explicit stack and visited array
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 20  // Maximum number of vertices

// Structure to represent a stack for iterative DFS
struct Stack {
    int items[MAX];
    int top;
};

// Structure to represent a graph using adjacency matrix
struct Graph {
    int vertices;                // Number of vertices
    int adjMatrix[MAX][MAX];     // Adjacency matrix
};

// Function to create and initialize a stack
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
}

// Function to check if stack is empty
int isEmpty(struct Stack* stack) {
    return (stack->top == -1);
}

// Function to check if stack is full
int isFull(struct Stack* stack) {
    return (stack->top == MAX - 1);
}

// Function to push an element onto the stack
void push(struct Stack* stack, int value) {
    if(isFull(stack)) {
        printf("Stack overflow!\n");
        return;
    }
    stack->items[++stack->top] = value;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if(isEmpty(stack)) {
        printf("Stack underflow!\n");
        return -1;
    }
    return stack->items[stack->top--];
}

// Function to initialize the graph
void initGraph(struct Graph* graph, int vertices) {
    graph->vertices = vertices;
    
    // Initialize all elements of adjacency matrix to 0
    for(int i = 0; i < vertices; i++) {
        for(int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
    
    printf("Graph with %d vertices initialized.\n", vertices);
}

// Function to add an edge to the graph (undirected)
void addEdge(struct Graph* graph, int src, int dest) {
    // Check if vertices are valid
    if(src >= graph->vertices || dest >= graph->vertices || src < 0 || dest < 0) {
        printf("Error: Invalid vertices!\n");
        return;
    }
    
    // For undirected graph, add edge in both directions
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1;
    
    printf("Edge added: %d <-> %d\n", src, dest);
}

// Function to display the adjacency matrix
void displayGraph(struct Graph* graph) {
    printf("\nAdjacency Matrix:\n");
    printf("   ");
    
    // Print column headers
    for(int i = 0; i < graph->vertices; i++) {
        printf("%3d", i);
    }
    printf("\n");
    
    // Print separator line
    printf("   ");
    for(int i = 0; i < graph->vertices; i++) {
        printf("---");
    }
    printf("\n");
    
    // Print matrix with row headers
    for(int i = 0; i < graph->vertices; i++) {
        printf("%2d|", i);
        for(int j = 0; j < graph->vertices; j++) {
            printf("%3d", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Recursive DFS helper function
void DFSRecursiveUtil(struct Graph* graph, int vertex, int visited[]) {
    // Mark current vertex as visited and print it
    visited[vertex] = 1;
    printf("%d ", vertex);
    
    // Recursively visit all adjacent unvisited vertices
    for(int i = 0; i < graph->vertices; i++) {
        if(graph->adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFSRecursiveUtil(graph, i, visited);
        }
    }
}

// Method 1: DFS using recursion
void DFSRecursive(struct Graph* graph, int startVertex) {
    // Create a visited array to keep track of visited vertices
    int visited[MAX] = {0};  // Initialize all as not visited (0)
    
    printf("\nDFS Traversal (Recursive) starting from vertex %d:\n", startVertex);
    
    // Call recursive helper function
    DFSRecursiveUtil(graph, startVertex, visited);
    
    printf("\n");
    
    // Check if all vertices were visited (graph is connected)
    int allVisited = 1;
    for(int i = 0; i < graph->vertices; i++) {
        if(!visited[i]) {
            allVisited = 0;
            break;
        }
    }
    
    if(!allVisited) {
        printf("Note: Not all vertices were reachable from vertex %d (graph is disconnected).\n", 
               startVertex);
    }
}

// Method 2: DFS using explicit stack (iterative)
void DFSIterative(struct Graph* graph, int startVertex) {
    // Create a visited array to keep track of visited vertices
    int visited[MAX] = {0};  // Initialize all as not visited (0)
    
    // Create a stack for DFS
    struct Stack* stack = createStack();
    
    printf("\nDFS Traversal (Iterative) starting from vertex %d:\n", startVertex);
    
    // Push the starting vertex onto stack
    push(stack, startVertex);
    
    // Loop until stack is empty
    while(!isEmpty(stack)) {
        // Pop a vertex from stack
        int currentVertex = pop(stack);
        
        // If not visited, mark as visited and print it
        if(!visited[currentVertex]) {
            visited[currentVertex] = 1;
            printf("%d ", currentVertex);
            
            // Push all adjacent unvisited vertices onto stack
            // Push in reverse order to maintain left-to-right traversal
            for(int i = graph->vertices - 1; i >= 0; i--) {
                if(graph->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                    push(stack, i);
                }
            }
        }
    }
    
    printf("\n");
    
    // Free the stack
    free(stack);
    
    // Check if all vertices were visited
    int allVisited = 1;
    for(int i = 0; i < graph->vertices; i++) {
        if(!visited[i]) {
            allVisited = 0;
            break;
        }
    }
    
    if(!allVisited) {
        printf("Note: Not all vertices were reachable from vertex %d (graph is disconnected).\n", 
               startVertex);
    }
}

// Function to perform DFS on all components (for disconnected graphs)
void DFSAllComponents(struct Graph* graph) {
    int visited[MAX] = {0};  // Initialize all as not visited
    
    printf("\nDFS Traversal of all components:\n");
    
    // Traverse all vertices
    for(int i = 0; i < graph->vertices; i++) {
        if(!visited[i]) {
            printf("Component starting from vertex %d: ", i);
            DFSRecursiveUtil(graph, i, visited);
            printf("\n");
        }
    }
}

// Function to check if graph is connected using DFS
int isConnected(struct Graph* graph) {
    int visited[MAX] = {0};
    
    // Perform DFS from vertex 0
    DFSRecursiveUtil(graph, 0, visited);
    
    // Check if all vertices were visited
    for(int i = 0; i < graph->vertices; i++) {
        if(!visited[i]) {
            return 0;  // Graph is not connected
        }
    }
    
    return 1;  // Graph is connected
}

// Function to detect cycle in undirected graph using DFS
int hasCycleUtil(struct Graph* graph, int vertex, int visited[], int parent) {
    visited[vertex] = 1;
    
    // Check all adjacent vertices
    for(int i = 0; i < graph->vertices; i++) {
        if(graph->adjMatrix[vertex][i] == 1) {
            // If adjacent vertex is not visited, recursively check for cycle
            if(!visited[i]) {
                if(hasCycleUtil(graph, i, visited, vertex)) {
                    return 1;
                }
            }
            // If adjacent vertex is visited and not parent, there's a cycle
            else if(i != parent) {
                return 1;
            }
        }
    }
    
    return 0;
}

// Function to detect cycle in the graph
int hasCycle(struct Graph* graph) {
    int visited[MAX] = {0};
    
    // Check each component
    for(int i = 0; i < graph->vertices; i++) {
        if(!visited[i]) {
            if(hasCycleUtil(graph, i, visited, -1)) {
                return 1;
            }
        }
    }
    
    return 0;
}

// Main function to demonstrate DFS
int main() {
    struct Graph graph;
    int vertices, edges, src, dest, startVertex;
    int choice;
    
    printf("=== Depth First Search (DFS) Implementation ===\n\n");
    
    // Get number of vertices
    printf("Enter number of vertices (max %d): ", MAX);
    scanf("%d", &vertices);
    
    if(vertices <= 0 || vertices > MAX) {
        printf("Invalid number of vertices!\n");
        return 1;
    }
    
    // Initialize the graph
    initGraph(&graph, vertices);
    
    // Get number of edges
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    
    // Add edges
    printf("Enter edges (source destination):\n");
    for(int i = 0; i < edges; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(&graph, src, dest);
    }
    
    // Menu-driven program
    while(1) {
        printf("\n--- Menu ---\n");
        printf("1. Display Graph (Adjacency Matrix)\n");
        printf("2. Perform DFS (Recursive) from a vertex\n");
        printf("3. Perform DFS (Iterative) from a vertex\n");
        printf("4. Perform DFS on all components\n");
        printf("5. Check if graph is connected\n");
        printf("6. Check if graph has a cycle\n");
        printf("7. Add more edges\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                displayGraph(&graph);
                break;
                
            case 2:
                printf("Enter starting vertex for DFS: ");
                scanf("%d", &startVertex);
                if(startVertex < 0 || startVertex >= vertices) {
                    printf("Invalid vertex!\n");
                } else {
                    DFSRecursive(&graph, startVertex);
                }
                break;
                
            case 3:
                printf("Enter starting vertex for DFS: ");
                scanf("%d", &startVertex);
                if(startVertex < 0 || startVertex >= vertices) {
                    printf("Invalid vertex!\n");
                } else {
                    DFSIterative(&graph, startVertex);
                }
                break;
                
            case 4:
                DFSAllComponents(&graph);
                break;
                
            case 5:
                if(isConnected(&graph)) {
                    printf("The graph is connected.\n");
                } else {
                    printf("The graph is not connected (has multiple components).\n");
                }
                break;
                
            case 6:
                if(hasCycle(&graph)) {
                    printf("The graph has a cycle.\n");
                } else {
                    printf("The graph does not have a cycle.\n");
                }
                break;
                
            case 7:
                printf("Enter source and destination: ");
                scanf("%d %d", &src, &dest);
                addEdge(&graph, src, dest);
                break;
                
            case 8:
                printf("Exiting program...\n");
                return 0;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
