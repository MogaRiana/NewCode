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

int freq[27];
const int MOD = 1e9 + 7;

i64 bpow(i64 n, i64 p) {
  if (p == 0) {
    return 1;
  }
  if (p == 1) {
    return n % MOD;
  }

  if (p % 2 == 0) {
    i64 ans = bpow(n, p / 2);
    return (ans * ans) % MOD;
  } else {
    return (bpow(n, p - 1) * (n % MOD)) % MOD;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"trumperika.in"};
  ofstream cout{"trumperika.out"};

  int q;
  cin >> q;

  while (q--) {
    int n;
    cin >> n;

    map<int, vi64> m;
    vi64 sum(n + 1);
    for (int i = 1; i <= 26; i++) {
      m[i].push_back(0);
      freq[i] = 0;
    }

    int s[n + 1];
    for (int i = 1; i <= n; i++) {
      char c;
      cin >> c;

      s[i] = c - 'a' + 1;
      freq[s[i]]++;

      for (int ii = 1; ii <= 26; ii++) {
        m[ii].push_back(freq[ii]);

        if (m[ii].back() != 0) {
          sum[i]++;
        }
      }
    }

    int res = 0;
    for (int r = 1; r <= n; r++) {
      for (int l = 1; l <= r; l++) {
        int sums = 0;
        for (int k = 1; k <= 26; k++) {
          int sm = m[k][r] - m[k][l - 1];
          sums += bpow(k, sm);
        }
        res = (res + sums) % MOD;
      }
    }

    cout << res << endl;
  }

  return 0;
}