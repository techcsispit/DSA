#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct queue {
    int size;
    int *arr;
    int front;
    int back;
} Queue;

Queue *q = NULL;  // this is a global pointer

void init(int size) {
    q = (Queue *)malloc(sizeof(Queue));
    q->size = size;
    q->arr = (int *)malloc(sizeof(int) * q->size);
    q->front = 0;
    q->back = -1;
}

bool isEmpty() {
    return (q->front > q->back);
}

bool isFull() {
    return (q->back == q->size - 1);
}

void enqueue(int a) {
    if (isFull()) {
        printf("OVERFLOW\n");
    } else {
        q->arr[++(q->back)] = a;
    }
}

int dequeue() {
    if (isEmpty()) {
        printf("EMPTY QUEUE\n");
        return -1;
    } else {
        return q->arr[(q->front)++];
    }
}

int peek() {
    if (isEmpty()) {
        printf("EMPTY\n");
        return -1;
    } else {
        return q->arr[q->front];
    }
}

int main() {
    int size=5;
    init(size);

    // Example usage
    dequeue(); // to check proper working of dequeuing while queue isEmpty() 
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(90);
    enqueue(130);
    enqueue(3230);

    printf("Front element is %d\n", peek());
    printf("Dequeued %d\n", dequeue()); 
    printf("Dequeued %d\n", dequeue()); 
    printf("Dequeued %d\n", dequeue()); 
    printf("Dequeued %d\n", dequeue()); 
    printf("Dequeued %d\n", dequeue()); 
    dequeue(); // to check proper working of dequeuing while queue isEmpty() 

    return 0;
}
