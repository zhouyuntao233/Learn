#include<bits/stdc++.h>
using namespace std;
bool group[20][20],vis[20][20];
int px[]={-1,0,1,0};
int py[]={0,-1,0,1};
int n,m,sx,sy,ex,ey,flag;
void dfs(int x,int y){
    if(x==ex&&y==ey){
        ++flag;
        return;
    }
    else{
        for(int i=0;i<4;i++){
            int x_next=x+px[i];
            int y_next=y+py[i];
            if(x_next>=1&&y_next>=1&&x_next<=ex&&y_next<=ey&&!group[x_next][y_next]&&!vis[x_next][y_next]){
                vis[x_next][y_next]=true;
                dfs(x_next,y_next);
                vis[x_next][y_next]=false;
            }
        }
    }    
}
int main(){
    int t=0,X=0,Y=0;
    scanf("%d%d%d",&n,&m,&t);
    scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
    while(t--){
        scanf("%d%d",&X,&Y);
        group[X][Y]=true;
    }
    dfs(sx,sy);
    cout<<flag<<endl;
    return 0;


}