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

i64 powtwo(i64 n) {
  i64 crt = 1;
  while (crt < n) {
    crt *= 2;
  }
  return crt * 2;
}

class segtree {
private:
  i64 n, len;
  vi64 tree;

  void build(vi64 &tr) {
    for (i64 i = 0; i < n; i++) {
      tree[i + len] = tr[i];
    }

    i64 start = len / 2, end = len;
    while (start != 0) {
      for (i64 i = start; i < end; i++) {
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
      }
      start /= 2;
      end /= 2;
    }
  }

public:
  segtree(vi64 &tr) {
    n = sz(tr);
    tree.resize(powtwo(n) * 2, 0);
    len = sz(tree) / 2;
  }

  void update(i64 pos, i64 n) {
    pos += len;
    tree[pos] += n;
    while (pos != 0) {
      pos /= 2;
      tree[pos] = tree[pos * 2] + tree[pos * 2 + 1];
    }
  }

  i64 query(i64 l, i64 r) {
    l += len;
    r += len;
    i64 ans = 0;

    while (l <= r) {
      if (l % 2 == 1) {
        ans += tree[l];
        l++;
      }
      if (r % 2 == 0) {
        ans += tree[r];
        r--;
      }

      l /= 2;
      r /= 2;
    }

    return ans;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 n, q;
  cin >> n >> q;

  vi64 tr(n, 0);
  segtree tree(tr);

  while (q--) {
    char c;
    cin >> c;

    if (c == '?') {
      i64 r;
      cin >> r;
      cout << tree.query(0, r - 1) << endl;
    } else {
      i64 pos, val;
      cin >> pos >> val;
      tree.update(pos, val);
    }
  }

  return 0;
}