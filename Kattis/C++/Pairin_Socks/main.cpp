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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 n;
  cin >> n;

  deque<i64> s1, s2;
  for (i64 i = 0; i < n * 2; i++) {
    i64 x;
    cin >> x;
    s1.push_back(x);
  }

  i64 crt = 0;
  while (!s1.empty()) {
    while (!s1.empty() and !s2.empty() and s1.back() == s2.back()) {
      crt++;
      s1.pop_back();
      s2.pop_back();
    }

    if (!s1.empty()) {
      s2.push_back(s1.back());
      s1.pop_back();
      crt++;
    }
  }

  if (!s2.empty()) {
    cout << "impossible" << endl;
  } else {
    cout << crt << endl;
  }

  return 0;
}