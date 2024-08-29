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

i64 n, k;
vi64 v(9);

bool ver1(vi64 &t) {
  for (i64 i = 0; i < n; i++) {
    if (t[i] > v[i]) {
      return false;
    }
  }

  return true;
}

bool ver2(vi64 &t) {
  i64 s = 0;
  for (i64 i = 0; i < n; i++) {
    s += t[i];
  }

  return !(s % k);
}

vi64 t;
set<vi64> s;
void slv(i64 i) {
  if (i == n) {
    if (ver1(t) && ver2(t)) {
      s.insert(t);
    }
    return;
  }

  for (i64 j = 1; j <= v[i]; j++) {
    t.push_back(j);
    slv(i + 1);
    t.pop_back();
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k;

  for (i64 i = 0; i < n; i++) {
    cin >> v[i];
  }

  slv(0);
  for (auto &x : s) {
    for (auto &y : x) {
      cout << y << " ";
    }
    cout << endl;
  }

  return 0;
}