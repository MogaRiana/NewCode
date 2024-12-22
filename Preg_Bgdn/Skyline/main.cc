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

const int NM = 4 * 1e4 + 1;
int v[NM], s[NM], d[NM];
i64 sum[NM];
i64 st[NM];
int n;

i64 maxsz() {
  i64 res = 0, k = 0;

  for (int i = 1; i <= n; i++) {
    while (k != 0 and v[st[k]] >= v[i]) {
      k--;
    }
    s[i] = st[k];
    st[++k] = i;
  }

  k = 0;
  st[k] = n + 1;
  for (int i = n; i > 0; i--) {
    while (k != 0 and v[st[k]] >= v[i]) {
      k--;
    }
    d[i] = st[k];
    st[++k] = i;
  }

  for (int i = 1; i <= n; i++) {
    res = max(res, (i64)(v[i] * (sum[d[i] - 1] - sum[s[i]])));
  }

  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"skyline.in"};
  ofstream cout{"skyline.out"};

  cin >> n;

  cin >> v[1] >> sum[1];
  for (int i = 2; i <= n; i++) {
    cin >> v[i] >> sum[i];
    sum[i] += sum[i - 1];
  }

  cout << maxsz() << endl;

  return 0;
}