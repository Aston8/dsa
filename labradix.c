#include<stdio.h>
#include<stdlib.h>
#define size 10

int largest(int arr[],int n){
    int large = arr[0],i;
    for(i=1;i<n;i++){
        if(arr[i]>large){
            large=arr[i];
        }
        
    }
    return large;//
}

void radix(int arr[],int n){
    int bucket[size][size],bucket_count[size];
    int NOP=0,divisor=1,ramainder,large,pass,i,k,j;
    large=largest(arr,n);
    while (large>0)
    {
        NOP++;
        large /=size;//
    }
    for ( pass = 0; pass<NOP ;pass++)
    {
        for ( i = 0; i < size; i++)
        {
          bucket_count[i]=0;
        }
        for(i=0;i<n;i++){
            ramainder=(arr[i]/divisor)%size;//
            bucket[ramainder][bucket_count[ramainder]]=arr[i];
            bucket_count[ramainder]++;//
        }
        i=0;
        for(k=0;k<size;k++){
            for(j=0;j<bucket_count[k];j++){
                arr[i]=bucket[k][j];
                i++;//
            }
        }
        divisor*=size;
        
    }
}

int main(){
    int arr[size],n;
    printf("Enter the no of elements\n");
    scanf("%d",&n);
    printf("Enter array elemnts\n");
    for (int i = 0; i < n; i++)
    {
       scanf("%d",&arr[i]);
    }
    radix(arr,n);
    printf("sorted elemnts are\n");
    for(int i=0;i<n;i++){
        printf("%d\n",arr[i]);
    }
    
    return 0;
}