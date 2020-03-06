#include<bits/stdc++.h>
using namespace std;


int n;
bool vis[1000];
int a[1000];
void dfs(int l){
    if(l>n) {
        for(int i=1;i<=n;i++)
         cout<<setw(5)<<a[i];
        cout<<endl;
    }
    else
    {
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                vis[i]=true;
                a[l]=i;
                dfs(l+1);//dfs下一层
                vis[i]=false;
           }
        }
    }
    

}

int main(){

    scanf("%d",&n);
    dfs(1);
    return 0;
}