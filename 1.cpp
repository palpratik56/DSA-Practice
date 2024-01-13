//C program to multiply  two polynomials using a function
#include<stdio.h>
#include<stdlib.h>
int* prod(int A[], int B[] , int s)
{
    int* sum = (int*) malloc((2*s-1)*sizeof(int));
    for(int i=0;i<2*s-1;i++)
    sum[i]=0;//initializing
    for (int i = s; i >= 0; i--){
        for (int j = s; j >= 0; j--)
            sum[i+j]+= A[i]*B[j];
    }
	return sum;
}

void print(int ar[], int n)
{
    for (int i = n; i >=0; i--) {
        if(i!=0)	printf("%dx^%d+",ar[i],i);
        else	printf("%d",ar[i]);
    }
}

int main()
{
    int a,b;
    printf("\n Give size of both poly: ");
    scanf("%d%d",&a,&b);	
    int A[a],B[b];
    int c = a>b?a:b;
    
    printf("\n Give coefficients of A: \n");
    for(int i=c;i>=0;i--){
    	printf("x^%d: ",i);
		scanf("%d",&A[i]);
	}
    printf("\n First polynomial is \n");
    print(A, c);
    
	printf("\n Give coefficients of B: \n");
    for(int i=c;i>=0;i--){
    	printf("x^%d: ",i);
		scanf("%d",&B[i]);
	}
    printf("\n\n 2nd polynomial is \n");
    print(B, c);
    
    int* res = prod(A, B, c);
    printf("\n\n Multiplied polynomial is \n");
    print(res, 2*c);
    return 0;
}

