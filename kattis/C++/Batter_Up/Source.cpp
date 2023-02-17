#include<bits/stdc++.h>

using namespace std;
typedef long long i64;

int main() {
	i64 n, a;
	double crt = 0, sum = 0;
	cin >> n;
	for (i64 i = 0; i < n; i++) {
		cin >> a;
		if (a >= 0) {
			crt++;
			sum += a;
		}
	}
	cout.precision(5);
	cout << fixed << sum / crt << endl;
}