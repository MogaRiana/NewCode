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
  vi64 ft;

public:
  fentree(i64 m) { ft.assign(m + 1, 0); }

  void build(const vi64 &f) {
    i64 m = f.size() - 1;
    ft.assign(m + 1, 0);

    for (i64 i = 1; i <= m; i++) {
      ft[i] += f[i];
      if (i + LSOne(i) <= m) {
        ft[i + LSOne(i)] += f[i];
      }
    }
  }

  fentree(const vi64 &f) { build(f); }

  fentree(i64 m, const vi64 &s) {
    vi64 f(m + 1, 0);
    for (i64 i = 0; i < s.size(); i++) {
      f[s[i]]++;
    }
    build(f);
  }

  i64 rsq(i64 j) {
    i64 sum = 0;
    for (; j; j -= LSOne(j)) {
      sum += ft[j];
    }
    return sum;
  }

  i64 rsq(i64 l, i64 r) { return rsq(r) - rsq(l - 1); }

  void update(i64 i, i64 val) {
    for (; i < ft.size(); i += LSOne(i)) {
      ft[i] += val;
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 n, q;
  cin >> n >> q;

  vi64 s(n, 0);
  fentree ft(n + 1, s);
  while (q--) {
    char c;
    cin >> c;

    if (c == 'F') {
      i64 pos;
      cin >> pos;

      if (s[pos - 1]) {
        s[pos - 1] = 0;
        ft.update(pos, -1);
      } else {
        s[pos - 1] = 1;
        ft.update(pos, 1);
      }
    } else {
      i64 l, r;
      cin >> l >> r;

      cout << ft.rsq(l, r) << endl;
    }
  }

  return 0;
}