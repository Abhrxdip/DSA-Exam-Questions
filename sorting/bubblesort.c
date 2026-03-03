#include <stdio.h>
#include <stdlib.h>   // For malloc() and free()

// Function to swap two numbers using pointers
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){

    int n;

    // Taking number of elements from user
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Dynamically allocating memory for n integers
    int *a = (int*)malloc(n * sizeof(int));

    // Check if memory allocation is successful
    if(a == NULL){
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Taking array input from user
    for(int i = 0; i < n; i++){
        printf("Enter %dth element: ", i + 1);
        scanf("%d", &a[i]);
    }

    // Bubble Sort Algorithm
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){

            // Compare adjacent elements
            if(a[j] > a[j + 1]){

                // Swap if elements are in wrong order
                swap(&a[j], &a[j + 1]);
            }
        }
    }

    // Display sorted array
    printf("Sorted array:\n");
    for(int i = 0; i < n; i++){
        printf("%dth element: %d\n", i + 1, a[i]);
    }

    // Free dynamically allocated memory
    free(a);

    return 0;
}