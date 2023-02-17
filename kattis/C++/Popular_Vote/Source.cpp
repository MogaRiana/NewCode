#include<bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef vector<i64> vi64;

int main() {
	i64 t, n;
	cin >> t;
	for (i64 i = 0; i < t; i++) {
		cin >> n;
		i64 win = 0, a, crt = 0, crtw = 1;
		vi64 v(n);
		for (i64 j = 0; j < n; j++) {
			cin >> v[i];
			crt += v[i];
			if (v[i] > win) {
				win = v[i];
				a = j;
				crtw = 1;
			}
			else if (v[i] == win) {
				crtw++;
			}
		}
		crt /= 2;
		if (crtw >= 2) {
			cout << "no winner" << endl;
			continue;
		}
		if (win > crt) {
			cout << "majority winner " << a + 1 << endl;
		}
		else {
			cout << "minority winner " << a + 1 << endl;
		}
	}
	return 0;
}