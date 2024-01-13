#include<iostream>
using namespace std;

void fibonac(int n){
    int dp[n+1];
    dp[0]=0;
    dp[1]=1;
    for(int k=2;k<=n;k++)
        dp[k]=dp[k-1]+dp[k-2];
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