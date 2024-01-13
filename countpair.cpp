#include <iostream>
using namespace std;
#include <unordered_map>

main(){
int n;
cout<<"\n Give size of the array: ";
cin>>n;
int ar[n],k=0;
while(k<n){
    cout<<"\n Give element no. "<<k+1<<": ";
    cin>>ar[k++];
}
cout<<"\n Given elemnts are:- ";
k=0;
while(k<n)
    cout<<ar[k++]<<" ";

//counting pairs using brute force
// int i=0,j,co=0;
// while(i<n){
//     j=i+1;
//     while(j<n){
//         if(ar[i]==ar[j])
//         co++;
//         j++;
//     }
//     i++;
// }

//counting pairs using map in c++ library
unordered_map<int,int> m;
int co=0;
for(int k=0;k<n;k++)
m[ar[k]]++;
cout<<"\nElement Frequency"<<endl;
for(auto i:m){
    cout<<i.first<<"\t"<<i.second<<endl;
    if(i.second==2)
    co++;
    }

cout<<"\n Number of pairs in array: "<<co;
}