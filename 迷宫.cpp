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
            //如果下一个（x，y)没有越界 并且不是障碍点 并且没有访问过
            if(x_next>=1&&y_next>=1&&x_next<=n&&y_next<=m&&!group[x_next][y_next]&&!vis[x_next][y_next]){
                vis[x_next][y_next]=true;//将格子设为走过
                dfs(x_next,y_next);//递归去走左边
                vis[x_next][y_next]=false;//状态回朔 并将格子设为没走过
            }
        }
    }    
}
int main(){
    int t=0,X=0,Y=0;
    //读入迷宫的行和列 以及障碍点的个数
    scanf("%d%d%d",&n,&m,&t);
    //读入起始坐标
    scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
    while(t--){
        scanf("%d%d",&X,&Y);
        group[X][Y]=true;
    }
    dfs(sx,sy);
    cout<<flag<<endl;
    return 0;


}