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
typedef vector<i32> vi32;
typedef vector<vi32> vv3;
typedef string str;
typedef pair<i32, i32> p32;
typedef vector<p32> vp3;
typedef vector<str> vstr;

i32 dist(p32 a, p32 b) { return abs(a.ft - b.ft) + abs(a.sd - b.sd); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"traseu.in"};
  ofstream cout{"traseu.out"};

  i32 n, m;
  i32 crt;

  cin >> n >> m;

  vp3 v(n * m + 1);
  for (i32 i = 0; i < n; i++) {
    for (i32 j = 0; j < m; j++) {
      i32 x;
      cin >> x;
      v[x] = {i, j};
    }
  }

  i32 res = -1;
  for (i32 i = 1; i < n * m + 1; i++) {
    for (i32 j = i - 1; j > 0; j--) {
      if (v[j].ft <= v[i].ft and v[j].sd <= v[i].sd) {
        res = max(res, dist(v[i], v[j]) + 1);
      }
    }
  }

  cout << res << endl;

  return 0;
}