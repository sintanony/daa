#include <stdio.h>
// Function to compute transitive closure using Warshall's algorithm
void transitiveClosure(int graph[][100], int n)
{
    int i, j, k;
    // Adding vertices individually
    for (k = 0; k < n; k++)
    {
        // Fixing source vertices one by one
        for (i = 0; i < n; i++)
        {
            // Fixing destination vertices one by one
            for (j = 0; j < n; j++)
            {
                // If vertex k is on a path from i to j,
                // then mark it as reachable
                if (graph[i][k] && graph[k][j])
                    graph[i][j] = 1;
            }
        }
    }
    // Displaying the transitive closure
    printf("Transitive closure of the given graph is:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int graph[100][100], n, i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    // Input adjacency matrix
    printf("Enter the adjacency matrix (space-separated):\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    // Compute transitive closure
    transitiveClosure(graph, n);
    return 0;
}
