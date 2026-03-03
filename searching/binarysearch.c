#include <stdio.h>

int main() {

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

    int start = 0;
    int end = n - 1;
    int found = 0;

    while(start <= end){

        int mid = (start + end) / 2;

        if(arr[mid] == target){
            printf("Element found at index %d\n", mid);
            found = 1;
            break;   // VERY IMPORTANT
        }
        else if(arr[mid] < target){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }

    if(found == 0){
        printf("Element not found\n");
    }

    return 0;
}