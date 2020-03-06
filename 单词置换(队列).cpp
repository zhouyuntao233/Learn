#include<bits/stdc++.h>
using namespace std;
int arr[1000],q[1000];
bool isTrue[1000];
//引入标记 以空间换时间
int main(){
    //读入数组及初始化
    int head=1,tail=0;
    int n=0,m=0,cnt=0; scanf("%d%d",&m,&n);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
 
    for(int i=0;i<n;i++){
        
       
        if(isTrue[arr[i]]==false){
            ++tail;
            if(tail-head>=m) {
                isTrue[q[head]]=false;//更新标记为未出现过
                ++head;
            }
            q[tail]=arr[i];
            
            isTrue[arr[i]]=true;//更新标记为存在
         
        }
    }
    cout<<tail;

    return 0;
}


//时间复杂版本 因为每次都要扫一遍 看有没有出现过
// int main(){
//     //读入数组及初始化
//     int head=1,tail=0;
//     int n=0,m=0,cnt=0; scanf("%d%d",&m,&n);
//     for(int i=0;i<n;i++) scanf("%d",&arr[i]);
 
//     for(int i=0;i<n;i++){
//         int flag=0;
//         for(int j=head;j<=tail;j++){
//             if(q[j]==arr[i]) flag=1;
//         }
//         if(flag==0){
//             ++tail;
//             if(tail-head>=m) ++head;
         
//             q[tail]=arr[i];
         
//         }
//     }
//     cout<<tail;

//     return 0;
// }