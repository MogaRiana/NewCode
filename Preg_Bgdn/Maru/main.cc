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

const int nmax = 403;
int a[nmax][nmax], v[nmax], n, T;

void res() {
  int s = 0;
  long long answer = 0;
  for (int l1 = 1; l1 <= n; l1++) {
    for (int l2 = l1; l2 <= n; l2++) {
      for (int i = 1; i <= n; i++) {
        v[i] = a[l2][i] - a[l1 - 1][i];
      }
      s = 0;

      int j = 1;
      for (int i = 1; i <= n; i++) {
        s += v[i];
        while (s > T) {
          s -= v[j];
          j++;
        }
        answer += (i - j + 1);
      }
    }
  }
  cout << answer << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int A, B, C, D;
  cin >> T >> n >> A >> B >> C >> D;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      a[i][j] = a[i - 1][j] + (A * i + B * j + C) % D;
    }
  }

  res();

  return 0;
}