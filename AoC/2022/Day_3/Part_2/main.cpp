#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef vector<i64> v64;

int main() {
  ifstream cin{"input.in"};
  ofstream cout{"output.out"};

  string r1, r2, r3;
  i64 sum = 0;
  while (cin >> r1 >> r2 >> r3) {
    v64 c1;
    v64 c2;
    v64 c3;
    for (i64 i = 0; i < r1.size(); i++) {
      c1.push_back((i64)r1[i]);
    }
    for (i64 i = 0; i < r2.size(); i++) {
      c2.push_back((i64)r2[i]);
    }
    for (i64 i = 0; i < r3.size(); i++) {
      c3.push_back((i64)r3[i]);
    }
    v64 c12;
    v64 com;
    for (i64 i = 0; i < c1.size(); i++) {
      for (i64 j = 0; j < c2.size(); j++) {
        if (c1[i] == c2[j]) {
          c12.push_back(c1[i]);
        }
      }
    }
    for (i64 i = 0; i < c12.size(); i++) {
      for (i64 j = 0; j < c3.size(); j++) {
        if (c12[i] == c3[j]) {
          com.push_back(c12[i]);
        }
      }
    }
    set<i64> a;
    for (i64 i = 0; i < com.size(); i++) {
      a.insert(com[i]);
    }
    for (auto &i : a) {
      if (i >= 65 && i <= 90) {
        sum += i - '@' + 26;
      } else if (i >= 97 && i <= 122) {
        sum += i - '`';
      }
    }
  }
  cout << sum << endl;
  return 0;
}
