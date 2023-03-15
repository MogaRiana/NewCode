#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

vv pref_sum(vv &v) {
  vv pref = v;

  for (i64 i = 1; i < v.size(); i++) {
    for (i64 j = 1; j < v[0].size(); j++) {
      pref[i][j] += pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
    }
  }

  return pref;
}

i64 nrp(vv &v, i64 l1, i64 c1, i64 l2, i64 c2) {
  i64 a = l2 - l1 + 1;
  i64 res = a * a;
  res -= a;

  return res / 2 + a;
}

i64 nr_one_neg(vv &pref, vv &v, i64 l1, i64 l2) {
  i64 sum = 0;
  for (i64 i = l1; i <= l2; i++) {
    i64 p = pref[i][i] - pref[i - 1][i] - pref[i][0] + pref[i - 1][0];
    sum += p;
  }

  return sum;
}

bool verify(vv &pref, vv &v, i64 l1, i64 c1, i64 l2, i64 c2, i64 pos) {
  i64 nr = nrp(v, l1, c1, l2, c2);
  i64 nrr;

  if (pos == -1) {
    nrr = nr_one_neg(pref, v, l1, l2);
  } else {
    i64 sum = 0;

    for (i64 i = l1; i <= l2; i++) {
      sum += v[i][i];
    }

    i64 p = pref[l2][c2] - pref[l1 - 1][c2] - pref[l2][c2 - 1] +
            pref[l1 - 1][c2 - 1];
    nrr = p - nr_one_neg(pref, v, l1, l2) + sum;
  }

  if (nrr < nr / 2) {
    return true;
  } else {
    return false;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  ifstream cin{"elicop.in"};
  ofstream cout{"elicop.out"};

  i64 l, c;
  cin >> l >> c;
  vv v(l + 1, vi64(c + 1));

  for (i64 i = 1; i <= l; i++) {
    for (i64 j = 1; j <= c; j++) {
      cin >> v[i][j];
    }
  }

  vv pref = pref_sum(v);
  vi64 res;
  i64 t;
  cin >> t;
  for (i64 i = 0; i < t; i++) {
    i64 l1, c1, l2, c2, pos;
    cin >> l1 >> c1 >> l2 >> c2 >> pos;

    if (verify(pref, v, l1, c1, l2, c2, pos)) {
      res.push_back(i + 1);
    }
  }

  cout << t - res.size() << endl;
  cout << res.size();
  for (i64 i = 0; i < res.size(); i++) {
    cout << " " << res[i];
  }

  return 0;
}