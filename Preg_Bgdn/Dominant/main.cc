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

const i64 NM = 3 * 1e5 + 2;
int f0[NM], f1[NM], s[NM];
map<int, int> freq;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int opt;
  str sss;
  cin >> opt >> sss;

  for (int i = 0; i < sz(sss); i++) {
    char c = sss[i];
    if (c == '0') {
      f0[i + 1] += f0[i];
    } else {
      f1[i + 1] += f1[i];
    }

    s[i + 1] = f1[i + 1] - f0[i + 1];
  }

  int maxres = 0;
  int ss = 0;

  for (int i = 1; i <= sz(sss); i++) {
    ss += s[i];
    if (!freq.count(ss)) {
      freq[ss]++;
    }
    if (ss > 0) {
      maxres = i + 1;
    } else if (freq.count(ss - 1)) {
      int cur = i - freq[ss - 1];
      maxres = max(maxres, cur);
    }
  }

  cout << maxres << endl;

  return 0;
}