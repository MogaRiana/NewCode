#include <bits/stdc++.h>

using namespace std;
typedef long long i64;

int main() {
  i64 n;
  cin >> n;
  int g, m;
  for (i64 i = 0; i < n; i++) {
    cin >> g >> m;
    i64 sg[g], sm[m], maxg = 0, maxm = 0;
    for (i64 j = 0; j < g; j++) {
      cin >> sg[j];
    }
    sort(sg, sg + g);
    maxg = sg[g - 1];
    for (i64 k = 0; k < m; k++) {
      cin >> sm[k];
    }
    sort(sm, sm + m);
    maxm = sm[m - 1];
    if (maxg > maxm) {
      cout << "Godzilla" << endl;
    } else if (maxg == maxm) {
      cout << "Godzilla" << endl;
    } else if (maxg < maxm) {
      cout << "MechaGodzilla" << endl;
    } else {
      cout << "uncertain" << endl;
    }
  }
  return 0;
}