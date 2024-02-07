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

  list<char> ll;
  str s;
  auto crt = ll.begin();

  getline(cin, s);
  for (auto &c : s) {
    if (c == 'L') {
      crt--;
    } else if (c == 'R') {
      crt++;
    } else if (c == 'B') {
      crt = ll.erase(--crt);
    } else {
      ll.insert(crt, c);
    }
  }

  for (auto c : ll) {
    cout << c;
  }

  return 0;
}
