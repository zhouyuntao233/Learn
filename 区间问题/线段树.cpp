#include<iostream>
using namespace std;
const int maxN = 10000;
int arr[maxN], tree[maxN],mark[maxN];
//建树操作
void build(int node, int l, int r) {
	int mid = (l + r) / 2;
	int lchild = (node << 1) + 1;
	int rchild = (node << 1) + 2;
	if (l == r) tree[node] = arr[l];
	else {
		build(lchild, l, mid);
		build(rchild, mid + 1, r);
		tree[node] = tree[lchild] + tree[rchild];
	}
}
//lazytag下放一层
void push_down(int node, int l, int r) {
	int mid = (l + r) / 2;
	int lchild = (node << 1) + 1;
	int rchild = (node << 1) + 2;

	mark[lchild] += mark[node];
	mark[rchild] += mark[node];

	tree[lchild] += (mid - l + 1)*mark[node];
	tree[rchild] += (r - mid)*mark[node];

	mark[node] = 0;

}
//将【ql,qr】区间内的每个数加上k
void update(int node, int l, int r, int ql, int qr, int k) {
	int mid = (l + r) / 2;
	int lchild = (node << 1) + 1;
	int rchild = (node << 1) + 2;
	if (qr<l || ql>r) return;
	else if (ql <= l && r <= qr) {
		tree[node] += (r-l+1)*k;
		if (l < r)
			mark[node] += k;
	}
	else {
		//如果有lazytag就传递下去
		if(mark[node])
		push_down(node, l, r);

		update(lchild, l, mid, ql, qr, k);
		update(rchild, mid + 1, r, ql, qr, k);
		tree[node] = tree[lchild] + tree[rchild];
	}
}

int query(int node, int l, int r, int ql, int qr) {
	int mid = (l + r) / 2;
	int lchild = (node << 1) + 1;
	int rchild = (node << 1) + 2;
	//如果不在查询区间返回0
	if (ql > r || qr < l) return 0;
	//如果在查询区间内 返回当前节点值
	else if (ql <= l && r <= qr) {
		return tree[node];
	}
	//如果与查询区间有重合，一分为二再进行查询
	else {
		if(mark[node]) push_down(node, l, r);
		return query(lchild, l, mid, ql, qr) + query(rchild, mid + 1, r, ql, qr);

	}
}
int main() {
	int n=0, m=0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	build(0, 0, n - 1);
	for (int i = 0; i < m; i++) {
		int opr = 0, x = 0, y = 0, k = 0;
		cin >> opr;
		if (opr == 1) {
			cin >> x >> y >> k;
			update(0, 0, n - 1, x-1, y-1, k);
		}
		else {
			cin >> x >> y;
			cout << query(0, 0, n - 1, x - 1, y - 1)<<endl;
		}

	}

}