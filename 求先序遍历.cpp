#include<bits/stdc++.h>
using namespace std;


string f,p,m;
//查找后序序列在中序遍历中的位置
int query(char c){
    for(int i=0;i<m.length();i++){
        if(c==m[i]) return i;
    }
}

//已知中序和后序 求前序
void dfs(int ml,int mr,int pl,int pr){
    if(ml>mr) return;
    if(ml==mr) {
        cout<<m[ml];
        return;
    }
    cout<<p[pr];
    int i=query(p[pr]);
    int rlen=mr-i;
    dfs(ml,i-1,pl,pr-rlen-1);
    dfs(i+1,mr,pr-rlen,pr-1);
}
int main(){
    cin>>m>>p;
    int size=m.length();
    dfs(0,size-1,0,size-1);
    return 0;

    
}