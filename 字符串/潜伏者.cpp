#include<bits/stdc++.h>
using namespace std;
map<char,char>m;
string s,e,q;
int main(){
    cin>>s>>e>>q;
    for(int i=0;i<s.length();i++){
        
        if(m[s[i]]=='\0') m[s[i]]=e[i];
        else{
            if(e[i]!=m[s[i]]){
            cout<<"Failed";
            return 0;
            }
        }
    }
    for(int i=0;i<q.length();i++){
        if(m[q[i]]!='\0') q[i]=m[q[i]];
        else {
            cout<<"Failed";
            return 0;
        }
    }
    for(int i=0;i<q.length();i++) cout<<q[i];
    return 0;
    
}