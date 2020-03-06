#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    stack<char> st;
    cin>>s;
    if(s[0]=='-'){
        for(int i=1;i<s.length();i++) st.push(s[i]);
        while(st.top()=='0') st.pop();
        cout<<"-";
    }
    else{
        for(int i=0;i<s.length();i++)  st.push(s[i]);
        while(st.top()=='0') st.pop();
    }
    while(!st.empty()) {
        cout<<st.top();
        st.pop();
    }
}