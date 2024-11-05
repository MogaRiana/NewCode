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

const i64 MAX = 1e6;
i64 sum[MAX];
i64 ss[MAX];

void s() {
  for (i64 i = 1; i <= MAX; i++) {
    for (i64 j = i; j <= MAX; j += i) {
      sum[j] += i;
    }
  }

  for (i64 i = 1; i <= MAX; i++) {
    ss[i] = ss[i - 1] + sum[i];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"bitcoin.in"};
  ofstream cout{"bitcoin.out"};

  s();

  i64 q;
  cin >> q;

  while (q--) {
    i64 a, b;
    cin >> a >> b;

    cout << ss[b] - ss[a - 1] << endl;
  }

  return 0;
}