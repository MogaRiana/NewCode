#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef long double d64;
typedef vector<i64> v;
typedef vector<vector<i64>> vv;

int main() {
  ifstream cin{"input.in"};
  ofstream cout{"output.out"};

  string a;
  i64 m = 0, s = 0;
  while (getline(cin, a)) {
    i64 nr = 0;
    if (a == "") {
      m = max(m, s);
      s = 0;
    } else {
      nr = stoi(a);
      s += nr;
    }
  }
  cout << m << endl;
  return 0;
}
