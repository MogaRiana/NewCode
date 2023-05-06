#include <bits/stdc++.h>

using namespace std;

// #define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

i64 ver(str &ss, i64 i) {
  i64 n = -1;
  if (ss[i] == 'B' or ss[i] == 'B' or ss[i] == 'F' or ss[i] == 'P' or
      ss[i] == 'V') {
    n = 1;
  } else if (ss[i] == 'C' or ss[i] == 'G' or ss[i] == 'J' or ss[i] == 'K' or
             ss[i] == 'Q' or ss[i] == 'S' or ss[i] == 'X' or ss[i] == 'Z') {
    n = 2;
  } else if (ss[i] == 'D' or ss[i] == 'T') {
    n = 3;
  } else if (ss[i] == 'L') {
    n = 4;
  } else if (ss[i] == 'M' or ss[i] == 'N') {
    n = 5;
  } else if (ss[i] == 'R') {
    n = 6;
  }

  return n;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  str ss;
  while (cin >> ss) {
    i64 nr = -1, r = -1;
    for (i64 i = 0; i < ss.size(); i++) {
      if (nr == -1) {
        if (ver(ss, i) != -1) {
          nr = ver(ss, i);
          r = ver(ss, i);
        }
      } else {
        if (ver(ss, i) != -1 && ver(ss, i) != r) {
          nr = nr * 10 + ver(ss, i);
        }
        r = ver(ss, i);
      }
    }

    cout << nr << endl;
  }

  return 0;
}