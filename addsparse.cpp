#include <stdio.h>
// Structure to represent a sparse matrix
typedef struct sparse_matrix {
  int row;
  int col;
  int val;
}sp;
sp A[20],B[20],C[20];

void accept_create(sp*);
void dis(sp*);
void add(sp*,sp*);

int main() {
	
  accept_create(A);
  dis(A);
  
  accept_create(B);
  dis(B);
  
  printf("\n Added Sparse matrix is :-\n");
  add(A,B);
  dis(C);
	
  return 7;
}

void accept_create(sp* A){
	int r,c;
	printf("\n Enter no of rows: ");
	scanf("%d",&r);
	printf("\n Enter no of columns: ");
	scanf("%d",&c);
	int mat[r][c];
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			printf("\n enter ele [%d][%d]: ",i,j);
			scanf("%d",&mat[i][j]);
		}
	}

	int k=1;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(mat[i][j]!=0){
				A[k].row=i;
				A[k].col=j;
				A[k++].val=mat[i][j];	
			}
		}
	}
	A[0].row=r;
	A[0].col=c;
	A[0].val=--k;
}

void dis(sp* A){
	printf("\n\tRow Col Value\n");
	for(int i=0;i<=A[0].val;i++){
		printf("\t%d   %d   %d\n",A[i].row,A[i].col,A[i].val);
	}
} 

void add(sp*A,sp*B){
	int l1,l2,i=1,j=1,k=1;
	
	l1=A[0].val;
	l2=B[0].val;
	C[0].row=A[0].row;
	C[0].col=A[0].col;
	
	while(i<=l1 && j<=l2){
		if(A[i].row==B[j].row){
			if(A[i].col==B[j].col){
				C[k].row=A[i].row;
				C[k].col=A[i].col;
				C[k].val=A[i].val+B[j].val;
				++i;++j;++k;
			}
			else{
				if(A[i].col<B[j].col){
					C[k].row=A[i].row;
					C[k].col=A[i].col;
					C[k].val=A[i].val;
					++i;++k;	
				}
				else{
					C[k].row=B[j].row;
					C[k].col=B[j].col;
					C[k].val=B[j].val;
					++j;++k;
				}
			}
		}
		else{
			if(A[i].row<B[j].row){
				C[k].row=A[i].row;
				C[k].col=A[i].col;
				C[k].val=A[i].val;
				++i;++k;
			}
			else{
				C[k].row=B[j].row;
				C[k].col=B[j].col;
				C[k].val=B[j].val;
				++j;++k;				
			}
		}
		
	}
	
	while(j<=l2){
		C[k].row=B[j].row;
		C[k].col=B[j].col;
		C[k].val=B[j].val;
		++j;++k;	
	}
	while(i<=l1){
		C[k].row=A[i].row;
		C[k].col=A[i].col;
		C[k].val=A[i].val;
		++i;++k;
	}
	C[0].val=--k;
}


