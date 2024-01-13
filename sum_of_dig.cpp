#include<iostream>
using namespace std;

int sumofdig(int n){
    if(n>=0 && n<=9) return n;
    return sumofdig((n/10)) + (n%10);
}

main(){
    cout<<"Give a number: ";
    int n;
    cin>>n;
    cout<<"\n Sum of digits: "<<sumofdig(n);
}