#include <bits/stdc++.h>
using namespace std;
int sum(int a[], int n)
{
    return (n < 0) ? 0 : sum(a, n - 1) + a[n - 1];
}
void reverse(int a[],int l,int r){
    if(l<r) {
        swap(a[l],a[r]);
        reverse(a,l+1,r-1);
    }
}
int main(){
    int a[5];
    for(int i=0;i<5;i++) a[i]=i;
    cout<<sum(a,5)<<endl;
    reverse(a,0,4);
    for(int i=0;i<5;i++) cout<<a[i];
    cout<<endl;
    return 0;
}