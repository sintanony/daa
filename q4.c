#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100
int queue[MAX_VERTICES];
int front = -1, rear = -1;
void enqueue(int data)
{
    if (rear == MAX_VERTICES - 1)
    {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)
    {
        front = 0;
    }
    queue[++rear] = data;
}
int dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
        return -1;
    }
    return queue[front++];
}
int isEmpty()
{
    return front == -1 || front > rear;
}
void bfs(int graph[MAX_VERTICES][MAX_VERTICES], int numVertices, int startVertex,
         int visited[])
{
    visited[startVertex] = 1;
    enqueue(startVertex);
    while (!isEmpty())
    {
        int currentVertex = dequeue();
        printf("%d ", currentVertex);
        for (int i = 0; i < numVertices; i++)
        {
            if (graph[currentVertex][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}
int main()
{
    int numVertices, graph[MAX_VERTICES][MAX_VERTICES],
        visited[MAX_VERTICES];
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter the starting vertex for BFS: ");
    int startVertex;
    scanf("%d", &startVertex);
    for (int i = 0; i < numVertices; i++)
    {
        visited[i] = 0;
    }
    printf("BFS Traversal: ");
    bfs(graph, numVertices, startVertex, visited);
    return 0;
}