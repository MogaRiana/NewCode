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

i32 v[1001];
int a[1001][1001];
int st[10001];
short n, m;

int maxsz() {
  short res = 0, k = 0;
  short tp, cur;

  for (int i = 0; i < n; i++) {
    while (k != 0 and v[st[k]] >= v[i]) {
      tp = st[k];
      k--;
      short w = k == 0 ? i : i - st[k] - 1;
      res = max(res, short(w * v[tp]));
    }
    st[++k] = i;
  }

  while (k != 0) {
    tp = st[k];
    k--;
    cur = v[tp] * (k == 0 ? n : n - st[k] - 1);
    res = max(res, cur);
  }

  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"hambar2.in"};
  ofstream cout{"hambar2.out"};

  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    a[x][y] = 1;
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] == 0) {
        v[j]++;
      } else {
        v[j] = 0;
      }
    }
    ans = max(ans, maxsz());
  }

  cout << ans << endl;

  return 0;
}