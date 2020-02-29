#include <iostream>
#include <algorithm>
using namespace std;
const int maxN = 4000;
int n, V, max_value;
struct node
{
    int weight;
    int value;
} w[maxN];
void DFS(int index, int cw, int cv)
{
    if (index == n)
    {
        if (cw <= V && cv > max_value)
        {
            max_value = cv;
        }
        return;
    }
    DFS(index + 1, cw, cv);
    if (cw + w[index].weight <= V)
    {
        DFS(index + 1, cw + w[index].weight, cv + w[index].value);
    }
}
int main()
{

    cin >> n >> V;
    for (int i = 0; i < n; i++)
    {
        cin >> w[i].weight >> w[i].value;
    }
    DFS(0, 0, 0);
    cout << max_value;

    return 0;
}