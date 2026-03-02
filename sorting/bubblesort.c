#include<stdio.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int main(){
    int temp;
    int n,a[50];
    printf("enter number of elements: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("enter %dth element: ",i+1);
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    printf("Sorted array: ");
    for(int i=0;i<n;i++){
        printf("%dth element: %d ",i+1,a[i]);
    }
    return 0;
}