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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"input.in"};
  ofstream cout{"output.out"};

  i64 sum = 0;
  str s;
  while (cin >> s) {
    i64 ft = -1, sc = -1;
    for (i64 i = 0; i < s.size(); i++) {
      if (s[i] >= '0' and s[i] <= '9') {
        if (ft == -1) {
          ft = s[i] - '0';
        }
        sc = s[i] - '0';
      }
    }

    sum += ft * 10 + sc;
  }

  cout << sum << endl;

  return 0;
}
