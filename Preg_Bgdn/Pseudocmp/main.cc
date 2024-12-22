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

const i64 N_MAX = 100000;
const i64 V_MAX = 1000000;

int P, N;
int A[N_MAX + 5];
int freq[V_MAX + 5];

int dsum(int x) {
  int ret = 0;
  while (x) {
    ret += x % 10;
    x /= 10;
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin("pseudocmp.in");
  ofstream cout("pseudocmp.out");

  cin >> P >> N;
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
    freq[A[i]]++;
  }

  int L = 0;
  for (int i = 1; i <= V_MAX; i++) {
    while (freq[i]--) {
      A[++L] = i;
    }
    freq[i] = 0;
  }

  if (P == 1) {
    for (int i = 2; i <= N; i++) {
      if (dsum(A[i - 1]) > dsum(A[i])) {
        cout << A[i - 1] << " " << A[i] << endl;
        return 0;
      }
    }

    cout << -1 << endl;

    return 0;
  }
  if (P == 2) {
    long long ans = 0;
    for (int i = 1; i <= N; i++) {
      int sum = dsum(A[i]);
      for (int j = sum + 1; j <= 54; j++) {
        ans += freq[j];
      }
      freq[sum]++;
    }
    cout << ans << endl;
  }
  return 0;
}