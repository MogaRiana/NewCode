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
  cout.tie(NULL);

  ifstream cin("input1.txt");
  ofstream cout("output1.txt");

  str s;
  i64 crt = 0;

  while (cin >> s) {
    for (i64 i = 0; i < s.size(); i++) {
      if (s[i] == 'O') {
        crt++;
      }
    }
  }

  cout << crt << endl;

  return 0;
}