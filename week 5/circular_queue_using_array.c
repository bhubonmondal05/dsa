#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int circularQueue[MAX];
int front = -1, rear = -1;

// Function to check if the circular queue is empty
int isEmpty() {
    return front == -1;
}

// Function to check if the circular queue is full
int isFull() {
    return (rear + 1) % MAX == front;
}

// Insert an element into the circular queue (enqueue operation)
void enqueue(int value) {
    if (isFull()) {
        printf("Circular Queue is full! Cannot insert %d.\n", value);
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }
    circularQueue[rear] = value;
    printf("Enqueued %d\n", value);
}

// Delete an element from the circular queue (dequeue operation)
void dequeue() {
    if (isEmpty()) {
        printf("Circular Queue is empty! Cannot dequeue.\n");
        return;
    }
    printf("Dequeued %d\n", circularQueue[front]);
    if (front == rear) {
        front = rear = -1;  // Reset the queue if it becomes empty
    } else {
        front = (front + 1) % MAX;
    }
}

// Peep operation (returns the front element without removing it)
void peep() {
    if (isEmpty()) {
        printf("Circular Queue is empty! No front element.\n");
        return;
    }
    printf("Front element: %d\n", circularQueue[front]);
}

// Display all elements in the circular queue
void displayQueue() {
    if (isEmpty()) {
        printf("Circular Queue is empty.\n");
        return;
    }
    printf("Circular Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", circularQueue[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// Main menu
int main() {
    int choice, value;
    while (1) {
        printf("\nCircular Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peep (Front Element)\n");
        printf("4. Display Circular Queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peep();
                break;
            case 4:
                displayQueue();
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}
