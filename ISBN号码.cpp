#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int k=0,sum=0;
    char flag;
    string s;cin>>s;
    for(int i=0;i<s.length()-1;i++){
        if(s[i]!='-'){
            ++k;
            sum+=k*(s[i]-'0');

        }
    }
    sum=sum%11;
    char last=s[s.length()-1];

    if((sum==(last-'0'))||(sum==10 && last=='X')) cout<<"Right";
    else {
        if(sum==10)
         cout<<s[0]<<s[1]<<s[2]<<s[3]<<s[4]<<s[5]<<s[6]<<s[7]<<s[8]<<s[9]<<s[10]<<s[11]<<'X';
         else
         cout<<s[0]<<s[1]<<s[2]<<s[3]<<s[4]<<s[5]<<s[6]<<s[7]<<s[8]<<s[9]<<s[10]<<s[11]<<sum;

    }
   
    
    return 0;
    
}
