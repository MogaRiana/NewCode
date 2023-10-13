#include <bits/stdc++.h>

using namespace std;

// #define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;
typedef long double d6;

const d6 EPS = 1 / 100000000.0;
const d6 NINF = -1e25;

struct intv {
  d6 left;
  d6 right;
  i64 id;
};

bool cmp(intv const &a, intv const &b) {
  if (abs(a.left - b.left) < EPS) {
    return a.right > b.right;
  }

  return a.left < b.left;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  d6 l, r;
  i64 n;

  while (cin >> l >> r) {
    cin >> n;
    vector<intv> v(n);

    for (i64 i = 0; i < n; i++) {
      cin >> v[i].left >> v[i].right;
      v[i].id = i;
    }

    sort(v.begin(), v.end(), cmp);

    vi64 res;
    d6 cov = l;
    for (i64 i = 0; i < n; i++) {
      if (v[i].right + EPS < cov) {
        continue;
      }

      if (v[i].left < cov + EPS) {
        d6 maxr = NINF;
        i64 xid;

        for (i64 j = i; (j < n) and (v[j].left < cov + EPS); j++) {
          if (v[j].right > maxr) {
            maxr = v[j].right;
            xid = j;
          }
        }

        if (maxr > NINF) {
          cov = maxr;
          res.push_back(v[xid].id);
          i = xid;
          if (r < cov + EPS) {
            break;
          }
        } else {
          res.clear();
          break;
        }
      } else {
        res.clear();
        break;
      }
    }

    if (cov + EPS < r) {
      res.clear();
    }

    if (res.empty()) {
      cout << "impossible" << endl;
    } else {
      cout << res.size() << endl;
      for (i64 i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
      }
      cout << endl;
    }
  }

  return 0;
}