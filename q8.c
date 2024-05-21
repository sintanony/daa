#include <stdio.h>
#include <stdlib.h>
// Structure to represent an edge in the graph
struct Edge {
 int src, dest, weight;
};
// Structure to represent a subset for union-find
struct Subset {
 int parent;
 int rank;
};
// Function prototypes
int find(struct Subset subsets[], int i);
void Union(struct Subset subsets[], int x, int y);
int compareEdges(const void* a, const void* b);
void KruskalMST(struct Edge edges[], int V, int E);
int main() {
 int V, E;
 printf("Enter the number of vertices and edges: ");
 scanf("%d %d", &V, &E);
 struct Edge* edges = (struct Edge*)malloc(E * sizeof(struct Edge));
 printf("Enter source, destination, and weight for each edge:\n");
 for (int i = 0; i < E; ++i)
 scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
 KruskalMST(edges, V, E);
 free(edges);
 return 0;
}
// Find set of an element i (uses path compression technique)
int find(struct Subset subsets[], int i) {
 if (subsets[i].parent != i)
 subsets[i].parent = find(subsets, subsets[i].parent);
 return subsets[i].parent;
}
// Union of two sets of x and y (uses union by rank)
void Union(struct Subset subsets[], int x, int y) {
 int xroot = find(subsets, x);
 int yroot = find(subsets, y);
 if (subsets[xroot].rank < subsets[yroot].rank)
 subsets[xroot].parent = yroot;
 else if (subsets[xroot].rank > subsets[yroot].rank)
 subsets[yroot].parent = xroot;
 else {
 subsets[yroot].parent = xroot;
 subsets[xroot].rank++;
 }
}
// Comparator function for sorting edges based on weight
int compareEdges(const void* a, const void* b) {
 struct Edge* edge1 = (struct Edge*)a;
 struct Edge* edge2 = (struct Edge*)b;
 return edge1->weight - edge2->weight;
}
// Kruskal's algorithm for finding Minimum Spanning Tree
void KruskalMST(struct Edge edges[], int V, int E) {
 qsort(edges, E, sizeof(edges[0]), compareEdges);
 struct Subset* subsets = (struct Subset*)malloc(V * sizeof(struct Subset));
 for (int v = 0; v < V; ++v) {
 subsets[v].parent = v;
 subsets[v].rank = 0;
 }
 struct Edge* result = (struct Edge*)malloc((V - 1) * sizeof(struct Edge));
 int e = 0; // Index for result[]
 int i = 0; // Index for sorted edges[]
 while (e < V - 1 && i < E) {
 struct Edge next_edge = edges[i++];
 int x = find(subsets, next_edge.src);
 int y = find(subsets, next_edge.dest);
 if (x != y) {
 result[e++] = next_edge;
 Union(subsets, x, y);
 }
 }
 printf("Edges in the Minimum Spanning Tree:\n");
 for (int j = 0; j < e; ++j)
 printf("%d -- %d == %d\n", result[j].src, result[j].dest, result[j].weight);
 free(subsets);
 free(result);
}
