# 2024/12/01

# Adjacency-Matrix-Graph-Processor

This project implements a **Graph Data Structure** with essential graph traversal and shortest path algorithms, including:
1. Breadth-First Search (BFS)
2. Depth-First Search (DFS)
3. Dijkstra’s Algorithm for shortest path

The program is designed to read a graph from an adjacency matrix file and perform various operations using a menu-driven interface.

---

## Table of Contents

1. [Introduction](#introduction)
2. [Features](#features)
3. [Program Structure](#program-structure)
   - [Main Program](#main-program)
   - [Core Functionalities](#core-functionalities)
4. [How to Run](#how-to-run)
5. [Usage](#usage)
6. [Implementation Details](#implementation-details)
   - [Graph Representation](#graph-representation)
   - [Traversal Algorithms](#traversal-algorithms)
   - [Shortest Path Algorithm](#shortest-path-algorithm)

---

## Introduction

This project demonstrates the fundamentals of graph representation and traversal algorithms. The graph is represented using both adjacency matrices and adjacency lists for flexibility and efficiency. The program allows users to:
- Traverse the graph using BFS and DFS.
- Find the shortest path from a starting vertex to all other vertices using Dijkstra's Algorithm.

---

## Features

1. **Graph Representation**:
   - Input is an adjacency matrix stored in a file.
   - Graph is represented as both an adjacency matrix and an adjacency list.

2. **Graph Traversals**:
   - Breadth-First Search (BFS)
   - Depth-First Search (DFS) using recursion

3. **Shortest Path Algorithm**:
   - Dijkstra's Algorithm to compute the shortest path from a starting vertex to all other vertices.

4. **Menu-Driven Interface**:
   - Allows users to interactively choose operations.

5. **Memory Management**:
   - Dynamically allocates memory for graph structures and frees it upon program exit.

---

## Program Structure

### Main Program

- **`main.c`**:
  - Provides a menu-driven interface for the user.
  - Handles user inputs and calls the appropriate graph functions.

### Core Functionalities

- **`graph.h`**:
  - Declares the graph data structures and function prototypes.

- **`graph_functions.c`**:
  - Implements all graph operations, including:
    - Graph construction and representation
    - BFS and DFS traversal
    - Dijkstra’s Algorithm
    - Adjacency list conversion
    - Memory deallocation

---

## How to Run

### Prerequisites

- A C compiler (e.g., GCC or Clang).
- Input file containing the adjacency matrix of the graph.

### Compilation and Execution

1. Compile the program:
   ```bash
   gcc main.c graph_functions.c -o graph_program
   ```
2. Run the program with an adjacency matrix file:
   ```bash
   ./graph_program adjacency_matrix.txt
   ```

---

## Usage

### Menu Options

1. **Display Adjacency List**:
   - Converts the adjacency matrix to an adjacency list and displays it.

2. **Breadth-First Search (BFS)**:
   - Traverses the graph starting from vertex 1 (index 0 internally).

3. **Depth-First Search (DFS)**:
   - Recursively traverses the graph starting from vertex 1 (index 0 internally).

4. **Find Shortest Path (Dijkstra’s Algorithm)**:
   - Calculates the shortest path from vertex 1 to all other vertices.

5. **Exit**:
   - Exits the program and frees all dynamically allocated memory.

---

## Implementation Details

### Graph Representation

- **Adjacency Matrix**:
  - Input format is a square matrix, where the value at row `i` and column `j` represents the edge weight from vertex `i` to vertex `j`.

- **Adjacency List**:
  - Constructed from the adjacency matrix for efficient traversal operations.

### Traversal Algorithms

- **Breadth-First Search (BFS)**:
  - Uses a queue to traverse the graph level by level.
  - Ensures all vertices at a given level are visited before moving to the next level.

- **Depth-First Search (DFS)**:
  - Uses recursion to traverse the graph depth-first.
  - Visits all descendants of a vertex before backtracking.

### Shortest Path Algorithm

- **Dijkstra's Algorithm**:
  - Finds the shortest path from a starting vertex to all other vertices.
  - Utilizes a priority-based relaxation technique:
    - For each vertex, updates the shortest known distance to its neighbors.
    - Repeats until all reachable vertices are processed.
