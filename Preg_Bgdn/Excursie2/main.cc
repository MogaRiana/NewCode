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

bool b[1001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  i64 s = n * (n + 1);
  if (s % 6 != 0) {
    cout << "NU" << endl;
    return 0;
  }

  s /= 6;
  for (int k = 0; k < 3; k++) {
    i64 sum = s;
    for (int i = n; i > 0 and sum > 0; i--) {
      if (!b[i] and (sum - i) >= 0) {
        sum -= i;
        b[i] = !b[i];
        cout << i << " ";
      }
    }
    cout << endl;
  }

  return 0;
}