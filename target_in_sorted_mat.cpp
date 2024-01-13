#include <iostream>
#include<vector>
using namespace std;

void mat_search(vector<vector<int>> &array, int x, int row, int col) {
  // Repeat until the pointers low and high meet each other
  int low=0,high=row*col-1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    int r = mid/col;
    int c = mid%row;
    if (array[r][c] == x)
      printf("\n %d is found at [%d][%d]",x,r,c);
    else if (array[r][c] < x)
      low = mid + 1;
    else
      high = mid - 1;
  }
  printf("\n %d is not found",x);
}

main(){
vector<vector<int>> a={{2, 6, 8, 9, 11},
                 {20, 22, 28, 29, 31},
                 {36, 38, 50, 57, 63},
                 {64, 66, 78, 90, 112}};
mat_search(a,50,a.size(),a[0].size());
}