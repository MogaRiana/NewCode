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

bool my_next_perm(int P[], int N) {
  int p = -1;
  while (p > 0 && P[p - 1] > P[p])
    p--;
  if (p == 0) {
    return false;
  }

  int res = p;
  for (int i = p; i < N; i++) {
    if (P[i] > P[p - 1] and P[res] > P[i]) {
      res = i;
    }
  }

  swap(P[p - 1], P[res]);
  reverse(P + p, P + N);
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n = 4;
  int v[n];
  for (int i = 0; i < n; i++) {
    v[i] = i + 1;
  }

  do {
    for (int i = 0; i < n; i++) {
      cout << v[i] << " ";
    }
    cout << endl;
  } while (my_next_perm(v + 1, n));

  return 0;
}