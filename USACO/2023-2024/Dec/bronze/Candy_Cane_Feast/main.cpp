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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 n, m;
  cin >> n >> m;

  vi64 cow(n);
  for (i64 i = 0; i < n; i++) {
    cin >> cow[i];
  }

  for (i64 j = 0; j < m; j++) {
    p64 h{0, 0};
    cin >> h.second;
    for (i64 i = 0; i < n; i++) {
      if (cow[i] >= h.first and cow[i] <= h.second) {
        i64 k = cow[i];
        cow[i] += cow[i] - h.first;
        h.first += k - h.first;
      } else if (cow[i] >= h.second and h.first != h.second) {
        cow[i] += h.second - h.first;
        h.first = h.second;
        break;
      }
    }
  }

  for (i64 i = 0; i < n; i++) {
    cout << cow[i] << endl;
  }

  return 0;
}
