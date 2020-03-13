#include<bits/stdc++.h>
using namespace std;
int n ,a[10000];

int main(){
    scanf("%d",&n);
    
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    sort(a,a+n);

    map<int,int> m;
    int max=0,maxn=0;
    for(int i=0;i<n;i++){
        ++m[a[i]];
        if(m[a[i]]>max){
            max=m[a[i]];
            maxn=a[i];
        }
    }

    cout<<maxn;
    return 0;
    

}