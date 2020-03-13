#include<bits/stdc++.h>
using namespace std;


int numTimesAllBlue(vector<int>& light) {
        
        int size=light.size();
        set<int> S;
        int flag=0;
        
        for(int i=0;i<size;i++){
            S.insert(light[i]);
            auto it=S.end();
            if(*(--it)==i+1) ++flag;
        
        }
        return flag;

}
int main(){
    vector<int> v;
    v.push_back(2);
    v.push_back(1); 
    v.push_back(3);
    v.push_back(4);
     v.push_back(5);

    numTimesAllBlue(v);

}