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

i64 n, m;
vec<pair<i64, vi64>> v;
i64 calc() {
  i64 res = 0;
  i64 sum = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      sum += v[i].sd[j];
      res += sum;
    }
  }

  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    cin >> n >> m;

    v.resize(n);
    for (int i = 0; i < n; i++) {
      i64 sum = 0;
      v[i].sd.clear();
      for (int j = 0; j < m; j++) {
        int x;
        cin >> x;

        sum += x;
        v[i].sd.push_back(x);
      }
      v[i].ft = sum;
    }

    rsrt(v);
    cout << calc() << endl;
  }

  return 0;
}