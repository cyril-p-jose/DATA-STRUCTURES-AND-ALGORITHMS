#include <stdio.h>
#define N 5

int queue[N];
int front = -1;
int rear = -1;

void enqueue(int x);
void dequeue();
void display();
void peek();

int main() {
    int choice, x;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter x: ");
                scanf("%d", &x);
                enqueue(x);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                peek();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid Choice!\n");
        }
    }
    return 0;
}

// Function to add an element to the queue
void enqueue(int x) {
    if (rear == N - 1) {
        printf("Overflow\n");
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = x;
    } else {
        rear++;
        queue[rear] = x;
    }
}

// Function to remove an element from the queue
void dequeue() {
    if (front == -1 && rear == -1) {
        printf("Underflow\n");
    } else if (front == rear) {
        printf("Dequeued element: %d\n", queue[front]);
        front = rear = -1;
    } else {
        printf("Dequeued element: %d\n", queue[front]);
        front++;
    }
}

// Function to view the front element without removing it
void peek() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Front element is: %d\n", queue[front]);
    }
}

// Function to display all elements of the queue
void display() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}
