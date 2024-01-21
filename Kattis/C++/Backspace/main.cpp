#include <algorithm>
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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  str s;
  cin >> s;

  deque<char> d;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '<' and !d.empty()) {
      d.pop_back();
    } else if (s[i] != '<') {
      d.push_back(s[i]);
    }
  }

  for (i64 i = 0; i < d.size(); i++) {
    cout << d[i];
  }

  return 0;
}