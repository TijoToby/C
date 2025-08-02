#include <stdio.h>
int front = -1, rear = -1, arr[50];
void Enqueue(int maxsize) {
if (rear == maxsize - 1) {
printf("Overflow\n");
return;
}
int value;
printf("Enter the element: ");
scanf("%d", &value);
if (front == -1 && rear == -1)
front = rear = 0;
else
rear++;
arr[rear] = value;
}
void Dequeue() {
if (front == -1 || front > rear) {
printf("Underflow\n");
return;
}
printf("Deleted element is %d\n", arr[front]);
front++;
if (front > rear)
front = rear = -1;
}
void Display() {
if (front == -1 || front > rear) {
printf("Queue is empty\n");
return;
}
printf("Queue elements:\n");
for (int i = front; i <= rear; i++)
printf("%d ", arr[i]);
printf("\n");
}
int main() {
int maxsize, op;
printf("Enter the size of the queue: ");
scanf("%d", &maxsize);
while (1) {
printf("\nChoose the operation to be performed \n 1-Enqueue 2-Dequeue 3-Display 0-Exit: ");
scanf("%d", &op);
switch (op) {
case 1: Enqueue(maxsize); break;
case 2: Dequeue(); break;
case 3: Display(); break;
case 0: return 0;
default: printf("Invalid option\n");
}
}
}
