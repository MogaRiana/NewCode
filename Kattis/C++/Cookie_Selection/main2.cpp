#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define LSOne(S) ((S) & -(S))

typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;
typedef pair<i64, i64> p64;
typedef vector<p64> vp64;
typedef vector<str> vstr;

class fentree {
private:
  vp64 ft;

public:
  fentree(i64 m) { ft.assign(m + 1, {0, 0}); }

  void build(const vp64 &f) {
    i64 m = f.size() - 1;
    ft.assign(m + 1, {0, 0});

    for (i64 i = 1; i <= m; i++) {
      ft[i].first += f[i].first;
      ft[i].second = f[i].second;
      if (i + LSOne(i) <= m) {
        ft[i + LSOne(i)].first += f[i].first;
      }
    }
  }

  fentree(const vp64 &f) { build(f); }

  fentree(i64 m, const set<p64> &s) {
    vp64 f(m + 1, {0, 0});

    vp64 c;
    for (auto &x : s) {
      c.push_back({x.first, x.second});
    }

    for (i64 i = 0; i < c.size(); i++) {
      f[c[i].first].first++;
    }
    build(f);
  }

  void update(i64 i, i64 val) {
    for (; i < ft.size(); i += LSOne(i)) {
      ft[i].first += val;
    }
  }

  i64 select(i64 k) {
    i64 p = 1;
    while (p * 2 < ft.size()) {
      p *= 2;
    }

    i64 i = 0;
    while (p) {
      if (k > ft[i + p].first) {
        k -= ft[i + p].first;
        i += p;
      }
      p /= 2;
    }

    return i + 1;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  set<p64> ll;
  fentree ft(ll.size() + 1, ll);
  i64 tt = 0;
  str c;
  while (cin >> c) {
    if (c == "#") {
      if (ll.size() / 2 == 0) {

      } else {
      }
    } else {
      ll.insert({stoi(c), tt++});
    }
  }

  return 0;
}