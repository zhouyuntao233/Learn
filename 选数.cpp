#include <iostream>
#include <cstdio>
using namespace std;

bool isprime(int a){//判断素数
    for(int i=2;i*i<=a;i++)//不想用sqrt，还要头文件
        if(a%i==0)//如果整除
            return false;//扔回false
    //程序都到这里的话就说明此为素数
    //否则就被扔回了
    return true;//扔回true
}

int n,k;
int a[25],flag;

void dfs(int step,int sum,int cnt){
    //递归出口
    if(step==n||cnt==k){
        if(isprime(sum)&&cnt==k) ++flag;
    }
    else{
        dfs(step+1,sum+a[step],cnt+1);//选这个数
        dfs(step+1,sum,cnt);//不选这个数
    }
}

int main(){
    scanf("%d%d",&n,&k);//输入

    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);//循环读入
    dfs(0,0,0);//调用函数
    printf("%d\n",flag);//输出答案
    return 0;//结束程序
}