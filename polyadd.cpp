#include <stdio.h>
#include <stdlib.h>
// Structure to represent a polynomial
typedef struct polynomial {
  int exp;
  int coef;
}pol;
pol A[20],B[20],C[20];

int accept(pol*);
void dis(pol*,int);
int add(pol*,pol*,int,int);

int main() {
  int a,b;
  a=accept(A);
  dis(A,a);
  b=accept(B);
  dis(B,b);
  int s=add(A,B,a,b);
  dis(C,s);
  return 6;
}

int accept(pol* A){
	int n;
	printf("\n Enter no of terms: ");
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		printf("\n Enter coef and exp of term %d: ",i);
		scanf("%d%d",&A[i].coef,&A[i].exp);
	}
	return n;
}

void dis(pol* A,int n){
	printf("\n Given polynomial is: ");
	for(int i=1;i<=n;i++){
		if(i!=n)
			printf("%dx^%d+",A[i].coef,A[i].exp);
		else{
			if(A[i].exp==1)
				printf("%dx",A[i].coef);
			else if(A[i].exp==0)
				printf("%d",A[i].coef);
			else
				printf("%dx^%d",A[i].coef,A[i].exp);	
		}
	}
} 

int add(pol*A,pol*B,int m,int n){
	int i=1,j=1,k=1;
	
	while(i<=m && j<=n){
		if(A[i].exp==B[j].exp){
			C[k].exp=A[i].exp;
			C[k].coef=A[i].coef+B[j].coef;
			++i;++j;++k;	
		}
		
		else{
			if(A[i].exp<B[j].exp){
				C[k].exp=B[j].exp;
				C[k].coef=B[j].coef;
				++j;++k;		
			}
			
			else{
				C[k].exp=A[i].exp;
				C[k].coef=A[i].coef;
				++i;++k;
			}
			
		}
	}
	while(i<=m){
		C[k].exp=A[i].exp;
		C[k].coef=A[i].coef;
		++i;++k;	
	}
	while(j<=n){
		C[k].exp=B[j].exp;
		C[k].coef=B[j].coef;
		++j;++k;
	}
	printf("\n Polynomials added and");
	return --k;
}

