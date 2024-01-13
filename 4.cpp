#include <stdio.h>
int main() {
	int n,k;
	printf("\n Give size: ");
	scanf("%d",&n);
  int arr[n];
  printf("\n Give elements: ");
  for(k=0;k<n;k++)
   scanf("%d",&arr[k]);

  int max = arr[0];
  int second_max = arr[1];
  for (int i = 2; i < n; i++) {
    if (arr[i] > max) {
      second_max = max;
      max = arr[i];
    } 
    else if (arr[i] > second_max) 
      second_max = arr[i];
  }
  printf("\n max is %d", max);
  printf("\n second max is %d", second_max);

  return 0;
}

