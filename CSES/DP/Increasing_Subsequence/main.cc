#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ft first
#define sd second
#define sz(x) (i64) x.size()
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

int power_of_two(int n) {
  int crt = 1;
  while (crt < n) {
    crt *= 2;
  }

  return crt * 2;
}

class SegmentTree {
private:
  int n;
  vector<int> tree;
  int len;

public:
  SegmentTree(vector<int> &tr) {
    n = tr.size();
    tree.resize(power_of_two(n), 0);
    len = tree.size() / 2;
  }

  void update(int pos, int value) {
    pos = pos + len - 1;
    tree[pos] = value;

    while (pos != 0) {
      pos = pos / 2;
      tree[pos] = max(tree[pos * 2], tree[pos * 2 + 1]);
    }
  }

  int query(int l, int r) {
    l = l + len - 1;
    r = r + len - 1;
    int res = 0;

    while (l <= r) {
      if (l % 2 == 1) {
        res = max(res, tree[l]);
        l++;
      }
      if (r % 2 == 0) {
        res = max(res, tree[r]);
        r--;
      }
      r /= 2;
      l /= 2;
    }

    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i32 n;
  cin >> n;

  vi32 a(n);
  set<i32> s;
  for (i32 i = 0; i < n; i++) {
    cin >> a[i];
    s.insert(a[i]);
  }

  map<i32, i32> m;
  i32 idx = 1;
  for (auto &e : s) {
    m[e] = idx++;
  }

  vi32 v(n, 0);
  SegmentTree t(v);

  i32 res = 0;
  for (i32 i = 0; i < n; i++) {
    i32 aux = m[a[i]];
    i32 idk = t.query(1, aux - 1);
    res = max(res, idk + 1);
    t.update(aux, idk + 1);
  }

  cout << res << endl;

  return 0;
}

/*
7 5 1 2 3 10 6

1 2 3 5 6 7 10
1 2 3 4 5 6 7

0 0 0 0 0 0 0
*/