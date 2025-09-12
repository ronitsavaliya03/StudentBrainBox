#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // maximum number of vertices


struct Node {
    int vertex;
    struct Node* link;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;  
    int* visited;            
};

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->link = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));
    graph->visited = (int*)malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    // Add edge src -> dest
    struct Node* newNode = createNode(dest);
    newNode->link = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge dest -> src
    newNode = createNode(src);
    newNode->link = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void DFS(struct Graph* graph, int vertex) {
    struct Node* adjList = graph->adjLists[vertex];
    struct Node* temp = adjList;

    graph->visited[vertex] = 1;
    printf("%d ", vertex);

    while (temp != NULL) {
        int connectedVertex = temp->vertex;
        if (graph->visited[connectedVertex] == 0) {
            DFS(graph, connectedVertex);
        }
        temp = temp->link;
    }
}

void BFS(struct Graph* graph, int startVertex) {
    int queue[MAX], front = 0, rear = 0;

    for (int i = 0; i < graph->numVertices; i++)
        graph->visited[i] = 0;

    graph->visited[startVertex] = 1;
    queue[rear++] = startVertex;

    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        struct Node* temp = graph->adjLists[currentVertex];

        while (temp != NULL) {
            int adjVertex = temp->vertex;
            if (graph->visited[adjVertex] == 0) {
                graph->visited[adjVertex] = 1;
                queue[rear++] = adjVertex;
            }
            temp = temp->link;
        }
    }
}

void printGraph(struct Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {       
        struct Node* temp = graph->adjLists[v];
        printf("Adjacency list of vertex %d: ", v);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->link;
        }
        printf("NULL\n");  
    }
}

int main() {
    int vertices = 5;
    struct Graph* graph = createGraph(vertices);
         
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4); 

    printGraph(graph);

    printf("DFS: ");
    for (int i = 0; i < vertices; i++)
        graph->visited[i] = 0;  
        
    DFS(graph, 0);

    printf("\nBFS: ");
    BFS(graph, 0);

    return 0;
}
