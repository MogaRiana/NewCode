#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef vector<i64> v64;

int main() {
  ifstream cin{"input.in"};
  ofstream cout{"output.out"};

  string s;
  cin >> s;
  set<char> a;
  for (i64 i = 0; i < s.size() - 3; i++) {
    for (i64 j = i; j < i + 4; j++) {
      a.insert(s[j]);
    }
    if (a.size() == 4) {
      cout << i + 4 << endl;
      break;
    }
    a.clear();
  }
  return 0;
}
