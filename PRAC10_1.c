#include <stdio.h>
int queue[5];
int front = 0;
int rear = -1;
void enqueue(int data)
{
    queue[++rear]=data;
}
int dequeue()
{
    int data=queue[front];
    front++;
    return data;
}
void display(int array[])
{
    for(int i=front;i<=rear;i++)
    {
        printf(" %d  ",array[i]);
    }
    printf("\n");
}
int main()
{
    enqueue(2);
    enqueue(5);
    enqueue(-1);
    display(queue);
    dequeue();
    display(queue);
}