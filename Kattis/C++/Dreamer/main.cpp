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

bool leap(i64 year) {
  if ((year % 4 == 0) && ((year % 400 == 0) || (year % 100 != 0))) {
    return true;
  }

  return false;
}

bool valid(i64 d, i64 m, i64 y) {
  if (y >= 2000 and m >= 1 and m < 13 and d >= 1 and d < 32) {
    if (d == 29 and m == 2) {
      return leap(y);
    } else if ((m < 8 and m > 0 and m % 2 == 1) or
               (m < 13 and m > 7 and m % 2 == 0)) {
      if (d <= 31) {
        return true;
      }
      return false;
    } else if ((m < 7 and m > 0 and m % 2 == 0) or
               (m < 13 and m > 7 and m % 2 == 1)) {
      if (d <= 30) {
        return true;
      }
      return false;
    }
  }

  return false;
}

/*
1 3 5 7 8 10 12
2 4 6 9 11
*/

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 t;
  cin >> t;

  cin.ignore();

  while (t--) {
    vi64 v;
    str s;
    getline(cin, s);

    for (i64 i = 0; i < s.size(); i++) {
      if (s[i] != ' ') {
        v.push_back(s[i] - '0');
      }
    }

    sort(v.begin(), v.end());
    i64 crt = 0;
    i64 resy = 1e9, resm = 1e9, resd = 1e9;

    do {
      i64 day = v[0] * 10 + v[1];
      i64 month = v[2] * 10 + v[3];
      i64 year = v[4] * 1000 + v[5] * 100 + v[6] * 10 + v[7];

      if (valid(day, month, year)) {
        crt++;

        if (year < resy) {
          resy = year;
          resm = month;
          resd = day;
        } else if (year == resy) {
          if (month < resm) {
            resy = year;
            resm = month;
            resd = day;
          } else if (month == resm) {
            if (day < resd) {
              resy = year;
              resm = month;
              resd = day;
            }
          }
        }
      }
    } while (next_permutation(v.begin(), v.end()));

    if (crt) {
      cout << crt << " ";
      if (resd < 10) {
        cout << 0;
      }
      cout << resd << " ";
      if (resm < 10) {
        cout << 0;
      }
      cout << resm << " " << resy << endl;
    } else {
      cout << 0 << endl;
    }
  }

  return 0;
}