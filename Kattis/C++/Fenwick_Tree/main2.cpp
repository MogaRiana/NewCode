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

  i64 rsq(i64 j) {
    i64 sum = 0;
    for (; j; j -= LSOne(j)) {
      sum += ft[j];
    }

    return sum;
  }

  void update(i64 i, i64 a) {
    for (; i < ft.size(); i += LSOne(i)) {
      ft[i] += a;
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 n, q;
  cin >> n >> q;

  fentree ft(n);

  while (q--) {
    char c;
    cin >> c;

    if (c == '+') {
      i64 pos, val;
      cin >> pos >> val;
      ft.update(pos + 1, val);
    } else {
      i64 r;
      cin >> r;

      cout << ft.rsq(r) << endl;
    }
  }

  return 0;
}