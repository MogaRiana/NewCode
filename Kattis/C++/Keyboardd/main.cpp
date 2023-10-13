#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;
typedef long double d6;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  str s1, s2;
  getline(cin, s1);
  getline(cin, s2);

  i64 k = 0;
  set<char> a;
  for (i64 i = 0; i < s2.size(); i++) {
    if (s1[i - k] != s2[i]) {
      k++;
      a.insert(s2[i]);
    }
  }

  for (auto &x : a) {
    cout << x;
  }

  return 0;
}