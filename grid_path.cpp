//count the total paths on an m*n grid from top left to bottom right
//constraint: from each cell you can either move bottom or right
#include<iostream>
using namespace std;
int f(int i,int j,int m,int n){
    if(i==m-1 && j==n-1) return 1;
    if(i>=m || j>=n) return 0;
    return f(i+1,j,m,n)+f(i,j+1,m,n);
}

main(){
    int m,n;
    cout<<"Give dimensions: ";
    cin>>m>>n;
    cout<<"\n Total path: "<<f(0,0,m,n);
}