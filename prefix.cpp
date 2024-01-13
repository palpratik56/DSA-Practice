// 48/2*3+3^5+1-
#include<iostream>
#include<stack>
#include<math.h>
using namespace std;

void swcase(char t,stack<int>&st,int a,int b){
    switch (t){
        case '+':
            st.push(a+b);
            break;
        case '-':
            st.push(a-b);
            break;
        case '*':
            st.push(a*b);
            break;
        case '/':
            st.push(a/b);
            break;
        case '^':
            st.push(pow(a,b));
            break;
    }
}

int evalexp(string s){
    int i=s.size()-1;
    stack<int> st;
    while(i>=0){
        if(s[i]>='0' && s[i]<='9')
            st.push(s[i]-'0');
        else{
            int op1=st.top();
            st.pop();
            int op2=st.top();
            st.pop();
            swcase(s[i],st,op1,op2);
        }
        //cout<<"\n Top element of st: "<<st.top();
        i--;
    }
    return st.top();
}
main(){
    string str = "+9*26";
    cout<<"\n Prefix evaluation is "<<evalexp(str);

}