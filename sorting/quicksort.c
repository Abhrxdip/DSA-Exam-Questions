#include<stdio.h>

#define Max 100

int a[Max];

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int p, int q){

    int x = a[p];   // pivot
    int i = p;

    for(int j = p+1; j <= q; j++){
        if(a[j] <= x){
            i++;
            swap(&a[i], &a[j]);
        }
    }

    swap(&a[p], &a[i]); // place pivot correctly
    return i;
}

void quicksort(int p, int q){

    if(p < q){
        int m = partition(p,q);
        quicksort(p, m-1);
        quicksort(m+1, q);
    }
}

int main(){

    int n;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter the elements:\n");

    for(int i=0;i<n;i++){
        printf("Enter %d element: ",i+1);
        scanf("%d",&a[i]);
    }

    quicksort(0,n-1);

    printf("\nSorted array:\n");

    for(int i=0;i<n;i++){
        printf("The %dth element is: %d\n",i+1,a[i]);
    }

    return 0;
}