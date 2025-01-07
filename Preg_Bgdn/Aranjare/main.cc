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

int freq[100002];
int fact[200002];
const int MOD = 100019;

void PreProcess() {
  fact[0] = 1;

  for (int i = 1; i < 200002; i++) {
    fact[i] = (1LL * fact[i - 1] * i) % MOD;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  PreProcess();

  int n, p;
  cin >> n >> p;

  for (int i = 1; i <= n; i++) {
    freq[i % p]++;
  }

  i64 res = 1;
  for (int i = 0; i < p; i++) {
    res = (res * fact[freq[i]]) % MOD;
  }

  cout << res << endl;

  return 0;
}