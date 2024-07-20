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

bool ver(str &v, i32 k) {
  i32 n = v.size();
  vi32 t;
  for (i32 i = 0; i <= n - k; i++) {
    t.clear();
    for (i32 j = i; j < i + k; j++) {
      t.push_back(v[j]);
    }

    vi32 temp = t;
    rvs(t);
    if (t == temp) {
      return true;
    }
  }

  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i32 n, k;
  cin >> n >> k;

  str v;
  cin >> v;

  srt(v);
  i32 crt = 0;
  while (next_permutation(v.begin(), v.end())) {
    if (!ver(v, k)) {
      crt++;
    }
  }

  if (!ver(v, k)) {
    crt++;
  }

  cout << crt << endl;

  return 0;
}