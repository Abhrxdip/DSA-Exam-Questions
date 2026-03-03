#include<stdio.h>

// Recursive Binary Search Function
int binarysearch(int arr[], int target, int start, int end){

    // Base case: If start index crosses end index
    // That means element is not present
    if(start > end){
        return -1;
    }

    // Find middle index
    int mid = (start + end) / 2;

    // If middle element is the target
    if(arr[mid] == target){
        return mid;
    }

    // If target is smaller than middle element
    // Then search in LEFT HALF
    // (start to mid-1)
    else if(arr[mid] > target){
        return binarysearch(arr, target, start, mid - 1);
    }

    // If target is greater than middle element
    // Then search in RIGHT HALF
    // (mid+1 to end)
    else{
        return binarysearch(arr, target, mid + 1, end);
    }
}

int main(){

    int n, target, arr[20];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements in sorted order:\n");
    for(int i = 0; i < n; i++){
        printf("Enter %dth element: ", i+1);
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to find: ");
    scanf("%d", &target);

    int result = binarysearch(arr, target, 0, n - 1);

    if(result == -1){
        printf("Element not found\n");
    }
    else{
        printf("Element found at index %d\n", result);
    }

    return 0;
}