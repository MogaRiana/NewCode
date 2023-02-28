#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  str s;
  map<char, i64> m;
  for (i64 i = 0; i < 5; i++) {
    cin >> s;
    m[s[0]]++;
  }

  i64 k = -1e9;
  for (auto key : m) {
    if (key.second > k) {
      k = key.second;
    }
  }

  cout << k << endl;

  return 0;
}