//Union and Intersection of Two Arrays
#include <stdio.h>
#define fr(n) for(i=0;i<n;i++)
// Function to find the union of two arrays
void uni(int a[], int n, int b[], int m) {
  int i, j, k;
  int c[n+m];

  for (i = 0; i < n; i++)  c[i] = a[i];

  for (i = 0; i < m; i++)  c[n + i] = b[i];

  for (i = 0; i < n + m; i++) {
    for (j = i + 1; j < n + m; j++) {
      if (c[i] == c[j])     c[j] = -1;
   }
  }

  for (i = 0, k = 0; i < n + m; i++) {
    if (c[i] != -1)   c[k++] = c[i];
   }

printf("\n Union array is:- ");
  for (i = 0; i < k; i++)   printf("%d ", c[i]);
}

// Function to find the intersection of two arrays
void Inter(int arr1[], int arr2[], int n1, int n2) {
    printf("Intersection of the two arrays: ");
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (arr1[i] == arr2[j]) {
                printf("%d ", arr1[i]);
                break;
            }
        }
    }
    printf("\n");
}

int main() {
    int a,b,i;
    printf("\n Give the sizes of two array: ");
    scanf("%d %d",&a,&b);
    int a1[a],a2[b];
    printf("\n In array 1");
    fr(a){
		printf("\n Give element %d:",i+1);
		scanf("%d",&a1[i]);
	}
	printf("\n In array 2");
    fr(b){
		printf("\n Give element %d:",i+1);
		scanf("%d",&a2[i]);
	}
    uni(a1, a, a2, b);
    Inter(a1, a2, a, b);

    return 0;
}


