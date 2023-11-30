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

i64 days[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool valid(i64 day, i64 month, i64 year) {
  if (year < 2000 || month > 12 || month == 0 || day == 0) {
    return false;
  }

  if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
    days[1] = 29;
  } else {
    days[1] = 28;
  }

  if (days[month - 1] < day) {
    return false;
  }
  return true;
}

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