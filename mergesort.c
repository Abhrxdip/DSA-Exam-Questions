#include<stdio.h>

#define Max 100

int a[Max];
int b[Max];

void Merge(int low, int mid, int high){

    int h = low;
    int i = low;
    int j = mid + 1;

    while(h <= mid && j <= high){
        if(a[h] <= a[j]){
            b[i] = a[h];
            h++;
        }else{
            b[i] = a[j];
            j++;
        }
        i++;
    }

    // copy remaining elements
    if(h > mid){
        for(int k=j; k<=high; k++){
            b[i] = a[k];
            i++;
        }
    }else{
        for(int k=h; k<=mid; k++){
            b[i] = a[k];
            i++;
        }
    }

    // copy back to original array
    for(int k=low; k<=high; k++){
        a[k] = b[k];
    }
}

void MergesortAlgo(int low, int high){

    if(low < high){
        int mid = (low + high) / 2;

        MergesortAlgo(low, mid);
        MergesortAlgo(mid+1, high);
        Merge(low, mid, high);
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

    MergesortAlgo(0,n-1);

    printf("\nSorted array:\n");

    for(int i=0;i<n;i++){
        printf("The %dth element is: %d\n",i+1,a[i]);
    }

    return 0;
}