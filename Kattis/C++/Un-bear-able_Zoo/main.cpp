#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;
typedef pair<i64, i64> p64;
typedef vector<p64> vp64;
typedef vector<str> vstr;

str low(str &s) {
  for (auto &x : s) {
    x = tolower(x);
  }

  return s;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 n, a = 1;
  while (cin >> n) {
    if (n == 0) {
      break;
    }

    cin.ignore();

    map<str, i64> list;
    for (i64 i = 0; i < n; i++) {
      str s;
      getline(cin, s);

      stringstream ss(s);
      str x;
      while (ss >> x) {
      }

      list[low(x)]++;
    }

    cout << "List " << a++ << ":" << endl;
    for (auto &x : list) {
      cout << x.first << " | " << x.second << endl;
    }
  }

  return 0;
}