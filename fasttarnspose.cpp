// Fast transpose of sparse matrix
#include<stdio.h>
#include<stdlib.h>
#define MAX 100

typedef struct
{
    int row;
    int col;
    int val;
}sparse;


void readsparse(sparse a[], int m, int n)
{
    int i, j, k, item;
    a[0].row = m;
    a[0].col = n;
    k = 1;

    printf("\n Enter the elements:\n");
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("\n ele %d:",i*n+j+1);
            scanf("%d",&item);
            if(item == 0)
                continue;
            a[k].row = i;
            a[k].col = j;
            a[k].val = item;
            k++;
        }
    }
    a[0].val = k-1;

    printf("\n The entered sparse matrix is:\n");
    printf("\nRow  Col Value\n");
    for(i=0;  i<=a[0].val;  i++){
        printf("%d    ", a[i].row);
        printf("%d    ", a[i].col);
        printf("%d\n", a[i].val);
        
        }
    }

void fast_transpose(sparse a[])
{
    int i,c,loc;       
    sparse b[(a[0].val)+1];
    int numCols[a[0].col],numTerms[(a[0].col)+1];
    for(i=0;i<a[0].col;i++) numCols[i]=0;
    for(i=1;i<=a[0].val;i++) numCols[a[i].col]++;
    numTerms[0]=1;
    for(c=1;c<=a[0].val;c++) numTerms[i]=numCols[i-1]+numTerms[i-1];
    b[0].row=a[0].col;
    b[0].col=b[0].row;
    b[0].val=a[0].val;

    for(int i=1;i<=a[0].val;i++){
        loc=numTerms[a[i].col];
        b[loc].row=a[i].col;
        b[loc].col=a[i].row;
        b[loc].val=a[i].val;
        numTerms[a[i].col]++;
    }
    
    printf("\n The Fast Transpose sparse matrix is:\n");
    printf("\nRow  Col  Value\n");
    for(i=0; i<=a[0].val; i++){
        printf("%d    ", b[i].row);
        printf("%d    ", b[i].col);
        printf("%d\n", b[i].val);
    }
}

int main()
{
    int m,n;
    sparse a[MAX];
    printf("\n Enter the no of rows and columns: ");
    scanf("%d%d",&m, &n);
    readsparse(a, m, n);
    fast_transpose(a);
    return 7;
}

