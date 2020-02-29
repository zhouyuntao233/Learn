#include<iostream>
using namespace std;
#define lowbit(x) ((x)&(-x))
const int maxN = 50000;
int a[maxN], t[maxN], m, n;

void update(int x, int k) {
	while (x <= n) {
		t[x] += k;
		x += lowbit(x);
	}
}
int sum(int x) {
	int ret = 0;
	while (x > 0) {
		ret += t[x];
		x -= lowbit(x);
	}
	return ret;
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		update(i, a[i]);
	}
	for (int i = 1; i <= m; i++) {
		int opr = 0, a = 0, b = 0;
		cin >> opr >> a >> b;
		if (opr == 1) update(a, b);
		else cout << sum(b) - sum(a - 1)<<endl;
	}
	return 0;
}