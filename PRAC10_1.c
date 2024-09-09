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
    enqueue(6);
    enqueue(9);
    enqueue(7);
     enqueue(45);
    enqueue(69);
    enqueue(14);
    display(queue);
    dequeue();
    display(queue);
}