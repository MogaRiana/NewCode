#include <bits/stdc++.h>

using namespace std;

// #define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  char ss[25];
  while (cin >> ss) {
    int v[strlen(ss)];
    for (i64 i = 0; i < strlen(ss); i++) {
      if (ss[i] == 'B' or ss[i] == 'F' or ss[i] == 'P' or ss[i] == 'V') {
        v[i] = 1;
      } else if (ss[i] == 'C' or ss[i] == 'G' or ss[i] == 'J' or ss[i] == 'K' or
                 ss[i] == 'Q' or ss[i] == 'S' or ss[i] == 'X' or ss[i] == 'Z') {
        v[i] = 2;
      } else if (ss[i] == 'D' or ss[i] == 'T') {
        v[i] = 3;
      } else if (ss[i] == 'L') {
        v[i] = 4;
      } else if (ss[i] == 'M' or ss[i] == 'N') {
        v[i] = 5;
      } else if (ss[i] == 'R') {
        v[i] = 6;
      } else {
        v[i] = 0;
      }
    }

    if (v[0] != 0) {
      cout << v[0];
    }
    for (i64 i = 1; i < strlen(ss); i++) {
      if (v[i] != 0 and v[i] != v[i - 1]) {
        cout << v[i];
      }
    }

    cout << endl;
  }

  return 0;
}
