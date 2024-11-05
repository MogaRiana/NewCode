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

int f[1000001], f1[1000001], n, val, k, m;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"cmmdc1.in"};
  ofstream cout{"cmmdc1.out"};

  int n, k;
  cin >> n >> k;

  for (int i = 1; i <= n; ++i) {
    cin >> val;
    f[val]++;
    m = max(m, val);
  }

  for (int i = 1; i <= m; i++) {
    for (int j = i; j <= m; j += i) {
      f1[i] += f[j];
    }
  }

  for (int i = m; i >= 0; i--) {
    if (f1[i] >= k) {
      cout << i << endl;

      for (int j = m / i * i; j; j -= i) {
        while (f[j] > 0) {
          cout << j << " ";
          --f[j];
          if (--k == 0) {
            return 0;
          }
        }
      }
    }
  }

  return 0;
}