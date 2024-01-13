#include<stdio.h>
#include<stdlib.h>
int sum(int* a,int id,int n){
    if(id==(n-1)) return 0;
    return a[id]+sum(a,id+1,n);
}

main(){
    int arr[]={1,2,5,6,9,4};
    printf("\n Sum is: %d",sum(arr,0,sizeof(arr)));
}