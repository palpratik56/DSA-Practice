#include<iostream>
#include<vector>
using namespace std;

void dis(vector<vector<int>> &v){
for(auto row:v){
        for(auto col:row){
            cout<<col<<" ";
        }
        cout<<endl;
    }
}

void rotate(vector<vector<int>> &v){
    for(int i=0;i<v.size();i++){
        for(int j=0;j<i;j++){
            swap(v[i][j],v[j][i]);
        }
    }
    //reversing the transposed matrix
    for(int i=0;i<v.size();i++){
        for(int j=0;j<=i;j++){
            swap(v[i][j],v[i][v[i].size()-1-j]);
        }
    }
        
}

main(){
    int n;
    cout<<"\n Give matrix dimension: ";
    cin>>n;
    cout<<"\n Input elements: ";
    vector<vector<int>> vec(n,vector<int> (n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>vec[i][j];
        }
    }
    cout<<"\nThe matrix is:-"<<endl;
    dis(vec);
    cout<<"\nAfter 90 rotation matrix is:-"<<endl;
    rotate(vec);
    dis(vec);
   
}
