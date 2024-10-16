#include<stdio.h>
#include<stdlib.h>


void printArray(int *A,int n){
    for(int  i=0; i<n; i++){
        printf("%d\t",A[i]);
   }
}

void insertionSort(int *A,int n){
    int key,j;
    for(int i=1;i<=n-1;i++){//i=1 because we keep first element as sorted
        key=A[i];
        j=i-1;
        while(j>=0 && A[j] > key){//less than sign gives in descending order because larger value shifts front           
            A[j+1]=A[j];
            j--;
        }
        A[j+1] =key;
    }
   
}



int main(){
    int A[]={12,54,65,7,23,9};
    int n=6;
    printArray(A,n);
    printf("\nafter sorting\n");
    insertionSort(A,n);
    printArray(A,n);
    return 0;
}