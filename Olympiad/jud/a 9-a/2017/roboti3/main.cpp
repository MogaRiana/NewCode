#include <bits/stdc++.h>

using namespace std;

int main() {
  ifstream cin{"roboti3.in"};
  ofstream cout{"roboti3.out"};
  int c, r;
  cin >> c >> r;
  if (c == 1) {
    int v[2 * r];
    for (int i = 0; i < r; i++) {
      cin >> v[i];
      v[i + r] = v[i];
    }
    int d = 1;
    int crt = 1;
    for (int i = 1; i < 2 * r; i++) {
      if (v[i] > v[i - 1]) {
        crt++;
        d = max(d, crt);
      } else {
        crt = 1;
      }
    }
    cout << d << endl;
  } else if (c == 2) {
    int v[r];
    for (int i = 0; i < r; i++) {
      cin >> v[i];
      v[i + r] = v[i];
    }
    sort(v, v + r);
    deque<int> d;
    d.push_back(v[0]);
    for (int i = 1; i < r; i++) {
      if (i % 2 == 1) {
        d.push_back(v[i]);
      } else {
        d.push_front(v[i]);
      }
    }

    while (d[0] != v[0]) {
      d.push_back(d[0]);
      d.pop_front();
    }

    for (auto e : d) {
      cout << e << " ";
    }
    cout << endl;
  }
  return 0;
}