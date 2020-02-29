#include<iostream>
#include<string.h>
using namespace std;
const int maxN=10000010;
int n,m;
int arr[maxN],diff[maxN],need[maxN],add[maxN],l[maxN],r[maxN];
bool judge(int x){
    memset(diff,0,sizeof(diff));
    for(int i=1;i<=x;i++){
        diff[l[i]]+=add[i];
        diff[r[i]+1]-=add[i];
    }
    for(int i=1;i<=n;i++){
        need[i]=need[i-1]+diff[i];
        if(need[i]>arr[i]) return 0;
    }
    return 1;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
    for(int i=1;i<=m;i++) scanf("%d%d%d",&add[i],&l[i],&r[i]);
    int left=1,right=m;
    if(judge(m)) { cout<<"0";return 0;}
    while(left<right){
        int mid=(left+right)/2;
        if(judge(mid)) left=mid+1;
        else right=mid;
    }
    cout<<"-1"<<endl<<left;
    return 0;

}