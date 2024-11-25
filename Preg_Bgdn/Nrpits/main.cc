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

const int NM = 1000005;
int s[NM], l[NM], r[NM];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"nrpits.in"};
  ofstream cout{"nrpits.out"};

  int n, k = 0;
  cin >> n;

  int v[n + 1];
  v[0] = 1e9;
  for (int i = 1; i <= n; i++) {
    cin >> v[i];

    while (k != 0 and v[i] >= v[s[k]]) {
      k--;
    }
    l[i] = s[k];
    s[++k] = i;
  }

  k = 0;
  for (int i = n; i > 0; i--) {
    while (k != 0 and v[i] >= v[s[k]]) {
      k--;
    }
    r[i] = s[k];
    s[++k] = i;
  }

  int crt = 0;
  for (int i = 1; i <= n; i++) {
    if (l[i] != i - 1 and l[i] != 0) {
      crt++;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (r[i] != i + 1 and r[i] != 0) {
      crt++;
    }
  }

  cout << crt << endl;

  return 0;
}