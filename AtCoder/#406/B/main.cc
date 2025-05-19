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

void Mult(int x[], i64 n) {
  int i, t = 0;
  for (i = 1; i <= x[0]; i++, t /= 10) {
    t += x[i] * n;
    x[i] = t % 10;
  }
  for (; t; t /= 10)
    x[++x[0]] = t % 10;
}

int idx[2001];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, k;
  cin >> n >> k;

  idx[1] = 1;
  idx[0] = 1;
  while (n--) {
    i64 a;
    cin >> a;

    Mult(idx, a);
    int cond = 0;
    for (int i = 2000; i > 0; i--) {
      if (idx[i] == 0) {
        cond++;
      } else {
        break;
      }
    }

    cond = 2000 - cond;

    if (cond > k) {
      for (int i = 1; i < 2001; i++) {
        idx[i] = 0;
      }
      idx[0] = 1;
      idx[1] = 1;
    } else {
      idx[0] = cond;
    }
  }

  bool ok = false;
  for (int i = 2000; i > 0; i--) {
    if (idx[i] != 0) {
      if (!ok) {
        ok = true;
      }
    }

    if (ok) {
      cout << idx[i];
    }
  }

  return 0;
}