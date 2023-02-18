#include<bits/stdc++.h>

using namespace std;

int main() {
	ifstream cin{ "admitere.in" };
	ofstream cout{ "admitere.out" };
	int8_t p;
	cin >> p;
	short n, m;
	cin >> n >> m;
	vector<int> rm(m);
	vector<int> um(m);
	vector<int> rn(n);
	vector<int> un(n);
	for (short i = 0; i < m; i++) {
		cin >> rm[i];
	}
	for (short i = 0; i < m; i++) {
		cin >> um[i];
	}
	for (short i = 0; i < n; i++) {
		cin >> rn[i] >> un[i];
	}
	if (p == '1') {
		vector<char> cr(n, 'X');
		vector<char> cu(n, 'X');
		short crtr = 0, crtu = 0;
		for (short i = 0; i < n; i++) {
			rm.push_back(rn[i]);
		}
		sort(rm.begin(), rm.end());
		sort(rn.begin(), rn.end());
		for (int i = rm.size() - 1; i >= rm.size() - m; i--) {
			int a = rm[i], l = 0, r = rn.size() - 1;
			bool ok = true;
			while (ok && l <= r) {
				int mid = l + ((r - l) / 2);
				if (rn[mid] == a) {
					crtr++;
					cr[mid] = 'R';
					ok = false;
				}
				else if (rn[mid] < a) {
					l = mid + 1;
				}
				else {
					r = mid - 1;
				}
			}
		}
		for (short i = 0; i < n; i++) {
			um.push_back(un[i]);
		}
		sort(um.begin(), um.end());
		sort(un.begin(), un.end());
		for (int i = um.size() - 1; i >= um.size() - m; i--) {
			int a = um[i], l = 0, r = un.size() - 1;
			bool ok = true;
			while (ok && l <= r) {
				int mid = l + ((r - l) / 2);
				if (un[mid] == a) {
					crtu++;
					cu[mid] = 'U';
					ok = false;
				}
				else if (un[mid] < a) {
					l = mid + 1;
				}
				else {
					r = mid - 1;
				}
			}
		}
		if (crtr > crtu) {
			cout << crtr << endl;
			for (short i = 0; i < n; i++) {
				cout << cr[i];
			}
		}
		else if (crtu > crtr) {
			cout << crtu << endl;
			for (short i = 0; i < n; i++) {
				cout << cu[i];
			}
		}
		else {
			cout << crtr << endl;
			for (short i = 0; i < n; i++) {
				cout << cr[i];
			}
		}
	}
	else {
		vector<char> c(n, 'X');
		short crt = 0;
		for (short i = 0; i < n; i++) {
			if (rn[i] >= rm[0]) {
				rm.push_back(rn[i]);
			}
		}
		sort(rm.begin(), rm.end());
		sort(rn.begin(), rn.end());
		for (int i = rm.size() - 1; i >= 0; i--) {
			int a = rm[i], l = 0, r = rn.size() - 1;
			bool ok = true;
			while (ok && l <= r) {
				int mid = l + ((r - l) / 2);
				if (rn[mid] == a) {
					crt++;
					c[mid] = 'R';
					ok = false;
				}
				else if (rn[mid] < a) {
					l = mid + 1;
				}
				else {
					r = mid - 1;
				}
			}
		}
		for (short i = 0; i < n; i++) {
			if (un[i] >= um[0]) {
				um.push_back(un[i]);
			}
		}
		sort(um.begin(), um.end());
		sort(un.begin(), un.end());
		for (int i = um.size() - 1; i >= 0; i--) {
			int a = um[i], l = 0, r = un.size() - 1;
			bool ok = true;
			while (ok && l <= r) {
				int mid = l + ((r - l) / 2);
				if (un[mid] == a) {
					if(crt + 1 <= n){
					crt++;
				}
					ok = false;
					c[mid] = 'U';
				}
				else if (un[mid] < a) {
					l = mid + 1;
				}
				else {
					r = mid - 1;
				}
			}
		}
		cout << crt << endl;
		for (int i = 0; i < n; i++) {
			cout << c[i];
		}
	}
	return 0;
}