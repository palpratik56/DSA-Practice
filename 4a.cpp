#include <stdio.h>
//finding unique elements from a sorted array
int main() {
  int n,k;
	printf("\n Give size: ");
	scanf("%d",&n);
  int arr[n];
  for(k=0;k<n;k++){
  	printf("\n Give element no. %d: ",k+1);
  	scanf("%d",&arr[k]);
  }
  // Create a new array to store the unique elements.
  int t[n];
  int j = 0;

  // Traverse the input array and copy unique elements.
  for (int i = 1; i < n; i++) {
    if (arr[i] != arr[i - 1]) 
      t[j++] = arr[i];
  }
// Copy j elements from t[] to arr[] again.
  // for (int i = 0; i < j; i++) 
  //   arr[i] = t[i];

 //printing unique array
  printf("\n Unique elements are: ");
 for (int i = 0; i < j; i++) 
    printf(" %d ",t[i]);
  return 5;
}

