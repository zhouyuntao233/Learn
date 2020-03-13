#include<bits/stdc++.h>
using namespace std;
bool canThreePartsEqualSum(vector<int>& A) {
    
    int size=A.size();
    int sum=0,subsum=0,flag=0;
    for(int i=0;i<size;i++){
        sum+=A[i];
    }
    if(sum%3!=0) return false;
    for(int i=0;i<size;i++){
        subsum+=A[i];
        if(subsum==sum/3){
            ++flag;
            subsum=0;
        } 
        if(flag==3) return true;
        
    }

    return false;
}
int main(){
    // vector<int> a;
    // a.push_back(10);
    // a.push_back(-10);
    // a.push_back(10);
    // a.push_back(-10);
    // a.push_back(10);
    // a.push_back(-10);
    // a.push_back(10);
    // a.push_back(-10);
    // cout<<canThreePartsEqualSum(a);
    int x=0x41c8f5c3;
    float i=*(float*)&x;
    cout<<i;
    

}