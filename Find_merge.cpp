#include<iostream>
using namespace std;
const int maxn=10010;
int fa[maxn];
int r[maxn];
int N,M,a1,a2,a3;
inline void init(int n){
    for(int i=1;i<=n;i++) fa[i]=i;
}
int find(int x){
    if(fa[x]==x) return x;
    else {
        fa[x]=find(fa[x]);
        return fa[x];
    }
   // return fa[x]==x ? x:fa[x]=find(fa[x]);
}
void merge(int a,int b){
    fa[find(a)]=find(b);  
}
int main(){
    cin>>N>>M;
    init(N);
    for(int i=0;i<M;i++){
        cin>>a1>>a2>>a3;
        if(a1==1) merge(a2,a3);
        else {
            if(find(a2)==find(a3)) cout<<"Y"<<endl;
            else cout<<"N"<<endl;
        }
    }
    return 0;
}