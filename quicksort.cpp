#include<iostream>
using namespace std;

int partition(int* a,int first,int last){
    int piv=a[last];// for randomization we can take first+rand()%(last-first+1) 
    int i=first-1;  //to insert elements at beginning
    int j=first;  //to traverse
    for(;j<last;j++){ //20,12,35,16,18,30
        if(a[j]<piv)
        swap(a[++i],a[j]);
    }
    swap(a[i+1],a[last]);
    return i+1;
}
void quicksort(int* a,int first,int last){
    //base case
    if(first>=last) return;
    //calling partition to get the pivot index
    int pi=partition(a,first,last);
    //recursively calling quicksort for the divided array
    quicksort(a,first,pi-1);
    quicksort(a,pi+1,last);
}

main(){
    int a[]={20,12,35,16,18,42,30};
    int n= sizeof(a)/sizeof(a[0]);
    quicksort(a,0,n-1);
    for(int k=0;k<n;k++)
    cout<<a[k]<<" ";
}