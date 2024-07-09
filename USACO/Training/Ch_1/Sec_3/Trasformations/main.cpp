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

/*
ID: Riana Moga (rianamo1)
TASK: transform
LANG: C++
*/

i64 n;
vv mat(n, vi64(n));
vv trans(n, vi64(n));

void rotate90Clockwise(vv &a) {
  for (i32 i = 0; i < n / 2; i++) {
    for (i32 j = i; j < n - i - 1; j++) {
      i32 temp = a[i][j];
      a[i][j] = a[n - 1 - j][i];
      a[n - 1 - j][i] = a[n - 1 - i][n - 1 - j];
      a[n - 1 - i][n - 1 - j] = a[j][n - 1 - i];
      a[j][n - 1 - i] = temp;
    }
  }
}

void reflect(vv &a) {
  for (i64 i = 0; i < n; i++) {
    for (i64 j = 0; j < n / 2; j++) {
      i64 temp = a[i][j];
      a[i][j] = a[i][n - 1 - j];
      a[i][n - 1 - j] = temp;
    }
  }
}

i32 chk() {
  for (i64 i = 1; i <= 3; i++) {
    rotate90Clockwise(mat);
    if (mat == trans)
      return i;
  }

  return -1;
}

i32 slv() {
  vv temp = mat;

  i32 x = chk();
  if (x != -1) {
    return x;
  }

  mat = temp;

  reflect(mat);
  if (mat == trans) {
    return 4;
  }

  x = chk();
  if (x != -1) {
    return 5;
  }

  if (temp == trans) {
    return 6;
  }

  return 7;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin("transform.in");
  ofstream cout("transform.out");

  cin >> n;

  mat.resize(n, vi64(n));
  trans.resize(n, vi64(n));

  for (i64 i = 0; i < n; i++) {
    for (i64 j = 0; j < n; j++) {
      char c;
      cin >> c;
      mat[i][j] = c == '@' ? 1 : 0;
    }
  }

  for (i64 i = 0; i < n; i++) {
    for (i64 j = 0; j < n; j++) {
      char c;
      cin >> c;
      trans[i][j] = c == '@' ? 1 : 0;
    }
  }

  cout << slv() << endl;

  return 0;
}