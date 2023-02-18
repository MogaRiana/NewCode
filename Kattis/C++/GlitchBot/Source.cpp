#include <bits/stdc++.h>

using namespace std;
typedef long long i64;

int main() {
	i64 n, x1, y1, x2 = 0, y2 = 0;
	cin >> x1 >> y1 >> n;
	i64 d = 1;
	vector<string> v(n);
	vector<string> c = { "Forward", "Right", "Left" };
	for (i64 i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (i64 j = 0; j < n; j++) {
		if (v[j] == c[0]) {
			for (i64 a = 1; a <= 2; a++) {
				string b = v[j];
				v[j] = c[a];
				for (i64 i = 0; i < n; i++) {
					if (v[i] == "Forward") {
						if (d == 1) {
							y2++;
						}
						else if (d == 2) {
							x2++;
						}
						else if (d == 3) {
							y2--;
						}
						else if (d == 4) {
							x2--;
						}
					}
					else if (v[i] == "Right") {
						d++;
						if (d == 5) {
							d = 1;
						}
					}
					else if (v[i] == "Left") {
						d--;
						if (d == 0) {
							d = 4;
						}
					}
				}
				if (x1 == x2 && y1 == y2) {
					cout << j + 1 << " " << v[j] << endl;
					return 0;
				}
				else {
					v[j] = b;
					x2 = 0;
					y2 = 0;
					d = 1;
				}
			}
		}
		if (v[j] == c[1]) {
			for (i64 a = 0; a <= 2; a++) {
				if (a == 1) {
					continue;
				}
				string b = v[j];
				v[j] = c[a];
				for (i64 i = 0; i < n; i++) {
					if (v[i] == "Forward") {
						if (d == 1) {
							y2++;
						}
						else if (d == 2) {
							x2++;
						}
						else if (d == 3) {
							y2--;
						}
						else if (d == 4) {
							x2--;
						}
					}
					else if (v[i] == "Right") {
						d++;
						if (d == 5) {
							d = 1;
						}
					}
					else if (v[i] == "Left") {
						d--;
						if (d == 0) {
							d = 4;
						}
					}
				}
				if (x1 == x2 && y1 == y2) {
					cout << j + 1 << " " << v[j] << endl;
					return 0;
				}
				else {
					v[j] = b;
					x2 = 0;
					y2 = 0;
					d = 1;
				}
			}
		}
		if (v[j] == c[2]) {
			for (i64 a = 0; a < 2; a++) {
				string b = v[j];
				v[j] = c[a];
				for (i64 i = 0; i < n; i++) {
					if (v[i] == "Forward") {
						if (d == 1) {
							y2++;
						}
						else if (d == 2) {
							x2++;
						}
						else if (d == 3) {
							y2--;
						}
						else if (d == 4) {
							x2--;
						}
					}
					else if (v[i] == "Right") {
						d++;
						if (d == 5) {
							d = 1;
						}
					}
					else if (v[i] == "Left") {
						d--;
						if (d == 0) {
							d = 4;
						}
					}
				}
				if (x1 == x2 && y1 == y2) {
					cout << j + 1 << " " << v[j] << endl;
					return 0;
				}
				else {
					v[j] = b;
					x2 = 0;
					y2 = 0;
					d = 1;
				}
			}
		}
	}
}