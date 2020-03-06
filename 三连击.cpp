#include <iostream>
using namespace std;

int Sum(int x)
{
    return x / 100 + x % 100 / 10 + x % 10;
}
int Mul(int x)
{
    return (x / 100) * (x % 100 / 10) * (x % 10);
}
int main()
{
    int A = 0, B = 0, C = 0, flag = 0;
    scanf("%d%d%d", &A, &B, &C); //读入三个数的比例
    for (int i = 123; i <= 987; i++)
    {
        //如果第一个数不能整除A 说明成不了比例关系
        if (i % A == 0)
        {
            int y = (i / A) * B; //按比例计算第二个数
            int z = (i / A) * C; //按比例计算第三个数
            //如果超过三位数剪枝
            if (y < 1000 && z < 1000)
            {
                //判断是否1-9 数字都有
                if (Sum(i) + Sum(y) + Sum(z) == 45 && Mul(i) * Mul(y) * Mul(z) == 362880)
                {
                    flag = 1;
                    cout << i << " " << y << " " << z << endl;
                }
            }
        }
    }
    if(flag==0) cout<<"No!!!"<<endl;
    return 0;
}