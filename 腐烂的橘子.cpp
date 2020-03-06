#include<bits/stdc++.h>
using namespace std;


int orangesRotting(vector<vector<int>>& grid) {

    int row=grid.size();//获取原数组的行
    int col=grid[0].size();//获取原数组的
    int cnt=0,level=0;//统计好橘子数量
    int dis[row][col]={};//初始化为0；
    int dir_x[4]={0,1,-1,0};
    int dir_y[4]={1,0,0,-1};
    queue<pair<int,int> > q;//定义一个队列 用来存坏橘子的
  
    for(int i=0;i<row;i++)
       for(int j=0;j<col;j++)
          dis[i][j]=-1;
    //扫描出腐烂橘子的位置
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            //如果这个位置没有橘子 跳过本次循环
            if(grid[i][j]==0) continue;
            //如果有一个好橘子 好橘子数加一
            else if(grid[i][j]==1) ++cnt;
            //如果是坏橘子 标记为0 并且将它加到坏橘子队列 方便下次感染其他橘子
            else{
                dis[i][j]=0;//这类橘子作为第一波感染者
                q.push(make_pair(i,j));
            }  
        }
    }
    while(!q.empty()){
        pair<int,int> v=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int x_next=v.first+dir_x[i];
            int y_next=v.second+dir_y[i];
            if(x_next<0||x_next>=row||y_next<0||y_next>=col||grid[x_next][y_next]!=1||(dis[x_next][y_next]>=0))
            continue;

            dis[x_next][y_next]=dis[v.first][v.second]+1;
            q.push(make_pair(x_next,y_next));
            --cnt;
            level=dis[x_next][y_next];

            if(cnt==0) break;    
        }
        
    }
    return (cnt>0) ? -1:level;
  

}
int main(){
        vector<vector<int> > grid;
    vector<int> a0;
    vector<int> a1;
    vector<int> a2;
    a0.push_back(2);
    a0.push_back(1);
    a0.push_back(1);
    a1.push_back(1);
    a1.push_back(1);
    a1.push_back(0);
    a2.push_back(0);
    a2.push_back(1);
    a2.push_back(1);

    grid.push_back(a0);
    grid.push_back(a1);
    grid.push_back(a2);
    orangesRotting(grid);
}


