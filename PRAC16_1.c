#include <stdio.h>
#define V 5
void printGraph(int graph[V][V]) {
printf("Adjacency Matrix:\n");
printf(" ");
for (int i = 0; i < V; i++) {
printf("%c ", 'A' + i);
}
printf("\n");
for (int i = 0; i < V; i++) {
printf("%c ", 'A' + i);
for (int j = 0; j < V; j++) {
printf("%d ", graph[i][j]);
}
printf("\n");
}
}
int main() {
// Initialize the adjacency matrix
int graph[V][V] = {
{0, 1, 0, 1, 0}, // Connections for vertex 1
{1, 0, 1, 1, 0}, // Connections for vertex 2
{0, 1, 0, 1, 1}, // Connections for vertex 3
{1, 1, 1, 0, 1}, // Connections for vertex 4
{0, 0, 1, 1, 0} // Connections for vertex 5
};
printGraph(graph);
return 0;
}