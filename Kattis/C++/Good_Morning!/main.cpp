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

vv g = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {-1, 0, -1}};
vi64 dirx = {1, 0};
vi64 diry = {0, 1};

bool ver(i64 x, i64 y) { return x >= 0 and x < 4 and y >= 0 and y < 3; }

void backtrack(str &s, p64 st) {
  str hi = "9999999", lo = "0000000";
  deq<p64> q;
  q.push_back(st);

  while (!q.empty()) {
    p64 cur = q.front();
    q.pop_front();

    for (i64 k = 0; k < 2; k++) {
      i64 x = cur.ft + dirx[k];
      i64 y = cur.sd + diry[k];

      if (ver(x, y) and g[x][y] != -1) {
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  map<i64, p64> pos = {{1, {0, 0}}, {2, {0, 1}}, {3, {0, 2}}, {4, {1, 0}},
                       {5, {1, 1}}, {6, {1, 2}}, {7, {2, 0}}, {8, {2, 1}},
                       {9, {2, 2}}, {0, {3, 1}}};

  i64 t;
  cin >> t;

  while (t--) {
    str s;
    cin >> s;

    p64 st = pos[s[0] - '0'];
  }

  return 0;
}