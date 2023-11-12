#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

i64 make_num(str s) {
  i64 num = (s[0] - '0') * 1000 + (s[1] - '0') * 100 + (s[2] - '0') * 10 +
            (s[3] - '0');

  return num;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  i64 n;
  cin >> n;

  while (n--) {
    str name, birth, start;
    double sem;
    cin >> name >> start >> birth >> sem;
    sem /= 5;

    if (make_num(start) >= 2010) {
      cout << name << " eligible" << endl;
      continue;
    } else if (make_num(birth) >= 1991) {
      cout << name << " eligible" << endl;
      continue;
    } else if (sem > 8) {
      cout << name << " ineligible" << endl;
      continue;
    }

    cout << name << " coach petitions" << endl;
  }

  return 0;
}