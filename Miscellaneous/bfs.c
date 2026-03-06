/*
 * Program: Breadth First Search (BFS) Implementation
 * Description: This program implements Breadth First Search algorithm for graph traversal.
 *              BFS explores the graph level by level, visiting all neighbors of a vertex
 *              before moving to the next level. It uses a queue data structure.
 * 
 * Algorithm:
 *   1. Start from a source vertex
 *   2. Mark it as visited and enqueue it
 *   3. While queue is not empty:
 *      a. Dequeue a vertex
 *      b. Visit all its unvisited adjacent vertices
 *      c. Mark them as visited and enqueue them
 * 
 * Time Complexity: O(V + E) where V = vertices, E = edges
 * Space Complexity: O(V) for queue and visited array
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 20  // Maximum number of vertices

// Structure to represent a queue for BFS
struct Queue {
    int items[MAX];
    int front;
    int rear;
};

// Structure to represent a graph using adjacency matrix
struct Graph {
    int vertices;                // Number of vertices
    int adjMatrix[MAX][MAX];     // Adjacency matrix
};

// Function to create and initialize a queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Function to check if queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->front == -1);
}

// Function to check if queue is full
int isFull(struct Queue* queue) {
    return (queue->rear == MAX - 1);
}

// Function to add an element to the queue (enqueue)
void enqueue(struct Queue* queue, int value) {
    if(isFull(queue)) {
        printf("Queue is full!\n");
        return;
    }
    
    if(queue->front == -1) {
        queue->front = 0;  // First element being added
    }
    
    queue->rear++;
    queue->items[queue->rear] = value;
}

// Function to remove an element from the queue (dequeue)
int dequeue(struct Queue* queue) {
    if(isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }
    
    int item = queue->items[queue->front];
    queue->front++;
    
    // Reset queue if it becomes empty
    if(queue->front > queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    }
    
    return item;
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

// BFS function to traverse the graph starting from a source vertex
void BFS(struct Graph* graph, int startVertex) {
    // Create a visited array to keep track of visited vertices
    int visited[MAX] = {0};  // Initialize all as not visited (0)
    
    // Create a queue for BFS
    struct Queue* queue = createQueue();
    
    // Mark the start vertex as visited and enqueue it
    visited[startVertex] = 1;
    enqueue(queue, startVertex);
    
    printf("\nBFS Traversal starting from vertex %d:\n", startVertex);
    printf("%d ", startVertex);
    
    // Loop until queue is empty
    while(!isEmpty(queue)) {
        // Dequeue a vertex from queue
        int currentVertex = dequeue(queue);
        
        // Visit all adjacent vertices of the dequeued vertex
        for(int i = 0; i < graph->vertices; i++) {
            // If there is an edge and the vertex is not visited
            if(graph->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;        // Mark as visited
                enqueue(queue, i);     // Enqueue the vertex
                printf("%d ", i);      // Print the vertex
            }
        }
    }
    
    printf("\n");
    
    // Free the queue
    free(queue);
    
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

// Function to perform BFS on all components (for disconnected graphs)
void BFSAllComponents(struct Graph* graph) {
    int visited[MAX] = {0};  // Initialize all as not visited
    
    printf("\nBFS Traversal of all components:\n");
    
    // Traverse all vertices
    for(int i = 0; i < graph->vertices; i++) {
        if(!visited[i]) {
            // Create a queue for BFS
            struct Queue* queue = createQueue();
            
            printf("Component starting from vertex %d: ", i);
            
            // Mark current vertex as visited and enqueue it
            visited[i] = 1;
            enqueue(queue, i);
            printf("%d ", i);
            
            // BFS for this component
            while(!isEmpty(queue)) {
                int currentVertex = dequeue(queue);
                
                for(int j = 0; j < graph->vertices; j++) {
                    if(graph->adjMatrix[currentVertex][j] == 1 && !visited[j]) {
                        visited[j] = 1;
                        enqueue(queue, j);
                        printf("%d ", j);
                    }
                }
            }
            
            printf("\n");
            free(queue);
        }
    }
}

// Main function to demonstrate BFS
int main() {
    struct Graph graph;
    int vertices, edges, src, dest, startVertex;
    int choice;
    
    printf("=== Breadth First Search (BFS) Implementation ===\n\n");
    
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
        printf("2. Perform BFS from a vertex\n");
        printf("3. Perform BFS on all components\n");
        printf("4. Add more edges\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                displayGraph(&graph);
                break;
                
            case 2:
                printf("Enter starting vertex for BFS: ");
                scanf("%d", &startVertex);
                if(startVertex < 0 || startVertex >= vertices) {
                    printf("Invalid vertex!\n");
                } else {
                    BFS(&graph, startVertex);
                }
                break;
                
            case 3:
                BFSAllComponents(&graph);
                break;
                
            case 4:
                printf("Enter source and destination: ");
                scanf("%d %d", &src, &dest);
                addEdge(&graph, src, dest);
                break;
                
            case 5:
                printf("Exiting program...\n");
                return 0;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
