#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef vector<i64> v64;

int main() {
  ifstream cin{"input.in"};
  ofstream cout{"output.out"};

  string r;
  i64 sum = 0;
  while (cin >> r) {
    v64 c1;
    v64 c2;
    for (i64 i = 0; i < r.size() / 2; i++) {
      c1.push_back((i64)r[i]);
    }
    for (i64 i = r.size() / 2; i < r.size(); i++) {
      c2.push_back((i64)r[i]);
    }
    v64 com;

    for (i64 i = 0; i < c1.size(); i++) {
      for (i64 j = 0; j < c2.size(); j++) {
        if (c1[i] == c2[j]) {
          com.push_back(c1[i]);
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
