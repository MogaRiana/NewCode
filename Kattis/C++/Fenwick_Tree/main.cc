#include <bits/stdc++.h>

using namespace std;

#define endl '\n';
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

i64 pow_2(i64 n) {
  i64 cnt = 1;

  while (cnt < n) {
    cnt *= 2;
  }

  return cnt;
}

void update(i64 pos, i64 val, vi64 &tree) {
  pos += tree.size() / 2;

  tree[pos] += val;

  while (pos != 0) {
    pos /= 2;
    tree[pos] = tree[pos * 2] + tree[pos * 2 + 1];
  }
}

i64 query(i64 rr, vi64 &tree) {
  i64 res = 0;

  i64 ll = tree.size() / 2;
  rr += tree.size() / 2;

  while (ll <= rr) {
    if (ll % 2 == 1) {
      res += tree[ll];
      ll++;
    }
    if (rr % 2 == 0) {
      res += tree[rr];
      rr--;
    }

    ll /= 2;
    rr /= 2;
  }

  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 n, k;
  cin >> n >> k;

  i64 len = pow_2(n);
  vi64 vv(len * 2, 0);

  while (k--) {
    char c;
    cin >> c;

    if (c == '+') {
      i64 pos, val;
      cin >> pos >> val;

      update(pos, val, vv);
    } else if (c == '?') {
      i64 right;
      cin >> right;

      cout << query(right - 1, vv) << endl;
    }
  }

  return 0;
}