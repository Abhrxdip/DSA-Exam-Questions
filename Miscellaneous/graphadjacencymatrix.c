/*
 * Program: Graph Representation using Adjacency Matrix
 * Description: This program demonstrates the creation and representation of a graph
 *              using an adjacency matrix. It supports both directed and undirected graphs.
 * 
 * Adjacency Matrix:
 *   - A 2D array where matrix[i][j] = 1 if there's an edge from vertex i to vertex j
 *   - For undirected graphs, the matrix is symmetric (matrix[i][j] = matrix[j][i])
 *   - For directed graphs, matrix[i][j] = 1 means edge from i to j only
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 20  // Maximum number of vertices

// Structure to represent a graph
struct Graph {
    int vertices;                // Number of vertices in the graph
    int adjMatrix[MAX][MAX];     // Adjacency matrix to store edges
    int isDirected;              // Flag: 1 for directed, 0 for undirected
};

// Function to initialize the graph
void initGraph(struct Graph* graph, int vertices, int isDirected) {
    graph->vertices = vertices;
    graph->isDirected = isDirected;
    
    // Initialize all elements of adjacency matrix to 0 (no edges)
    for(int i = 0; i < vertices; i++) {
        for(int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
    
    if(isDirected) {
        printf("Directed graph with %d vertices initialized.\n", vertices);
    } else {
        printf("Undirected graph with %d vertices initialized.\n", vertices);
    }
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Check if vertices are valid
    if(src >= graph->vertices || dest >= graph->vertices || src < 0 || dest < 0) {
        printf("Error: Invalid vertices! Vertices should be between 0 and %d.\n", 
               graph->vertices - 1);
        return;
    }
    
    // Add edge from src to dest
    graph->adjMatrix[src][dest] = 1;
    
    // If undirected graph, add edge from dest to src as well
    if(!graph->isDirected) {
        graph->adjMatrix[dest][src] = 1;
    }
    
    printf("Edge added: %d -> %d\n", src, dest);
}

// Function to remove an edge from the graph
void removeEdge(struct Graph* graph, int src, int dest) {
    // Check if vertices are valid
    if(src >= graph->vertices || dest >= graph->vertices || src < 0 || dest < 0) {
        printf("Error: Invalid vertices!\n");
        return;
    }
    
    // Remove edge from src to dest
    graph->adjMatrix[src][dest] = 0;
    
    // If undirected graph, remove edge from dest to src as well
    if(!graph->isDirected) {
        graph->adjMatrix[dest][src] = 0;
    }
    
    printf("Edge removed: %d -> %d\n", src, dest);
}

// Function to display the adjacency matrix
void displayMatrix(struct Graph* graph) {
    printf("\nAdjacency Matrix Representation:\n");
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

// Function to display edges in the graph
void displayEdges(struct Graph* graph) {
    printf("\nEdges in the graph:\n");
    int edgeCount = 0;
    
    for(int i = 0; i < graph->vertices; i++) {
        for(int j = 0; j < graph->vertices; j++) {
            if(graph->adjMatrix[i][j] == 1) {
                printf("%d -> %d\n", i, j);
                edgeCount++;
            }
        }
    }
    
    if(edgeCount == 0) {
        printf("No edges in the graph.\n");
    } else {
        printf("Total edges: %d\n", edgeCount);
    }
}

// Function to check if an edge exists
int hasEdge(struct Graph* graph, int src, int dest) {
    if(src >= graph->vertices || dest >= graph->vertices || src < 0 || dest < 0) {
        return 0;
    }
    return graph->adjMatrix[src][dest];
}

// Function to display degree of each vertex
void displayDegrees(struct Graph* graph) {
    printf("\nDegree of each vertex:\n");
    
    for(int i = 0; i < graph->vertices; i++) {
        int degree = 0;
        
        if(graph->isDirected) {
            // For directed graph: calculate in-degree and out-degree
            int inDegree = 0, outDegree = 0;
            
            for(int j = 0; j < graph->vertices; j++) {
                if(graph->adjMatrix[i][j] == 1) outDegree++;
                if(graph->adjMatrix[j][i] == 1) inDegree++;
            }
            
            printf("Vertex %d: In-degree = %d, Out-degree = %d\n", 
                   i, inDegree, outDegree);
        } else {
            // For undirected graph: calculate degree
            for(int j = 0; j < graph->vertices; j++) {
                if(graph->adjMatrix[i][j] == 1) degree++;
            }
            printf("Vertex %d: Degree = %d\n", i, degree);
        }
    }
}

// Main function to demonstrate graph operations
int main() {
    struct Graph graph;
    int vertices, isDirected, choice;
    int src, dest;
    
    printf("=== Graph Representation using Adjacency Matrix ===\n\n");
    
    // Get graph type and number of vertices
    printf("Enter number of vertices (max %d): ", MAX);
    scanf("%d", &vertices);
    
    if(vertices <= 0 || vertices > MAX) {
        printf("Invalid number of vertices!\n");
        return 1;
    }
    
    printf("Enter graph type (0 for Undirected, 1 for Directed): ");
    scanf("%d", &isDirected);
    
    // Initialize the graph
    initGraph(&graph, vertices, isDirected);
    
    // Menu-driven program
    while(1) {
        printf("\n--- Menu ---\n");
        printf("1. Add Edge\n");
        printf("2. Remove Edge\n");
        printf("3. Display Adjacency Matrix\n");
        printf("4. Display Edges\n");
        printf("5. Check if Edge Exists\n");
        printf("6. Display Degrees\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter source vertex: ");
                scanf("%d", &src);
                printf("Enter destination vertex: ");
                scanf("%d", &dest);
                addEdge(&graph, src, dest);
                break;
                
            case 2:
                printf("Enter source vertex: ");
                scanf("%d", &src);
                printf("Enter destination vertex: ");
                scanf("%d", &dest);
                removeEdge(&graph, src, dest);
                break;
                
            case 3:
                displayMatrix(&graph);
                break;
                
            case 4:
                displayEdges(&graph);
                break;
                
            case 5:
                printf("Enter source vertex: ");
                scanf("%d", &src);
                printf("Enter destination vertex: ");
                scanf("%d", &dest);
                if(hasEdge(&graph, src, dest)) {
                    printf("Edge %d -> %d exists.\n", src, dest);
                } else {
                    printf("Edge %d -> %d does not exist.\n", src, dest);
                }
                break;
                
            case 6:
                displayDegrees(&graph);
                break;
                
            case 7:
                printf("Exiting program...\n");
                return 0;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
