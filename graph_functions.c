#include "graph.h"

/* function will display the primary user interface
    This is already done for you*/
void prompt(void) {
  printf("\nMenu:\n");
  printf("1. Display Adjacency List\n");
  printf("2. Perform Breadth-First Search (BFS)\n");
  printf("3. Perform Depth-First Search (DFS)\n");
  printf("4. Find Shortest Path using Dijkstra's Algorithm\n");
  printf("5. Exit\n");
}

/**
 * Reads a graph from a file and constructs the graph structure.
 * @param filename The name of the file containing the adjacency matrix.
 * @return Pointer to the created Graph structure, or NULL if an error occurs.
 */
Graph *readGraph(const char *filename) {
  FILE *file = fopen(filename, "r");

  if (file == NULL) {
    return NULL;
  }

  Graph *graph = (Graph *)malloc(sizeof(Graph));
  fscanf(file, "%d", &graph->numVertices);

  // Initialize adjacency matrix
  for (int i = 0; i < graph->numVertices; i++) {
    for (int j = 0; j < graph->numVertices; j++) {
      fscanf(file, "%d", &graph->adjMatrix[i][j]);
    }
  }

  // Create adjacency list
  createAdjacencyList(graph);

  fclose(file);

  return graph;
}

/**
 * Creates a new node for the adjacency list.
 * @param vertex The vertex number that this node will represent.
 * @return Pointer to the newly created Node structure.
 */
Node *createNode(int vertex) {
  Node *newNode = (Node *)malloc(sizeof(Node));

  newNode->vertex = vertex;
  newNode->next = NULL;

  return newNode;
}

/**
 * Displays the adjacency list of the graph.
 * @param graph Pointer to the Graph structure.
 */
void displayAdjacencyList(Graph *graph) {
  for (int i = 0; i < graph->numVertices; i++) {
    printf("Vertex %d: ", i + 1);

    for (Node *temp = graph->adjList[i]; temp != NULL; temp = temp->next) {
      printf("-> %d ", temp->vertex + 1);
    }

    printf("\n");
  }
}

/**
 * Converts the adjacency matrix of the graph to an adjacency list.
 * @param graph Pointer to the Graph structure.
 */
void createAdjacencyList(Graph *graph) {
  for (int i = 0; i < graph->numVertices; i++) {
    graph->adjList[i] = NULL;

    for (int j = 0; j < graph->numVertices; j++) {
      if (graph->adjMatrix[i][j] != 0) {
        Node *newNode = createNode(j);

        newNode->next = graph->adjList[i];
        graph->adjList[i] = newNode;
      }
    }
  }
}

/**
 * Performs Breadth-First Search (BFS) starting from a given vertex.
 * @param graph Pointer to the Graph structure.
 * @param startVertex The vertex from which BFS starts (0-based index).
 */
void bfs(Graph *graph, int startVertex) {
  bool visited[MAX_VERTICES] = {false};
  int queue[MAX_VERTICES];
  int front = 0, rear = 0;

  visited[startVertex] = true;
  queue[rear++] = startVertex;

  while (front != rear) {
    int currentVertex = queue[front++];
    printf("Visited %d\n", currentVertex + 1);

    Node *temp = graph->adjList[currentVertex];

    while (temp) {
      int adjVertex = temp->vertex;

      if (!visited[adjVertex]) {
        visited[adjVertex] = true;
        queue[rear++] = adjVertex;
      }

      temp = temp->next;
    }
  }
}

/**
 * Performs Depth-First Search (DFS) starting from a given vertex.
 * @param graph Pointer to the Graph structure.
 * @param startVertex The vertex from which DFS starts (0-based index).
 */
void dfs(Graph *graph, int startVertex) {
  bool visited[MAX_VERTICES] = {false};
  dfsRecursion(graph, startVertex, visited);
}

/**
 * Performs Depth-First Search (DFS) starting from a given vertex.
 */
void dfsRecursion(Graph *graph, int vertex, bool visited[]) {
  visited[vertex] = true;
  printf("Visited %d\n", vertex + 1);

  Node *temp = graph->adjList[vertex];
  while (temp) {
    int adjVertex = temp->vertex;

    if (!visited[adjVertex]) {
      dfsRecursion(graph, adjVertex, visited);
    }

    temp = temp->next;
  }
}

/**
 * Finds the shortest path from the start vertex to all other vertices using
 * Dijkstra's algorithm.
 * @param graph Pointer to the Graph structure.
 * @param startVertex The vertex from which to start the algorithm (0-based
 * index).
 */
void dijkstra(Graph *graph, int startVertex) {
  int distances[MAX_VERTICES];
  bool visited[MAX_VERTICES] = {false};

  // Initialize distances
  for (int i = 0; i < graph->numVertices; i++) {
    distances[i] = INT_MAX;
  }

  distances[startVertex] = 0;

  for (int i = 0; i < graph->numVertices - 1; i++) {
    // Find the minimum distance vertex
    int minDist = INT_MAX;
    int minVertex = -1;

    for (int j = 0; j < graph->numVertices; j++) {
      if (!visited[j] && distances[j] < minDist) {
        minDist = distances[j];
        minVertex = j;
      }
    }

    // If no vertex was found (i.e., all reachable vertices are visited), break
    if (minVertex == -1) {
      break;
    }

    visited[minVertex] = true;

    // Update the distances of adjacent vertices
    Node *temp = graph->adjList[minVertex];

    // Ensure temp is not NULL before dereferencing
    while (temp != NULL) {
      int adjVertex = temp->vertex;
      int weight = graph->adjMatrix[minVertex][adjVertex];

      // Relaxation step
      if (!visited[adjVertex] && distances[minVertex] != INT_MAX &&
          distances[minVertex] + weight < distances[adjVertex]) {
        distances[adjVertex] = distances[minVertex] + weight;
      }

      temp = temp->next;
    }
  }

  // Print the distances
  for (int i = 0; i < graph->numVertices; i++) {
    if (distances[i] == INT_MAX) {
      printf("No path from vertex %d to vertex %d\n", startVertex + 1, i + 1);
    } else {
      printf("Distance from vertex %d to vertex %d: %d\n", startVertex + 1,
             i + 1, distances[i]);
    }
  }
}

/**
 * Frees the memory allocated for the graph, including the adjacency list.
 * @param graph Pointer to the Graph structure to be freed.
 */
void freeGraph(Graph *graph) {
  for (int i = 0; i < graph->numVertices; i++) {
    Node *temp = graph->adjList[i];

    while (temp) {
      Node *next = temp->next;
      free(temp);
      temp = next;
    }
  }

  free(graph);
}