#include<iostream>
using namespace std;


int main(){
    double s=0,x=0,a=7,sum=0;
    cin>>s>>x;
    while(sum<=s+x){
        if(sum>=s-x){
            //如果一秒后任未脱险
            if(sum+a<=s+x){
                cout<<"y";
                return 0;
            }
        }
        sum+=a;
        a=a*0.98;
    }
    cout<<"n";
    return 0;

}
