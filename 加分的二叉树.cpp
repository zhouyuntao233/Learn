#include<bits/stdc++.h>
using namespace std;
int n,a[1000],m[40][40],root[40][40];
//求区间L,R之间的最大分数
long long dfs(int L,int R){
    //最大值 要定义在函数内
    //如果定义在全局变量的话，那就不是L R之间的最大值，就是全局的最大值
    long long maxn=0;
    //递归边界条件
    if(L>R) return 1;
    if(L==R) return a[L];
    if(m[L][R]) return m[L][R];
    //递归思想 枚举这个L到R的区间内的每个数，分别作为根节点 求最大值
    for(int i=L;i<=R;i++){
  
        long long tmp=dfs(L,i-1)*dfs(i+1,R)+a[i];// 选定一个根节点 分别去找它左区间和有区间的最大值
        
        if(tmp>maxn){
        root[L][R]=i;
        maxn=tmp;
        }
    }
    //把这个区间里的最大值存起来
    m[L][R]=maxn;
    
    //cout<<"区间"<<L<<" "<<R<<"根节点"<<root[L][R]<<"  最大值"<<maxn<<endl;

    //遍历结束 返回这个区间的最大值
    return maxn;
}
void pre_root(int L,int R){
    if(L>R) return;
    if(L==R) {
       // root[L][R]=L;
        return;
    }
    int flag=0,Min=1e5;
    for(int i=L;i<=R;i++){
        if(a[i]<Min) {
            Min=a[i];
            flag=i;
        }
    }
    root[L][R]=flag;
    pre_root(L,flag-1);
    pre_root(flag+1,R);
}
long long cal(int L,int R){
    if(L>R) return 1;
    if(L==R) return a[L];

    return cal(L,root[L][R]-1)*cal(root[L][R]+1,R)+a[root[L][R]];
}
void pre(int L,int R){
    if(L>R) return;//左树为空
    //到达叶子节点
    if(L==R) {
        cout<<L<<" ";
        return ;
    }
    cout<<root[L][R]<<" ";
    pre(L,root[L][R]-1);
    pre(root[L][R]+1,R);

}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
   // cout<<dfs(1,n);
   // pre(1,n);
    pre_root(1,n);
    cout<<cal(1,n)<<endl;
    pre(1,n);
   
  
   

    return 0;

}