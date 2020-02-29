#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int maxN=1000;
int weight[maxN],value[maxN];
long long dp[maxN];
int n,V;
int main(){
    
    scanf("%d%d",&V,&n);
    for(int i=1;i<=n;i++) {
        scanf("%d%d",&weight[i],&value[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=V;j>=weight[i];j--)
          dp[j]=max(dp[j],dp[j-weight[i]]+weight[i]*value[i]);
    }
    cout<<dp[V];
   
    return 0;

}