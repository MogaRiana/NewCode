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

const vector<str> num = {"one", "two",   "three", "four", "five",
                         "six", "seven", "eight", "nine"};

map<str, i64> m = {{"one", 1},   {"two", 2},   {"three", 3},
                   {"four", 4},  {"five", 5},  {"six", 6},
                   {"seven", 7}, {"eight", 8}, {"nine", 9}};

pair<p64, p64> findn(str &s) {
  pair<p64, p64> res = {{-1, 1e9}, {-1, -1e9}};

  for (i64 k = 0; k < num.size(); k++) {
    for (int i = 0; i < s.size(); i++) {
      if (s.substr(i, num[k].size()) == num[k]) {
        if (i < res.first.second) {
          res.first = {m[num[k]], i};
        }
        if (i > res.second.second) {
          res.second = {m[num[k]], i};
        }
      }
    }
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"input.in"};
  ofstream cout{"output.out"};

  i64 sum = 0;
  str s;
  while (cin >> s) {
    p64 ft = {-1, -1}, sc = {-1, -1};

    for (i64 i = 0; i < s.size(); i++) {
      if (s[i] > '0' and s[i] <= '9') {
        if (ft.first == -1) {
          ft.first = s[i] - '0';
          ft.second = i;
        }
        sc.first = s[i] - '0';
        sc.second = i;
      }
    }

    p64 ft2 = findn(s).first;
    p64 sc2 = findn(s).second;

    i64 n1, n2;
    if (ft.first != -1 and sc.first != -1) {
      if (ft.second < ft2.second) {
        n1 = ft.first;
      } else {
        n1 = ft2.first;
      }
      if (sc.second > sc2.second) {
        n2 = sc.first;
      } else {
        n2 = sc2.first;
      }
    } else {
      n1 = ft2.first;
      n2 = sc2.first;
    }

    // cout << n1 << n2 << endl;
    sum += n1 * 10 + n2;
  }

  cout << endl << sum << endl;

  return 0;
}