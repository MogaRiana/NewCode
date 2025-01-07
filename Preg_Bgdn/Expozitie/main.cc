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

const int N = 10000;
int res[N + 2];

void Div(int x[], int n) {
  int i, r = 0;
  for (i = x[0]; i > 0; i--) {
    r = 10 * r + x[i];
    x[i] = r / n;
    r %= n;
  }
  for (; x[x[0]] == 0 && x[0] > 1;) {
    x[0]--;
  }
}

void Mult(int x[], int n) {
  int i, t = 0;
  for (i = 1; i <= x[0]; i++, t /= 10) {
    t += x[i] * n;
    x[i] = t % 10;
  }
  for (; t; t /= 10) {
    x[++x[0]] = t % 10;
  }
}

void comb(i64 n, i64 k) {
  res[0] = 1;
  res[1] = 1;

  for (int i = 1; i <= k; i++) {
    Mult(res, n - i + 1);
    Div(res, i);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin("expozitie.in");
  ofstream cout("expozitie.out");

  int n, k, d;
  cin >> n >> k >> d;

  int r = n - k * d;
  int m = r + k - 1;

  if (r < 0) {
    cout << "0";
    return 0;
  }

  comb(m, r);

  for (int i = res[0]; i >= 1; i--) {
    cout << res[i];
  }
  cout << endl;

  return 0;
}