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

struct DSU {
  vector<int> p, size;
  int comp = 0;
  int mx_Set = 0;

  DSU(int N) {
    p.resize(N + 1);
    size.resize(N + 1, 1);
    comp = N;

    for (int i = 1; i <= N; i++) {
      p[i] = i;
    }
  }

  int find(int x) {
    if (p[x] == x)
      return x;

    return p[x] = find(p[x]);
  }

  void Union(int x, int y) {
    int a = find(x);
    int b = find(y);

    if (a == b)
      return;

    if (size[a] > size[b]) {
      p[b] = a;
      size[a] += size[b];
    } else {
      p[a] = b;
      size[b] += size[a];
    }

    mx_Set = max({mx_Set, size[a], size[b]});
    comp--;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  cin >> n >> m;

  DSU eep(n);

  while (m--) {
    int a, b;
    cin >> a >> b;

    eep.Union(a, b);
    cout << eep.comp << " " << eep.mx_Set << endl;
  }

  return 0;
}