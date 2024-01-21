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

  i64 n;
  cin >> n;

  vi64 v;
  do {
    v.push_back(n % 2);
  } while (n /= 2);

  i64 res = 0, i = 0;
  while (!v.empty()) {
    res += v.back() * pow(2, i);
    i++;
    v.pop_back();
  }

  cout << res << endl;

  return 0;
}
