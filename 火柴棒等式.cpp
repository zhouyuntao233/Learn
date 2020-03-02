#include<iostream>
using namespace std;
int map[10]={6,2,5,5,4,5,6,3,7,6};

int f(int x){
    if(x==0) return 6;
    int sum=0;
    while(x>0){
        sum+=map[x%10];
        x/=10;
    }
    return sum;
}
int main(){
    int n=0,cnt=0;
    scanf("%d",&n);//读入总火柴的
 
    for(int i=0;i<1000;i++){
        for(int j=0;j<1000;j++){
            if((f(i)+2+f(j)+2+f(i+j))==n){
                ++cnt;
            }
        }
    }
    cout<<cnt;
    return 0;

}