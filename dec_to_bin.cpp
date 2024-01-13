#include<iostream>
using namespace std;

int bin_conv(int);

main(){
    int n;
    cout<<"\n Give a decimal number: ";
    cin>>n;
    //int m=n;
    cout<<"\n Binary conversion of "<<n<<" is: "<<bin_conv(n);
}

int bin_conv(int num){
    int ans=0,pow=1;
    while(num!=0){
        int parity=num%2;
        ans+=parity*pow;
        pow*=10;
        num/=2;
    }
    return ans;
}