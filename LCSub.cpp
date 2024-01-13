#include<stdio.h>
#include<stdlib.h>

void accept(int*,int);
void dis(int*,int,int);
void largest_cont_sub(int*,int);

int main() {
	int* ar,n;
	char ch;
	do{
	    printf("\n Give the size of array: ");
	    scanf("%d",&n);
	    ar = (int*)malloc(n*sizeof(int));
		accept(ar,n);
		dis(ar,0,n);
		largest_cont_sub(ar,n);
		printf("\n press 'y' to run again else press anything: ");
		fflush(stdin);
		scanf("%c",&ch);
	}while(ch=='y');
    return 10;
}
void accept(int* A, int a){
    for(int i=0;i<a;i++){
		printf("\n Give element %d:",i+1);
		scanf("%d",&A[i]);
	}
}

void dis(int* A,int s,int e){
	printf("\n Given array: ");
    for(int i=s;i<e;i++)
		printf("%d ",A[i]);
}

void largest_cont_sub(int* A,int a){
	int i=0,j=1,m=0,s,t;
	while(j<a){
		if(A[i]<=A[j] && A[j-1]<A[j])
			j++;
		else{
			i=j;
			j++;
		}
		if(j-i>m){
			m=j-i;
			s=i;
			t=j;
		}
	}
	printf("\n largest contiguous subarray is: ");
	for(int k=s;k<t;k++)
		printf("%d ",A[k]);
}
