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

const int NM = 100000;
int a[NM], b[NM];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"countseqmatch.in"};
  ofstream cout{"countseqmatch.out"};

  map<int, int> fa, fb;

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  int m;
  cin >> m;
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
    fb[b[i]]++;
    fa[a[i]]++;
  }

  i64 res = 0;
  if (fa == fb) {
    res++;
  }

  int i = 2, j = m + 1;
  while (j <= n) {
    if (fa.count(a[i - 1])) {
      fa[a[i - 1]]--;
    }
    if (fa[a[i - 1]] == 0) {
      fa.erase(a[i - 1]);
    }

    fa[a[j]]++;

    if (fa == fb) {
      res++;
    }

    i++;
    j++;
  }

  if (fa == fb) {
    res++;
  }

  cout << res << endl;

  return 0;
}