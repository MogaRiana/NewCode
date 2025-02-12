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

const int NMAX = 100002;
int n, d;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"vectori.in"};
  ofstream cout{"vectori.out"};

  cin >> n >> d;
  vi64 a(n + 1), b(n + 1), c(n + 1);

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }

  srt(a);
  srt(b);
  srt(c);

  i64 ans1 = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (abs(a[i] - b[j]) <= d) {
        ans1++;
      }
    }
  }
  i64 ans2 = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (abs(a[i] - c[j]) <= d) {
        ans2++;
      }
    }
  }
  i64 ans3 = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (abs(b[i] - c[j]) <= d) {
        ans3++;
      }
    }
  }

  cout << ans1 << " " << ans2 << " " << ans3 << endl;

  // cout << ans << endl;

  return 0;
}