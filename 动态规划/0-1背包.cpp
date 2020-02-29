#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int maxN=1000;
int lev1,lev2,m,n,V,t[maxN],a,weight[maxN],value[maxN],dp[maxN];
int main(){
    scanf("%d%d%d%d",&lev1,&lev2,&m,&n);
    for(int i=1;i<=n;i++) scanf("%d",&t[i]);
    for(int i=1;i<=m;i++) {
        scanf("%d%d",&a,&value[i]);
        weight[i]=t[a]*(lev2/lev1);
    }
    scanf("%d",&V);
    for(int i=1;i<=m;i++){
        for(int j=V;j>=weight[i];j--)
        dp[j]=max(dp[j],dp[j-weight[i]]+value[i]);
    }
    cout<<dp[V];
    return 0;


}