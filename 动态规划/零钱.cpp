#include<bits/stdc++.h>
using namespace std;
int coinChange(vector<int>& coins, int amount) {
    int size=coins.size();
    int dp[10][20]={0};
    for(int i=1;i<=amount;i++) dp[0][i]=10000;
    for(int i=1;i<=size;i++){
        for(int j=1;j<=amount;j++){
            
            if(j>=coins[i-1]) 
            dp[i][j]=min(dp[i-1][j],dp[i][j-coins[i-1]]+1);
            else
            dp[i][j]=dp[i-1][j];
            
            
        }
    }
    return dp[size][amount];
}
string generateTheString(int n) {

    int a=0,b=0; 
    for(int i=1;i<=n;i++)
        if(i%2!=0){
            for(int j=1;j<=n;j++){
                if(j%2!=0){
                    if(i+j==n) {
                        a=i;
                        b=j;  
                    }
                }
            }
        }
    string s(a+b,' ');
    int i=0;
    while(a--){
        s[i]='p';
        ++i;
        
    }

    while(b--){
        s[i]='z';
        ++i;
        
        
    }
    return s;
}

int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(5);
cout<<coinChange(v,11);
//cout<<generateTheString(4);
}