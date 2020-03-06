#include<iostream>
using namespace std;
bool isPrime(int x) {
	if (x < 2) return 0;
	for (int i = 2; i*i <= x; i++) {
		if (x%i == 0) return 0;
	}
	return 1;
}
int main() {
	int n; cin >> n;
	int flag=0;
		for (int i = 0; i<n; i++) {
            if(isPrime(i))
			for (int j = 0; j <n; j++) {
				if (isPrime(j)&& isPrime(n -i-j)) {
					cout << i <<" "<<j<<" "<<  n - i-j << endl;
					return 0;
				}
			}
		}


	return 0;
}



// #include<iostream>
// using namespace std;
// bool isPrime(int x) {
// 	if (x < 2) return 0;
// 	for (int i = 2; i*i <= x; i++) {
// 		if (x%i == 0) return 0;
// 	}
// 	return 1;
// }
// int a[1000];
// int main() {
// 	int n; cin >> n;
// 	int flag=0;
// 	for (int i = 0; i <= n; i++) {
// 		if (isPrime(i)) a[flag++] = i;
// 	}
	
// 		for (int j = 0; j < flag / 2; j++) {
// 			for (int k = 0; k < flag / 2; k++) {
// 				if (isPrime(n - a[j]-a[k])) {
// 					cout << a[j] <<" "<<a[k]<<" "<<  n - a[j]-a[k] << endl;
// 					return 0;
// 				}
// 			}
// 		}


// 	return 0;
// }