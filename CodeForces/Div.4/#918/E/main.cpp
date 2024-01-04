#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;
typedef pair<i64, i64> p64;
typedef vector<p64> vp64;

void f(i64 &sum1, i64 &sum2, vi64 &p, vi64 &im, i64 i, i64 j) {
  if (i == 0) {
    if (im[j] == 0) {
      sum1 = im[j - 1];
      sum2 = p[j];
    } else {
      sum1 = im[j];
      sum2 = p[j - 1];
    }
  } else {
    if (im[j] == 0) {
      if (im[i - 1] == 0) {
        sum1 = im[j - 1] - im[i - 2];
        sum2 = p[j] - p[i - 1];
      } else {
        sum1 = im[j - 1] - im[i - 1];
        if (i <= 1) {
          sum2 = p[j];
        } else {
          sum2 = p[j] - p[i - 2];
        }
      }
    } else {
      if (im[i - 1] == 0) {
        sum1 = im[j] - im[i - 2];
        sum2 = p[j - 1] - p[i - 1];
      } else {
        sum1 = im[j] - im[i - 1];
        if (i <= 1) {
          sum2 = p[j - 1];
        } else {
          sum2 = p[j - 1] - p[i - 2];
        }
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 t;
  cin >> t;

  while (t--) {
    i64 n;
    cin >> n;

    vi64 p(n, 0), im(n, 0), v(n);
    for (i64 i = 0; i < n; i++) {
      cin >> v[i];

      if ((i + 1) % 2 == 0) {
        if (i == 1) {
          p[i] = v[i];
        } else {
          p[i] = v[i] + p[i - 2];
        }
      } else {
        if (i == 0) {
          im[i] = v[i];
        } else {
          im[i] = v[i] + im[i - 2];
        }
      }
    }

    bool ok = true;
    for (i64 i = 0; i < n and ok; i++) {
      for (i64 j = i + 1; j < n and ok; j++) {
        i64 sum1, sum2;
        f(sum1, sum2, p, im, i, j);

        if (sum1 == sum2) {
          ok = false;
        }
      }
    }

    if (!ok) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}
