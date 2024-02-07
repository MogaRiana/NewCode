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

deque<i64> ll, rr, cc;

void slvl(i64 &res, i64 l) {
  if (res % 2 == 1) {
    res++;
  }

  i64 sum = 0;
  while (!ll.empty() and sum + ll.front() <= l) {
    sum += ll.front();
    cc.push_back(ll.front());
    ll.pop_front();
  }

  if (!cc.empty()) {
    res++;
    cc.clear();
  }
}

void slvr(i64 &res, i64 l) {
  if (res % 2 == 0) {
    res++;
  }

  i64 sum = 0;
  while (!rr.empty() and sum + rr.front() <= l) {
    sum += rr.front();
    cc.push_back(rr.front());
    rr.pop_front();
  }

  if (!cc.empty()) {
    res++;
    cc.clear();
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 q;
  cin >> q;
  while (q--) {
    i64 l, m;
    cin >> l >> m;

    l *= 100;
    for (i64 i = 0; i < m; i++) {
      i64 x;
      str s;
      cin >> x >> s;
      (s == "left") ? ll.push_back(x) : rr.push_back(x);
    }

    i64 res = 0;
    while (!ll.empty() or !rr.empty()) {
      slvl(res, l);
      slvr(res, l);
    }

    cout << res << endl;
  }

  return 0;
}
