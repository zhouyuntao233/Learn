#include<bits/stdc++.h>
using namespace std;
int n,a;
int main(){

    //读入数据
    scanf("%d",&n);
    for(int i=0;i<=n;i++) {
        scanf("%d",&a);
        if(a==0) continue;
        //如果是正数则写加号 第一项不用写
        else{
            if(i==0) {
                if(a==1) cout<<"x^"<<n-i;
                else cout<<a<<"x^"<<n-i;
            }
            //如果是正数
            else if(a>0&&i!=0) {
                if(i==n) cout<<'+'<<a;
                else{
                if(a==1) cout<<"+x^"<<n-i;
                else cout<<'+'<<a<<"x^"<<n-i;
                }
            }
            //如果是负数
            else {
                if(i==n) cout<<a;
                else {
                    if(a==-1) cout<<"-x^"<<n-i;
                    else cout<<a<<"x^"<<n-i;
                }
            }
        }
    }

   
    return 0;
}