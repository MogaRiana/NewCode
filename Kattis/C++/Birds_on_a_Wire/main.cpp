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

  i64 l, d, n;
  cin >> l >> d >> n;

  vi64 v(l, 0);
  deque<i64> pos;
  for (i64 i = 0; i < n; i++) {
    i64 x;
    cin >> x;
    x--;
    pos.push_back(x);
    v[x] = 1;
  }

  sort(pos.begin(), pos.end());

  i64 res = 0;
  for (i64 i = 6; i < l - 6; i++) {
    if (!pos.empty()) {
      i64 dis = pos.front() - i;
      if (dis > d and dis % d == 0) {
        res += dis / d;
      }
      i = pos.front() - 1;
      pos.pop_front();
    } else {
      i64 dis = l - 1 - i;
      if (dis > d and dis % d == 0) {
        res += dis / d;
      }
    }
  }

  cout << res << endl;

  return 0;
}