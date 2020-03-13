#include<bits/stdc++.h>
 
using namespace std;
 

#define LL long long
const int N=100010;

 
struct node {
    LL h , pos;//pos为当前矩形的最左端点
}a[N];
 
LL n,maxx=0,pos;
stack<node> q;
 
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++){

        scanf("%d",&a[i].h);
        a[i].pos=i;//每个小矩形的左端点初始化为自己，并记录每个矩形的高度
    }
    for(int i=1;i<=n+1; i++) {
        if(q.empty() || q.top().h<a[i].h)//如果栈是空的或栈是递增的，继续入栈
            q.push(a[i]);
        else if(q.top().h!=a[i].h) {
            int pos1;//pos1为记录新加入栈的矩形的左端点
            while(!q.empty()&&q.top().h>a[i].h) {
                node x=q.top();//x记录栈顶元素
                LL sum=0;//sum统计当前最大矩形面积
                q.pop();
                sum=x.h*(i-x.pos);//右端点为i，左端点为pos
                printf("当前面积 底:%d 高：%d\n",i-x.pos,x.h);
                maxx=max(maxx,sum);//记录答案
                pos1=x.pos;//继承左端点
            }
            node G;//把新元素放入栈
            G.h=a[i].h;
            G.pos=pos1;
            q.push(G);
        }
    }
    cout<<maxx;
    return 0;
}