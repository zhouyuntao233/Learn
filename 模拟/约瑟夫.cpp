#include<iostream>
#include<queue>
using namespace std;
int main(){
    int n=0,m=0,a=0;
    queue<int> q;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
       q.push(i);
    }
    while(!q.empty()){
    for(int i=0;i<m-1;i++){
       q.push(q.front());
       q.pop();
    }
    cout<<q.front()<<" ";
    q.pop();
    }
    return 0;
}
