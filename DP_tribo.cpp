#include<iostream>
using namespace std;

void fibonac(int n){
    int dp[n+1];
    dp[0]=dp[1]=0,dp[2]=1;
    for(int k=3;k<=n;k++)
        dp[k]=dp[k-1]+dp[k-2]+dp[k-3];
    for(int k=0;k<=n;k++)
    cout<<dp[k]<<" ";
}
main(){
    int num;
    cout<<"Give a number: ";
    cin>>num;
    cout<<"the series is: ";
    fibonac(num);
}