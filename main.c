#include "graph.h"

/*
 * A basic menu based structure has been provided
 */

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    return 1;
  }

  // Read the graph from the file
  Graph *graph = readGraph(argv[1]);
  if (graph == NULL) {
    fprintf(stderr, "Error reading graph from file: %s\n", argv[1]);
    return 1;
  }

  int choice;
  // int startVertex = 1;

  do {
    // Display the options
    prompt();

    // Get user input
    printf("Enter a Choice: ");
    scanf("%d", &choice);

    /*
     * You will need to add all the cases here.
     * Call the relevant functions in each case.
     * Make sure to handle invalid inputs or edge cases.
     */

    switch (choice) {
      case 1:
        // Create Adjacency List
        createAdjacencyList(graph);
        // Display Adjacency List
        displayAdjacencyList(graph);
        break;

      case 2:
        // Perform Breadth-First Search (BFS)
        bfs(graph, 1);  // Starting from vertex 1 (index 0)
        break;

      case 3:
        // Perform Depth-First Search (DFS)
        dfs(graph, 1);  // Starting from vertex 1 (index 0)
        break;

      case 4:
        // Find Shortest Path using Dijkstra's Algorithm
        dijkstra(graph, 1);  // Starting from vertex 1 (index 0)
        break;

      case 5:
        // Exit
        printf("Exiting program.\n");
        freeGraph(graph);
        return 0;

      default:
        printf("Invalid choice. Please try again.\n");
        break;
    }

  } while (true);

  freeGraph(graph);

  return 0;
}
