#include <stdio.h>
#define n 7
void BFS(int graph[n][n], int start)
{
    int visited[n] = {0};
    int queue[n];
    int front = 0, rear = 0;
    visited[start] = 1;
    queue[rear++] = start;
    int i;
    printf("BFS Traversal Output: ");
    while (front < rear)
    {
        int node = queue[front++];
        printf("%d ", node);
        for (i = 0; i < n; i++)
        {
            if (graph[node][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}
void DFS(int graph[n][n], int node, int visited[n])
{
    visited[node] = 1;
    printf("%d ", node);
    int i;
    for (i = 0; i < n; i++)
    {
        if (graph[node][i] == 1 && !visited[i])
        {
            DFS(graph, i, visited);
        }
    }
}
int main()
{
    int graph[n][n] = {0};
    graph[0][1] = 1; // Edge between 0 and 1
    graph[1][0] = 1;
    graph[1][2] = 1; // Edge between 1 and 2
    graph[2][1] = 1;
    graph[1][5] = 1; // Edge between 1 and 5
    graph[5][1] = 1;
    graph[2][3] = 1; // Edge between 2 and 3
    graph[3][2] = 1;
    graph[2][5] = 1; // Edge between 2 and 5
    graph[5][2] = 1;
    graph[3][0] = 1; // Edge between 3 and 0
    graph[0][3] = 1;
    graph[3][4] = 1; // Edge between 3 and 4
    graph[4][3] = 1;
    graph[4][2] = 1; // Edge between 4 and 2
    graph[2][4] = 1;
    graph[4][6] = 1; // Edge between 4 and 6
    graph[6][4] = 1;
    graph[5][6] = 1; // Edge between 5 and 6
    graph[6][5] = 1;
    BFS(graph, 0);
    int visited[n] = {0};
    printf("DFS Traversal Output: ");
    DFS(graph, 0, visited);
    printf("\n");
    return 0;
}
