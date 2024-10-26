#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct Queue {
    int front, rear;
    int arr[MAX];
} Queue;

void init(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue *q)
{
    return q->front == -1;
}

int isFull(Queue *q)
{
    return (q->rear + 1) % MAX == q->front;
}

void enqueue(Queue *q, int value)
{
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;                       // When inserting the first element, update front
    }
    q->rear = (q->rear + 1) % MAX;          // Circular increment of rear
    q->arr[q->rear] = value;
}

void dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    if (q->front == q->rear) {              // Only one element was present
        q->front = q->rear = -1;            // Reset queue after the last element is dequeued
    }
    else {
        q->front = (q->front + 1) % MAX;    // Circular increment of front
    }
}

void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    int i = q->front;
    printf("Queue: ");
    while (i != q->rear) {
        printf("%d ", q->arr[i]);
        i = (i + 1) % MAX;
    }
    printf("%d\n", q->arr[i]);              // Print the last element
}

int main() {
    Queue q;
    init(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    display(&q);

    dequeue(&q);
    dequeue(&q);

    display(&q);

    enqueue(&q, 60);
    enqueue(&q, 70);

    display(&q);

    return 0;
}
