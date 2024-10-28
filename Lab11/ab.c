#include <stdio.h>
#include<stdlib.h>

#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int adjMatrix[MAX][MAX];  // Adjacency matrix for the graph
int visited[MAX];          // Array to keep track of visited vertices
int parent[MAX];           // Array to keep track of the parent of each vertex
int finishTime[MAX];       // Finishing time for each vertex
int time;                  // Global time counter
bool cycleDetected;        // Flag to check if a cycle is detected

// Function to perform Depth First Traversal
void DFS(int vertex, int n) {
    visited[vertex] = 1;
    printf("%d ", vertex);  // Print the vertex as it is visited
    time++;
    
    for (int i = 0; i < n; i++) {
        if (adjMatrix[vertex][i]) {  // If there is an edge
            if (!visited[i]) {       // If the vertex is not visited
                parent[i] = vertex;
                DFS(i, n);
            } else if (visited[i] == 1 && parent[vertex] != i) {
                // If a back edge is found, a cycle exists
                cycleDetected = true;
            }
        }
    }
    
    visited[vertex] = 2;       // Mark the vertex as fully processed
    finishTime[vertex] = ++time; // Set finishing time
}

// Function to initialize the DFS and display output
void performDFS(int n) {
    time = 0;
    cycleDetected = false;

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        parent[i] = -1;
        finishTime[i] = -1;
    }

    printf("Order of vertices traversed in DFS:\n");
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            DFS(i, n);
        }
    }

    printf("\n\nCycle detected: %s\n", cycleDetected ? "Yes" : "No");

    printf("Finishing times of vertices:\n");
    for (int i = 0; i < n; i++) {
        printf("Vertex %d: Finishing time = %d\n", i, finishTime[i]);
    }
}

int** listToMatrix(int **a, int n){
    int** mat = (int*)calloc(n, sizeof(int));
    for(int i=0; i<n;i++){
        mat[i] = (int*)calloc(n, sizeof(int));
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n;j++){
            if(a[i][j] != 0){
                mat[i][a[i][j]-1] = 1;
            }
        }
    }
    return mat;
}
int main() {
    // Write C code here
    printf("Try programiz.pro");
        int n;
    printf("Enter the number of vertices");
    scanf("%d", &n);
    int** a = (int*)calloc(n, sizeof(int));
    for(int i=0; i<n;i++){
        a[i] = (int*)calloc(n, sizeof(int));
    }

    for(int i=0; i<n; i++){
        printf("Enter the vertices to which vertex %d is connected else enter 0", i+1);
        for(int j=0; j<n;j++){
            scanf("%d", &a[i][j]);
        }
    }
    
    int** adjMatrix = listToMatrix(a, n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n;j++){
            printf("%d", adjMatrix[i][j]);
        }
        printf("\n");
    }
    performDFS(n);
    
    return 0;
}