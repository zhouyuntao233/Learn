#include<bits/stdc++.h>
using namespace std;
map<string,int> m;

int main(){
    m["zero"]=0;
    m["one"]=1;
    m["two"]=2;
    m["three"]=3;
    m["four"]=4;
    m["five"]=5;
    m["six"]=6;
    m["seven"]=7;
    m["eight"]=8;
    m["nine"]=9;
    m["ten"]=10;
    m["eleven"]=11;
    m["twelve"]=12;
    m["thirteen"]=13;
    m["fourteen"]=14;
    m["fifteen"]=15;
    m["sixteen"]=16;
    m["seventeen"]=17;
    m["eighteen"]=18;
    m["nineteen"]=19;
    m["twenty"]=20;
    string s;
    int arr[20];
    int i=0;
    while(cin>>s){
        if(s[0]=='.') break;
        if(m[s]!=0) arr[i++]=(m[s]*m[s])%100;
    }
    sort(arr,arr+i);
    for(int j=0;j<i;j++){
        cout<<arr[j];
    }
   
    return 0;
}