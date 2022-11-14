// This Code was taken from Geeks For Geeks on 11/10/2022, website
// (https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/)
// Adjusted by Alex Kunzler & Peyton Grattino
// A C++ program for Prim's Minimum
// Spanning Tree (MST) algorithm. The program is
// for adjacency matrix representation of the graph
//#include <bits/stdc++.h>
#include <iostream>
#include <chrono>
using namespace std;

// Number of vertices in the graph
#define V 10
int comparison;
// A utility function to find the vertex with
// minimum key value, from the set of vertices
// not yet included in MST
int minKey(int key[], bool mstSet[]) {
    // Initialize min value
    int min = INT_MAX, min_index;
    
    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
    
    return min_index;
}

// A utility function to print the
// constructed MST stored in parent[]
void printMST(int parent[], int graph[V][V]) {
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";
}

// Function to construct and print MST for
// a graph represented using adjacency
// matrix representation
void primMST(int graph[V][V]) {
    // Array to store constructed MST
    int parent[V];
    
    // Key values used to pick minimum weight edge in cut
    int key[V];
    
    // To represent set of vertices included in MST
    bool mstSet[V];
    
    // Initialize all keys as INFINITE
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;
    
    // Always include first 1st vertex in MST.
    // Make key 0 so that this vertex is picked as first
    // vertex.
    key[0] = 0;
    parent[0] = -1; // First node is always root of MST
    
    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum key vertex from the
        // set of vertices not yet included in MST
        int u = minKey(key, mstSet);
        
        // Add the picked vertex to the MST Set
        mstSet[u] = true;
        
        // Update key value and parent index of
        // the adjacent vertices of the picked vertex.
        // Consider only those vertices which are not
        // yet included in MST
        for (int v = 0; v < V; v++) {
            comparison++;
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u, key[v] = graph[u][v];
            }
        }
        
        // graph[u][v] is non zero only for adjacent
        // vertices of m mstSet[v] is false for vertices
        // not yet included in MST Update the key only
        // if graph[u][v] is smaller than key[v]
    }
    
    // print the constructed MST
    printMST(parent, graph);
}

// Driver's code
int main() {
    
    int graph[V][V] = {
        {0, 6, 10, 0, 0, 0, 0, 0, 0, 0},    {6, 0, 12, 11, 14, 0, 0, 0, 0, 0},
        {10, 12, 0, 12, 0, 0, 8, 16, 0, 0}, {0, 11, 12, 0, 0, 6, 3, 0, 0, 0},
        {0, 14, 0, 0, 0, 4, 0, 0, 6, 0},    {0, 0, 0, 6, 4, 0, 0, 0, 12, 0},
        {0, 0, 8, 3, 0, 0, 0, 0, 16, 6},    {0, 0, 16, 0, 0, 0, 0, 0, 0, 8},
        {0, 0, 0, 0, 6, 12, 16, 0, 0, 13},  {0, 0, 0, 0, 0, 0, 6, 8, 13, 0}};
    
    // Print the solution
    auto primStart = chrono::steady_clock::now();
    primMST(graph);
    auto primStop = chrono::steady_clock::now();
    chrono::duration<double> primRunT = primStop - primStart;
    cout << "Number of Comparisons " << comparison << endl;
    cout << "Runtime = " << primRunT.count() << " milliseconds.";
    
    return 0;
}

// This code is contributed by rathbhupendra
