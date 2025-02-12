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
  vi64 a(n), b(n), c(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }

  // srt(a);
  srt(b);
  srt(c);

  i64 ans = 0;
  for (int i = 0; i < n; i++) {
    int b1 = upper_bound(b.begin(), b.end(), a[i] + d) - b.begin();
    int b2 = lower_bound(b.begin(), b.end(), a[i] - d) - b.begin();
    int c1 = upper_bound(c.begin(), c.end(), a[i] + d) - c.begin();
    int c2 = lower_bound(c.begin(), c.end(), a[i] - d) - c.begin();

    for (int j = b2; j < b1; j++) {
      int ll = lower_bound(c.begin(), c.end(), b[j] - d) - c.begin();
      int rr = upper_bound(c.begin(), c.end(), b[j] + d) - c.begin();

      ans += min(c1, rr) - max(c2, ll);
    }
  }

  cout << ans << endl;

  return 0;
}