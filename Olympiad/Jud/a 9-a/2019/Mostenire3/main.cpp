#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  ifstream cin{"mostenire3.in"};
  ofstream cout{"mostenire3.out"};

  i64 n, k, tot = 0, young = 1e9;
  cin >> n >> k;
  vi64 g(n);
  vi64 pos;
  map<i64, pair<i64, i64>> res;

  for (i64 i = 0; i < n; i++) {
    cin >> g[i];
    tot += g[i];
  }

  i64 crt = 1, s = g[0], div = tot / k, a = 1;
  for (i64 i = 1; i < n; i++) {
    if (abs(div - (s + g[i])) < abs(div - s)) {
      s += g[i];
      crt++;
    } else {
      if (s < young) {
        young = s;
      }
      pos.push_back(s);
      res[a++] = {s, crt};
      s = g[i];
      crt = 1;
    }
  }
  pos.push_back(s);
  res[a++] = {s, crt};

  sort(pos.rbegin(), pos.rend());

  cout << young << endl;
  for (i64 i = 1; i <= k; i++) {
    i64 target = res[i].first;

    i64 l = 0, r = pos.size() - 1;
    while (l <= r) {
      i64 mid = l + (r - l) / 2;
      if (pos[mid] == target) {
        cout << mid + 1;
        break;
      } else if (pos[mid] > target) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }

    cout << " " << res[i].second << endl;
  }

  return 0;
}