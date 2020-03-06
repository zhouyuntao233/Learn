#include<bits/stdc++.h>
using namespace std;

int n;
bool col[100];//列是否可以访问
bool l_d[100];//左对角线是否可以访问
bool r_d[100];//右对角线是否可以访问
int a[100],cnt;
void dfs(int l){
    if(l>n){
        ++cnt;
        if(cnt<=3){
        for(int i=1;i<=n;i++) 
        cout<<a[i]<<" ";
        cout<<endl;
        }
    }
    else{
        for(int i=1;i<=n;i++){
            if(!col[i]&&!l_d[l-i+n]&&!r_d[l+i]){
                col[i]=true;
                l_d[l-i+n]=true;
                r_d[l+i]=true;
                a[l]=i;
                dfs(l+1);
                col[i]=false;
                l_d[l-i+n]=false;
                r_d[l+i]=false;
            }

        }
    }

}
int main(){
    
    scanf("%d",&n);
    dfs(1);
    cout<<cnt;


    return 0;
}