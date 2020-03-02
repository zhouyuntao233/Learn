#include<iostream>
using namespace std;
int cnt,n,arr[1000];
void compute(int n){
    if(arr[n]!=0) {
        cnt+=arr[n];
        return;
    }
    n=n/2;
    cnt+=n;
    for(int i=2;i<=n;i++) {
    int pre=cnt;
    compute(i);
    arr[i]=cnt-pre;
    }

}
int main(){
    cin>>n;
    cnt=1;
    compute(n);
    cout<<cnt;
    return 0;

}