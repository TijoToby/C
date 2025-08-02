#include <stdio.h>
#include <stdlib.h>

int front = -1, rear = -1, *queue;

void insertFront(int n) {
    int value;
    printf("Enter the value to insert at front: ");
    scanf("%d", &value);

    if ((front == 0 && rear == n - 1) || (front == rear + 1)) {
        printf("Overflow: Deque is full\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else if (front == 0) {
        front = n - 1;
    } else {
        front--;
    }
    queue[front] = value;
}

void insertRear(int n) {
    int value;
    printf("Enter the value to insert at rear: ");
    scanf("%d", &value);

    if ((front == 0 && rear == n - 1) || (front == rear + 1)) {
        printf("Overflow: Deque is full\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else if (rear == n - 1) {
        rear = 0;
    } else {
        rear++;
    }
    queue[rear] = value;
}

void deleteFront(int n) {
    if (front == -1) {
        printf("Underflow: Deque is empty\n");
        return;
    }

    printf("Deleted %d from front\n", queue[front]);
    if (front == rear) {
        front = rear = -1;
    } else if (front == n - 1) {
        front = 0;
    } else {
        front++;
    }
}

void deleteRear(int n) {
    if (front == -1) {
        printf("Underflow: Deque is empty\n");
        return;
    }

    printf("Deleted %d from rear\n", queue[rear]);
    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = n - 1;
    } else {
        rear--;
    }
}

void display(int n) {
    if (front == -1) {
        printf("Deque is empty\n");
        return;
    }

    printf("Deque elements: ");
    int i = front;
    while (i != rear) {
        printf("%d ", queue[i]);
        i = (i + 1) % n;
    }
    printf("%d\n", queue[rear]);
}

int main() {
    int choice, n;
    printf("Enter the size of the deque: ");
    scanf("%d", &n);

    queue = (int *)malloc(n * sizeof(int));
    if (queue == NULL) {
        printf("Memory allocation failed\n");
        return -1;
    }

    do {
        printf("\n1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertFront(n); break;
            case 2: insertRear(n); break;
            case 3: deleteFront(n); break;
            case 4: deleteRear(n); break;
            case 5: display(n); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice\n");
        }
    } while (choice != 6);

    free(queue);
    return 0;
}

