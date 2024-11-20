#include <stdio.h>
#define n 7
void printgraph(int graph[n][n], int node, int visited[n])
{
    visited[node] = 1;
    printf("%c -> ", node + 'A');
    int i;
    for (i = 0; i < n; ++i)
    {
        if (graph[node][i] == 1 && !visited[i])
        {
            printgraph(graph, i, visited);
        }
    }
}
int main()
{
    int graph[n][n] = {0};
    graph[0][1] = 1; // A->B
    graph[0][2] = 1; // A->C
    graph[1][3] = 1; // B->D
    graph[1][4] = 1; // B->E
    graph[2][5] = 1; // C->F
    graph[4][6] = 1; // E->G
    int visited[n] = {0};
    printf("DFS Traversal Path: ");
    printgraph(graph, 0, visited);
    printf("End\n");
    return 0;
}