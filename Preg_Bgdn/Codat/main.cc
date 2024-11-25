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

#define nmax 1000002
int st[nmax], l[nmax], r[nmax];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"codat.in"};
  ofstream cout{"codat.out"};

  int n, k = 0, m = 0;
  cin >> n;
  int v[n + 1];

  for (int i = 1; i <= n; i++) {
    cin >> v[i];
    m = max(m, v[i]);

    while (k != 0 and v[i] >= v[st[k]]) {
      k--;
    }
    l[i] = st[k];
    st[++k] = i;
  }

  k = 0;
  st[k] = n + 1;
  for (int i = n; i > 0; i--) {
    while (k != 0 and v[i] >= v[st[k]]) {
      k--;
    }
    r[i] = st[k];
    st[++k] = i;
  }

  int mm = 1e9, pm = 0;
  for (int i = 1; i <= n; i++) {
    if (v[i] == m) {
      v[i] = -1;
      continue;
    }
    mm = 1e9;
    if (l[i] != 0 && i - l[i] < mm) {
      mm = i - l[i];
      pm = l[i];
    }
    if (r[i] != n + 1 && r[i] - i <= mm) {
      mm = r[i] - i;
      pm = r[i];
    }
    v[i] = pm;
  }

  for (int i = 1; i <= n; i++) {
    cout << v[i] << " ";
  }

  return 0;
}