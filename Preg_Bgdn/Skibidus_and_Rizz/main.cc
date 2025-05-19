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

void print(int &c, int k, int idx) {
  if (idx == k) {
    return;
  }
  cout << c;
  print(c, k, idx + 1);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;

    if (max(n, m) < k or abs(n - m) > k) {
      cout << -1 << endl;
      continue;
    }

    p64 cst = {n, 0}, cfn = {m, 1};
    if (m > n) {
      swap(cst, cfn);
    }

    for (int i = 0; i < k; i++) {
      cout << cst.sd;
      cst.ft--;
    }

    while (cfn.ft) {
      cout << cfn.sd;
      cfn.ft--;
      swap(cst, cfn);
    }

    swap(cst, cfn);
    while (cfn.ft) {
      cout << cfn.sd;
      cfn.ft--;
    }
    cout << endl;
  }

  return 0;
}