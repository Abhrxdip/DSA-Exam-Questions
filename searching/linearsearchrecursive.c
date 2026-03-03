// Linear Search - Recursive Approach
#include <stdio.h>

int linearSearchRecursive(int arr[], int n, int key, int index) {
    if (index >= n) {
        return -1; // Base case: element not found
    }
    if (arr[index] == key) {
        return index; // Base case: element found
    }
    return linearSearchRecursive(arr, n, key, index + 1); // Recursive call
}

int main() {
    int n, key, result, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    result = linearSearchRecursive(arr, n, key, 0);

    if (result == -1) {
        printf("Element %d not found in the array.\n", key);
    } else {
        printf("Element %d found at index %d.\n", key, result);
    }

    return 0;
}
