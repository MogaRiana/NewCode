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

  ifstream cin{"piese1.in"};
  ofstream cout{"piese1.out"};

  int n, k;
  cin >> n >> k;

  i64 crt = 0;
  vi64 v(n);
  for (auto &i : v) {
    cin >> i;
    if (i <= k) {
      crt++;
    }
  }

  srt(v);
  for (int i = 0; i < n - 1; i++) {
    int s = k - v[i], a = 0;
    int l = i + 1, r = n - 1;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      a = mid;
      if (v[mid] <= s) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }

    if (a != 0) {
      crt += (a - i);
    }
  }

  cout << crt << endl;

  return 0;
}