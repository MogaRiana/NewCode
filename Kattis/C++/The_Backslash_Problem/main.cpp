#include <bits/stdc++.h>

using namespace std;

// #define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;
typedef pair<i64, i64> p64;
typedef vector<p64> vp64;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 n;
  while (cin >> n) {
    cin.ignore();
    str s;
    getline(cin, s);

    str tt = "", bb;
    bb.resize(pow(2, n) - 1, '\\');

    for (auto &x : s) {
      if (x >= '!' and x <= '*' or x >= '[' and x <= ']') {
        tt += bb;
      }
      tt.push_back(x);
    }

    cout << tt << endl;
  }

  return 0;
}
