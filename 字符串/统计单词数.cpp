#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    string a, b;
    int cnt = 0, p = -1, l, r;
    getline(cin, a);
    getline(cin, b);
    int la = a.length();
    int lb = b.length();
    for (int i = 0; i < la; i++) a[i]=towlower(a[i]);
    for (int i = 0; i < lb; i++) b[i]=towlower(b[i]);
    for (int i = 0; i < lb; i++)
    {
        //匹配单词的关键就是什么样的字符串算一个单词
        //如果是第一个单词 或者是字符前有空格的就是单词起始位置
        if (i == 0 || (b[i - 1] = ' '))
        {
            l = i;
            while (b[i] != ' ' && i < lb)   ++i;
            r = i - 1;
            //找到单词匹配a
            if(a==b.substr(l,r-l+1)){
                ++cnt;
                if (p == -1) p = l;
            }
        }
    }
    if (cnt == 0)
        cout << -1;
    else
        cout << cnt << " " << p;
    return 0;
}
// int main(){
//     string a,b;
//     getline(cin,a);
//     getline(cin,b);
//     a=' '+a+' ';
//     int flag=0,num=0;
//     //字符串全部变小写
//     for(int i=0;i<a.length();i++) a[i]=tolower(a[i]);
//     for(int i=0;i<b.length();i++) b[i]=tolower(b[i]);
//     if(b.find(a)==string::npos) cout<<-1;
//     else{
//         int first=b.find(a);
//         set<int> s;
//         while(b.find(a,num)!=string::npos){
//             s.insert(b.find(a,num));
//             ++flag;++num;

//         }
//         cout<<s.size()<<" "<<first;
//     }

//     return 0;
// }