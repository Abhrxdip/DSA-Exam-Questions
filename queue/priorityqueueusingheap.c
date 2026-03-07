#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int priorityQueue[MAX];
int size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int value) {
    if (size >= MAX) {
        printf("Priority queue is full!\n");
        return;
    }
    priorityQueue[size] = value;
    int i = size;
    size++;

    // Bubble up (max-heap)
    while (i > 0 && priorityQueue[(i - 1) / 2] < priorityQueue[i]) {
        swap(&priorityQueue[(i - 1) / 2], &priorityQueue[i]);
        i = (i - 1) / 2;
    }
    printf("Inserted %d\n", value);
}

int extractMax() {
    if (size == 0) {
        printf("Priority queue is empty!\n");
        return -1;
    }
    int max = priorityQueue[0];
    priorityQueue[0] = priorityQueue[size - 1];
    size--;

    // Heapify down
    int i = 0;
    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < size && priorityQueue[left] > priorityQueue[largest])
            largest = left;
        if (right < size && priorityQueue[right] > priorityQueue[largest])
            largest = right;
        if (largest == i) break;

        swap(&priorityQueue[i], &priorityQueue[largest]);
        i = largest;
    }
    return max;
}

void display() {
    if (size == 0) {
        printf("Priority queue is empty.\n");
        return;
    }
    printf("Priority Queue: ");
    for (int i = 0; i < size; i++)
        printf("%d ", priorityQueue[i]);
    printf("\n");
}

int main() {
    insert(10);
    insert(30);
    insert(20);
    insert(5);
    insert(15);

    display();

    printf("Extracted max: %d\n", extractMax());
    printf("Extracted max: %d\n", extractMax());

    display();

    return 0;
}
