#include <stdio.h>

#define MAX 100  // Maximum number of vertices

// Function to check if the graph is complete
int is_complete_graph(int adj_matrix[MAX][MAX], int V) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i != j && adj_matrix[i][j] == 0)
                return 0;
        }
    }
    return 1;
}

// Function to get the degree of a node (for undirected graph)
int degree_of_node(int adj_matrix[MAX][MAX], int u, int V) {
    int degree = 0;
    for (int i = 0; i < V; i++) {
        degree += adj_matrix[u][i];
    }
    return degree;
}

// Function to get indegree and outdegree of a node (for directed graph)
void indegree_outdegree(int adj_matrix[MAX][MAX], int u, int V, int *indegree, int *outdegree) {
    *indegree = 0;
    *outdegree = 0;
    for (int i = 0; i < V; i++) {
        *outdegree += adj_matrix[u][i];  // Outdegree is the sum of row
        *indegree += adj_matrix[i][u];   // Indegree is the sum of column
    }
}

// Function to check if a path exists between two vertices using DFS
int path_exists(int adj_matrix[MAX][MAX], int V, int start, int end, int visited[MAX]) {
    if (start == end) return 1;
    
    visited[start] = 1;
    for (int i = 0; i < V; i++) {
        if (adj_matrix[start][i] == 1 && !visited[i]) {
            if (path_exists(adj_matrix, V, i, end, visited))
                return 1;
        }
    }
    return 0;
}

// Function to input graph as adjacency matrix
void input_graph(int adj_matrix[MAX][MAX], int V) {
    printf("Enter the adjacency matrix row by row (space-separated):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &adj_matrix[i][j]);
        }
    }
}

int main() {
    int V, adj_matrix[MAX][MAX];
    
    // Input number of vertices and adjacency matrix
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    input_graph(adj_matrix, V);
    
    // Check if the graph is complete
    if (is_complete_graph(adj_matrix, V))
        printf("The graph is complete.\n");
    else
        printf("The graph is not complete.\n");
    
    // Get degree (undirected) or indegree/outdegree (directed)
    int node;
    printf("Enter the node to find its degree (or indegree/outdegree): ");
    scanf("%d", &node);
    
    char directed;
    printf("Is the graph directed? (y/n): ");
    scanf(" %c", &directed);
    
    if (directed == 'n') {
        printf("Degree of node %d: %d\n", node, degree_of_node(adj_matrix, node, V));
    } else {
        int indegree, outdegree;
        indegree_outdegree(adj_matrix, node, V, &indegree, &outdegree);
        printf("Indegree of node %d: %d\n", node, indegree);
        printf("Outdegree of node %d: %d\n", node, outdegree);
    }
    
    // Check if a path exists between two vertices
    int start, end;
    int visited[MAX] = {0};  // Array to keep track of visited nodes
    printf("Enter the start vertex for path check: ");
    scanf("%d", &start);
    printf("Enter the end vertex for path check: ");
    scanf("%d", &end);
    
    if (path_exists(adj_matrix, V, start, end, visited))
        printf("There is a path between %d and %d.\n", start, end);
    else
        printf("No path exists between %d and %d.\n", start, end);
    
    return 0;
}




#include <stdio.h>
#include <stdbool.h>

#define MAX 100  // Maximum number of vertices

// Function to perform Breadth-First Traversal
void BFT(int adj_matrix[MAX][MAX], int V, int source) {
    int queue[MAX], front = 0, rear = 0;
    bool visited[MAX] = {false};  // To keep track of visited vertices
    int distance[MAX];  // To store the shortest distance from the source

    // Initialize all distances as -1 (indicating infinity/unreachable initially)
    for (int i = 0; i < V; i++) {
        distance[i] = -1;
    }

    // Start from the source vertex
    visited[source] = true;
    queue[rear++] = source;
    distance[source] = 0;

    printf("BFS Traversal Order: ");
    
    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        // Traverse all adjacent vertices of the current node
        for (int i = 0; i < V; i++) {
            if (adj_matrix[current][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = true;
                distance[i] = distance[current] + 1;  // Update the distance
            }
        }
    }

    printf("\nShortest distances from source vertex %d:\n", source);
    for (int i = 0; i < V; i++) {
        printf("Vertex %d: %d\n", i, distance[i]);
    }
}

// Function to input graph as adjacency matrix
void input_graph(int adj_matrix[MAX][MAX], int V) {
    printf("Enter the adjacency matrix row by row (space-separated):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &adj_matrix[i][j]);
        }
    }
}

int main() {
    int V, adj_matrix[MAX][MAX];
    int source;

    // Input number of vertices and adjacency matrix
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    input_graph(adj_matrix, V);

    // Input the source vertex for BFS
    printf("Enter the source vertex: ");
    scanf("%d", &source);

    // Perform BFS and output the traversal order and distances
    BFT(adj_matrix, V, source);

    return 0;
}
