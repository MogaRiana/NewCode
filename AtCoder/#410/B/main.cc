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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, k;
  cin >> n >> k;

  vi64 v(0);
  vi64 aux(n + 1, 0);
  for (int i = 0; i < k; i++) {
    int x;
    cin >> x;

    if (x > 0) {
      v.push_back(x);
      aux[x]++;
    } else {
      int p = 0, m = 1e9;
      for (int j = 1; j <= n; j++) {
        if (aux[j] < m) {
          m = aux[j];
          p = j;
        }
      }

      v.push_back(p);
      aux[p]++;
    }
  }

  for (auto &i : v) {
    cout << i << " ";
  }

  return 0;
}