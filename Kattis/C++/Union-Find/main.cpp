#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
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
typedef pair<i32, i32> p64;
typedef string str;
typedef vector<i64> vi64;
typedef vec<i32> vi32;
typedef vec<vi32> vv;
typedef vec<p64> vp64;
typedef vec<str> vstr;

class unionfind {
private:
  vi64 p, rank;
  i64 numset;

public:
  unionfind(i64 n) {
    p.assign(n, 0);
    rank.assign(n, 0);
    numset = n;
    for (i64 i = 0; i < n; i++) {
      p[i] = i;
    }
  }

  i64 find(i64 i) { return (p[i] == i) ? i : (p[i] = find(p[i])); }
  bool same(i64 i, i64 j) { return (find(p[i]) == find(p[j])); }

  void unite(i64 i, i64 j) {
    if (same(i, j)) {
      return;
    }
    i64 pi = find(i), pj = find(j);
    if (rank[pi] > rank[pj]) {
      swap(pi, pj);
    }
    p[pj] = pi;
    numset--;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 n, q;
  cin >> n >> q;

  unionfind uf(n);
  while (q--) {
    char c;
    i64 a, b;
    cin >> c >> a >> b;

    if (c == '?') {
      if (uf.same(a, b)) {
        cout << "yes" << endl;
      } else {
        cout << "no" << endl;
      }
    } else {
      uf.unite(a, b);
    }
  }

  return 0;
}