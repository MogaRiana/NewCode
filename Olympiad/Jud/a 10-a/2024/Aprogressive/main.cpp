#include <bits/stdc++.h>

using namespace std;

// #define endl '\n'
#define ft first
#define sd second
#define sz(x) (i6) x.size()
#define col(x) x.begin(), x.end()
#define srt(x) sort(x.begin(), x.end())
#define rsrt(x) sort(x.rbegin(), x.rend())
#define rvs(x) reverse(x.begin(), x.end())
#define LSOne(S) ((S) & (-S))

template <typename T> using vec = vector<T>;
template <typename T> using deq = deque<T>;

typedef int64_t i64;
typedef int32_t i32;
typedef int16_t i16;
typedef string str;
typedef pair<i64, i64> p64;
typedef vec<i64> vi64;
typedef vec<i32> vi32;
typedef vec<vi64> vv;
typedef vec<p64> vp64;
typedef vec<str> vstr;

vv res(0, vi64(0));

void ratie(i64 &r, bool &ok, vv &v, p64 p1, p64 p2) {
  i64 x1 = p1.ft, y1 = p1.sd;
  i64 x2 = p2.ft, y2 = p2.sd;

  vi64 a;
  for (i64 i = x1; i <= x2; i++) {
    i64 s = 0;
    for (i64 j = y1; j <= y2; j++) {
      s += v[i][j];
    }

    a.push_back(s);
  }

  srt(a);
  r = a[1] - a[0];
  for (i64 i = 1; i < a.size(); i++) {
    if (a[i] - a[i - 1] != r) {
      ok = false;
      return;
    }
  }

  return;
}

ofstream fout{"aprogressive.out"};
void sol(p64 p1, p64 p2, vv &v) {
  i64 x1 = p1.ft, y1 = p1.sd;
  i64 x2 = p2.ft, y2 = p2.sd;

  if (x1 == x2 or y1 == y2) {
    fout << '(' << x1 + 1 << ',' << y1 + 1 << ',' << x2 + 1 << ',' << y2 + 1
         << ',' << 0 << ')';
    return;
  }

  i64 r;
  bool ok = true;

  ratie(r, ok, v, p1, p2);

  if (ok and r != 0) {
    fout << '(' << x1 + 1 << ',' << y1 + 1 << ',' << x2 + 1 << ',' << y2 + 1
         << ',' << r << ')';
    return;
  }

  i64 mx = (x1 + x2) / 2;
  i64 my = (y1 + y2) / 2;

  fout << '(';

  sol({x1, y1}, {mx, my}, v);
  sol({x1, my + 1}, {mx, y2}, v);
  sol({mx + 1, y1}, {x2, my}, v);
  sol({mx + 1, my + 1}, {x2, y2}, v);

  fout << ')';

  return;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"aprogressive.in"};
  ofstream cout{"aprogressive.out"};

  i64 tc;
  cin >> tc;

  i64 l, c;
  cin >> l >> c;

  if (tc == 1) {
    set<p64> s;
    i64 res = -1e9;
    for (i64 i = 1; i <= l; i++) {
      i64 sum = 0;
      for (i64 j = 0; j < c; j++) {
        i64 x;
        cin >> x;
        sum += x;
      }
      res = max(res, sum);
      s.insert({i, sum});
    }

    for (auto &x : s) {
      if (x.second == res) {
        cout << x.first << endl;
      }
    }

    return 0;
  } else if (tc == 2) {
    for (i64 i = 1; i <= l; i++) {
      vi64 s;
      for (i64 j = 0; j < c; j++) {
        i64 x;
        cin >> x;
        s.push_back(x);
      }

      sort(s.begin(), s.end());
      i64 cc = -1e9;
      bool ok = true;
      for (i64 j = 1; j < c; j++) {
        if (cc == -1e9) {
          cc = s[j] - s[j - 1];
        }

        if (s[j] - s[j - 1] != cc) {
          ok = false;
          break;
        }
      }

      if (ok) {
        cout << i << endl;
      }
    }

    return 0;
  }

  vv v(l, vi64(c));
  for (i64 i = 0; i < l; i++) {
    for (i64 j = 0; j < c; j++) {
      cin >> v[i][j];
    }
  }

  sol({0, 0}, {l - 1, c - 1}, v);

  return 0;
}