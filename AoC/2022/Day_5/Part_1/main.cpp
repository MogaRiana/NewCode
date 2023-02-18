#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef vector<i64> v64;

int main() {
  ifstream cin{"input.in"};
  ofstream cout{"output.out"};

  vector<char> v1 = {'F', 'H', 'B', 'V', 'R', 'Q', 'D', 'P'};
  vector<char> v2 = {'L', 'D', 'Z', 'Q', 'W', 'V'};
  vector<char> v3 = {'H', 'L', 'Z', 'Q', 'G', 'R', 'P', 'C'};
  vector<char> v4 = {'R', 'D', 'H', 'F', 'J', 'V', 'B'};
  vector<char> v5 = {'Z', 'W', 'L', 'C'};
  vector<char> v6 = {'J', 'R', 'P', 'N', 'T', 'G', 'V', 'M'};
  vector<char> v7 = {'J', 'R', 'L', 'V', 'M', 'B', 'S'};
  vector<char> v8 = {'D', 'P', 'J'};
  vector<char> v9 = {'D', 'C', 'N', 'W', 'V'};
  i64 x, y, n;
  string a, b, c;
  while (cin >> a >> n >> b >> x >> c >> y) {
    char m;
    if (x == 1 && y == 2) {
      for (i64 i = 0; i < n; i++) {
        m = v1[v1.size() - 1];
        v2.push_back(m);
        v1.pop_back();
      }
    }
    if (x == 1 && y == 3) {
      for (i64 i = 0; i < n; i++) {
        m = v1[v1.size() - 1];
        v3.push_back(m);
        v1.pop_back();
      }
    }
    if (x == 1 && y == 4) {
      for (i64 i = 0; i < n; i++) {
        m = v1[v1.size() - 1];
        v4.push_back(m);
        v1.pop_back();
      }
    }
    if (x == 1 && y == 5) {
      for (i64 i = 0; i < n; i++) {
        m = v1[v1.size() - 1];
        v5.push_back(m);
        v1.pop_back();
      }
    }
    if (x == 1 && y == 6) {
      for (i64 i = 0; i < n; i++) {
        m = v1[v1.size() - 1];
        v6.push_back(m);
        v1.pop_back();
      }
    }
    if (x == 1 && y == 7) {
      for (i64 i = 0; i < n; i++) {
        m = v1[v1.size() - 1];
        v7.push_back(m);
        v1.pop_back();
      }
    }
    if (x == 1 && y == 8) {
      for (i64 i = 0; i < n; i++) {
        m = v1[v1.size() - 1];
        v8.push_back(m);
        v1.pop_back();
      }
    }
    if (x == 1 && y == 9) {
      for (i64 i = 0; i < n; i++) {
        m = v1[v1.size() - 1];
        v9.push_back(m);
        v1.pop_back();
      }
    }
    if (x == 2 && y == 1) {
      for (i64 i = 0; i < n; i++) {
        m = v2[v2.size() - 1];
        v1.push_back(m);
        v2.pop_back();
      }
    }
    if (x == 2 && y == 3) {
      for (i64 i = 0; i < n; i++) {
        m = v2[v2.size() - 1];
        v3.push_back(m);
        v2.pop_back();
      }
    }
    if (x == 2 && y == 4) {
      for (i64 i = 0; i < n; i++) {
        m = v2[v2.size() - 1];
        v4.push_back(m);
        v2.pop_back();
      }
    }
    if (x == 2 && y == 5) {
      for (i64 i = 0; i < n; i++) {
        m = v2[v2.size() - 1];
        v5.push_back(m);
        v2.pop_back();
      }
    }
    if (x == 2 && y == 6) {
      for (i64 i = 0; i < n; i++) {
        m = v2[v2.size() - 1];
        v6.push_back(m);
        v2.pop_back();
      }
    }
    if (x == 2 && y == 7) {
      for (i64 i = 0; i < n; i++) {
        m = v2[v2.size() - 1];
        v7.push_back(m);
        v2.pop_back();
      }
    }
    if (x == 2 && y == 8) {
      for (i64 i = 0; i < n; i++) {
        m = v2[v2.size() - 1];
        v8.push_back(m);
        v2.pop_back();
      }
    }
    if (x == 2 && y == 9) {
      for (i64 i = 0; i < n; i++) {
        m = v2[v2.size() - 1];
        v9.push_back(m);
        v2.pop_back();
      }
    }
    if (x == 3 && y == 1) {
      for (i64 i = 0; i < n; i++) {
        m = v3[v3.size() - 1];
        v1.push_back(m);
        v3.pop_back();
      }
    }
    if (x == 3 && y == 2) {
      for (i64 i = 0; i < n; i++) {
        m = v3[v3.size() - 1];
        v2.push_back(m);
        v3.pop_back();
      }
    }
    if (x == 3 && y == 4) {
      for (i64 i = 0; i < n; i++) {
        m = v3[v3.size() - 1];
        v4.push_back(m);
        v3.pop_back();
      }
    }
    if (x == 3 && y == 5) {
      for (i64 i = 0; i < n; i++) {
        m = v3[v3.size() - 1];
        v5.push_back(m);
        v3.pop_back();
      }
    }
    if (x == 3 && y == 6) {
      for (i64 i = 0; i < n; i++) {
        m = v3[v3.size() - 1];
        v6.push_back(m);
        v3.pop_back();
      }
    }
    if (x == 3 && y == 7) {
      for (i64 i = 0; i < n; i++) {
        m = v3[v3.size() - 1];
        v7.push_back(m);
        v3.pop_back();
      }
    }
    if (x == 3 && y == 8) {
      for (i64 i = 0; i < n; i++) {
        m = v3[v3.size() - 1];
        v8.push_back(m);
        v3.pop_back();
      }
    }
    if (x == 3 && y == 9) {
      for (i64 i = 0; i < n; i++) {
        m = v3[v3.size() - 1];
        v9.push_back(m);
        v3.pop_back();
      }
    }
    if (x == 4 && y == 1) {
      for (i64 i = 0; i < n; i++) {
        m = v4[v4.size() - 1];
        v1.push_back(m);
        v4.pop_back();
      }
    }
    if (x == 4 && y == 2) {
      for (i64 i = 0; i < n; i++) {
        m = v4[v4.size() - 1];
        v2.push_back(m);
        v4.pop_back();
      }
    }
    if (x == 4 && y == 3) {
      for (i64 i = 0; i < n; i++) {
        m = v4[v4.size() - 1];
        v3.push_back(m);
        v4.pop_back();
      }
    }
    if (x == 4 && y == 5) {
      for (i64 i = 0; i < n; i++) {
        m = v4[v4.size() - 1];
        v5.push_back(m);
        v4.pop_back();
      }
    }
    if (x == 4 && y == 6) {
      for (i64 i = 0; i < n; i++) {
        m = v4[v4.size() - 1];
        v6.push_back(m);
        v4.pop_back();
      }
    }
    if (x == 4 && y == 7) {
      for (i64 i = 0; i < n; i++) {
        m = v4[v4.size() - 1];
        v7.push_back(m);
        v4.pop_back();
      }
    }
    if (x == 4 && y == 8) {
      for (i64 i = 0; i < n; i++) {
        m = v4[v4.size() - 1];
        v8.push_back(m);
        v4.pop_back();
      }
    }
    if (x == 4 && y == 9) {
      for (i64 i = 0; i < n; i++) {
        m = v4[v4.size() - 1];
        v9.push_back(m);
        v4.pop_back();
      }
    }
    if (x == 5 && y == 1) {
      for (i64 i = 0; i < n; i++) {
        m = v5[v5.size() - 1];
        v1.push_back(m);
        v5.pop_back();
      }
    }
    if (x == 5 && y == 2) {
      for (i64 i = 0; i < n; i++) {
        m = v5[v5.size() - 1];
        v2.push_back(m);
        v5.pop_back();
      }
    }
    if (x == 5 && y == 3) {
      for (i64 i = 0; i < n; i++) {
        m = v5[v5.size() - 1];
        v3.push_back(m);
        v5.pop_back();
      }
    }
    if (x == 5 && y == 4) {
      for (i64 i = 0; i < n; i++) {
        m = v5[v5.size() - 1];
        v4.push_back(m);
        v5.pop_back();
      }
    }
    if (x == 5 && y == 6) {
      for (i64 i = 0; i < n; i++) {
        m = v5[v5.size() - 1];
        v6.push_back(m);
        v5.pop_back();
      }
    }
    if (x == 5 && y == 7) {
      for (i64 i = 0; i < n; i++) {
        m = v5[v5.size() - 1];
        v7.push_back(m);
        v5.pop_back();
      }
    }
    if (x == 5 && y == 8) {
      for (i64 i = 0; i < n; i++) {
        m = v5[v5.size() - 1];
        v8.push_back(m);
        v5.pop_back();
      }
    }
    if (x == 5 && y == 9) {
      for (i64 i = 0; i < n; i++) {
        m = v5[v5.size() - 1];
        v9.push_back(m);
        v5.pop_back();
      }
    }
    if (x == 6 && y == 1) {
      for (i64 i = 0; i < n; i++) {
        m = v6[v6.size() - 1];
        v1.push_back(m);
        v6.pop_back();
      }
    }
    if (x == 6 && y == 2) {
      for (i64 i = 0; i < n; i++) {
        m = v6[v6.size() - 1];
        v2.push_back(m);
        v6.pop_back();
      }
    }
    if (x == 6 && y == 3) {
      for (i64 i = 0; i < n; i++) {
        m = v6[v6.size() - 1];
        v3.push_back(m);
        v6.pop_back();
      }
    }
    if (x == 6 && y == 4) {
      for (i64 i = 0; i < n; i++) {
        m = v6[v6.size() - 1];
        v4.push_back(m);
        v6.pop_back();
      }
    }
    if (x == 6 && y == 5) {
      for (i64 i = 0; i < n; i++) {
        m = v6[v6.size() - 1];
        v5.push_back(m);
        v6.pop_back();
      }
    }
    if (x == 6 && y == 7) {
      for (i64 i = 0; i < n; i++) {
        m = v6[v6.size() - 1];
        v7.push_back(m);
        v6.pop_back();
      }
    }
    if (x == 6 && y == 8) {
      for (i64 i = 0; i < n; i++) {
        m = v6[v6.size() - 1];
        v8.push_back(m);
        v6.pop_back();
      }
    }
    if (x == 6 && y == 9) {
      for (i64 i = 0; i < n; i++) {
        m = v6[v6.size() - 1];
        v9.push_back(m);
        v6.pop_back();
      }
    }
    if (x == 7 && y == 1) {
      for (i64 i = 0; i < n; i++) {
        m = v7[v7.size() - 1];
        v1.push_back(m);
        v7.pop_back();
      }
    }
    if (x == 7 && y == 2) {
      for (i64 i = 0; i < n; i++) {
        m = v7[v7.size() - 1];
        v2.push_back(m);
        v7.pop_back();
      }
    }
    if (x == 7 && y == 3) {
      for (i64 i = 0; i < n; i++) {
        m = v7[v7.size() - 1];
        v3.push_back(m);
        v7.pop_back();
      }
    }
    if (x == 7 && y == 4) {
      for (i64 i = 0; i < n; i++) {
        m = v7[v7.size() - 1];
        v4.push_back(m);
        v7.pop_back();
      }
    }
    if (x == 7 && y == 5) {
      for (i64 i = 0; i < n; i++) {
        m = v7[v7.size() - 1];
        v5.push_back(m);
        v7.pop_back();
      }
    }
    if (x == 7 && y == 6) {
      for (i64 i = 0; i < n; i++) {
        m = v7[v7.size() - 1];
        v6.push_back(m);
        v7.pop_back();
      }
    }
    if (x == 7 && y == 8) {
      for (i64 i = 0; i < n; i++) {
        m = v7[v7.size() - 1];
        v8.push_back(m);
        v7.pop_back();
      }
    }
    if (x == 7 && y == 9) {
      for (i64 i = 0; i < n; i++) {
        m = v7[v7.size() - 1];
        v9.push_back(m);
        v7.pop_back();
      }
    }
    if (x == 8 && y == 1) {
      for (i64 i = 0; i < n; i++) {
        m = v8[v8.size() - 1];
        v1.push_back(m);
        v8.pop_back();
      }
    }
    if (x == 8 && y == 2) {
      for (i64 i = 0; i < n; i++) {
        m = v8[v8.size() - 1];
        v2.push_back(m);
        v8.pop_back();
      }
    }
    if (x == 8 && y == 3) {
      for (i64 i = 0; i < n; i++) {
        m = v8[v8.size() - 1];
        v3.push_back(m);
        v8.pop_back();
      }
    }
    if (x == 8 && y == 4) {
      for (i64 i = 0; i < n; i++) {
        m = v8[v8.size() - 1];
        v4.push_back(m);
        v8.pop_back();
      }
    }
    if (x == 8 && y == 5) {
      for (i64 i = 0; i < n; i++) {
        m = v8[v8.size() - 1];
        v5.push_back(m);
        v8.pop_back();
      }
    }
    if (x == 8 && y == 6) {
      for (i64 i = 0; i < n; i++) {
        m = v8[v8.size() - 1];
        v6.push_back(m);
        v8.pop_back();
      }
    }
    if (x == 8 && y == 7) {
      for (i64 i = 0; i < n; i++) {
        m = v8[v8.size() - 1];
        v7.push_back(m);
        v8.pop_back();
      }
    }
    if (x == 8 && y == 9) {
      for (i64 i = 0; i < n; i++) {
        m = v8[v8.size() - 1];
        v9.push_back(m);
        v8.pop_back();
      }
    }
    if (x == 9 && y == 1) {
      for (i64 i = 0; i < n; i++) {
        m = v9[v9.size() - 1];
        v1.push_back(m);
        v9.pop_back();
      }
    }
    if (x == 9 && y == 2) {
      for (i64 i = 0; i < n; i++) {
        m = v9[v9.size() - 1];
        v2.push_back(m);
        v9.pop_back();
      }
    }
    if (x == 9 && y == 3) {
      for (i64 i = 0; i < n; i++) {
        m = v9[v9.size() - 1];
        v3.push_back(m);
        v9.pop_back();
      }
    }
    if (x == 9 && y == 4) {
      for (i64 i = 0; i < n; i++) {
        m = v9[v9.size() - 1];
        v4.push_back(m);
        v9.pop_back();
      }
    }
    if (x == 9 && y == 5) {
      for (i64 i = 0; i < n; i++) {
        m = v9[v9.size() - 1];
        v5.push_back(m);
        v9.pop_back();
      }
    }
    if (x == 9 && y == 6) {
      for (i64 i = 0; i < n; i++) {
        m = v9[v9.size() - 1];
        v6.push_back(m);
        v9.pop_back();
      }
    }
    if (x == 9 && y == 7) {
      for (i64 i = 0; i < n; i++) {
        m = v9[v9.size() - 1];
        v7.push_back(m);
        v9.pop_back();
      }
    }
    if (x == 9 && y == 8) {
      for (i64 i = 0; i < n; i++) {
        m = v9[v9.size() - 1];
        v8.push_back(m);
        v9.pop_back();
      }
    }
  }
  cout << v1[v1.size() - 1] << v2[v2.size() - 1] << v3[v3.size() - 1]
       << v4[v4.size() - 1] << v5[v5.size() - 1] << v6[v6.size() - 1]
       << v7[v7.size() - 1] << v8[v8.size() - 1] << v9[v9.size() - 1];
  return 0;
}
