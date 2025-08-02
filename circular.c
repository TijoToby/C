#include <stdio.h>
#include <stdlib.h>

int front = -1, rear = -1, *queue;

void enqueue(int n) {
    int value;
    printf("Enter the value to enqueue: ");
    scanf("%d", &value);

    if ((rear + 1) % n == front) {
        printf("Overflow: Queue is full\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % n;
    }
    queue[rear] = value;
}

void dequeue(int n) {
    if (front == -1) {
        printf("Underflow: Queue is empty\n");
        return;
    }

    printf("Deleted %d from front\n", queue[front]);
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % n;
    }
}

void display(int n) {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    int i = front;
    while (i != rear) {
        printf("%d ", queue[i]);
        i = (i + 1) % n;
    }
    printf("%d\n", queue[rear]);
}

int main() {
    int choice, n;
    printf("Enter the size of the queue: ");
    scanf("%d", &n);

    queue = (int *)malloc(n * sizeof(int));
    if (queue == NULL) {
        printf("Memory allocation failed\n");
        return -1;
    }

    do {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: enqueue(n); break;
            case 2: dequeue(n); break;
            case 3: display(n); break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid choice\n");
        }
    } while (choice != 4);

    free(queue);
    return 0;
}

