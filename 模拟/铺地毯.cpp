#include<bits/stdc++.h>
using namespace std;

const int maxN=1e5+5;
struct node{
    int x;
    int y;
    int xlen;
    int ylen;
}tag[maxN];
int main(){
    //读入数据
   int a,b,j,k,n,x,y; scanf("%d",&n);
   for(int i=0;i<n;i++){
       scanf("%d%d%d%d",&a,&b,&j,&k);
       tag[i].x=a;
       tag[i].y=b;
       tag[i].xlen=j;
       tag[i].ylen=k;
   }
   scanf("%d%d",&x,&y);

   for(int i=n-1;i>=0;i--){
       if(x>=tag[i].x&&y>=tag[i].y&&tag[i].x+tag[i].xlen>=x&&tag[i].y+tag[i].ylen>=y){
           cout<<i+1;
           return 0;
       }
       
   }

   cout<<-1;

    return 0;
}