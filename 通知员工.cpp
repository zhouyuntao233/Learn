#include<bits/stdc++.h>
using namespace std;



int ans,h[100005],ne[100005],a[100005],d[100005];
void dfs(int x)
{
    ans=max(ans,d[x]);
    for(int i=h[x];~i;i=ne[i])
    {
        d[i]=d[x]+a[x];
        dfs(i);
    }
}
int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        memset(h,-1,sizeof(h));
        int i;
        for(i=0;i<n;i++)if(i!=headID)
        {
            ne[i]=h[manager[i]];
            h[manager[i]]=i;
        }
        for(i=0;i<n;i++)a[i]=informTime[i];
        d[headID]=ans=0;
        dfs(headID);
        return ans;
}