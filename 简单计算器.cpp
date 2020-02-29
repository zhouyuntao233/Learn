#include<bits/stdc++.h>
using namespace std;

string str;//存储输入的字符串
stack<char>s;//存储操作符
stack<double>ca;
queue<char>q;//存储后缀表达式
map<char,int>op;
//中缀表达式转后缀表达式
void change(){
    int tmp=0;
    for(int i=0;i<str.length();i++){
        if(str[i]>='0'&&str[i]<='9'){
           tmp=str[i]-'0';
           q.push(str[i]);
        }
        else{
            while(!s.empty() && op[s.top()]>op[str[i]]){
                q.push(s.top());
                s.pop();
            }
            s.push(str[i]);
        }
    }
    while(!s.empty()) {
    q.push(s.top());
    s.pop();
    }
}
float calcu ( float a, float b ,char opr) { //执行二元运算
   switch ( opr ) {
      case '+' : return a + b;
      case '-' : return a - b;
      case '*' : return a * b;
      case '/' : if ( 0==b ) exit ( -1 ); return a/b; //注意：如此判浮点数为零可能不安全
      case '^' : return pow ( a, b );
      default  : exit ( -1 );
   }
}
double Cal(){
    while(!q.empty()){
        if(q.front()>='0'&&q.front()<='9'){
            ca.push(q.front()-'0');
        }
        else{
            double tmp1=ca.top();
            ca.pop();
            double tmp2=ca.top();
            ca.pop();
            ca.push(calcu(tmp1,tmp2,q.front()));
        }
        q.pop();
    }
}
int main(){
    cout<<"请输入表达式：";
    cin>>str;
    op['+']=op['-']=1;
    op['*']=op['/']=2;
    change();
    cout<<"后缀表达式为：";
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
    change();
    Cal();
    cout<<"计算结果是  ："<<ca.top();
    cout<<endl;
    return 0;

}