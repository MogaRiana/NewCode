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

vector<str> cc = {"red", "green", "blue"};

str finds(str &s, i64 in) {
  str res;
  for (i64 k = 0; k < 3; k++) {
    if (s.substr(in, cc[k].size()) == cc[k]) {
      res = cc[k];
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
  while (getline(cin, s)) {
    i64 ss = 1;
    map<str, i64> res = {{"red", -1e9}, {"green", -1e9}, {"blue", -1e9}};

    for (i64 i = 8; i < s.size(); i++) {
      if (s[i] >= '0' and s[i] <= '9') {
        i64 nr = s[i] - '0';

        if (s[i + 1] >= '0' and s[i + 1] <= '9') {
          nr = nr * 10 + s[i + 1] - '0';
          i++;
        }
        if (s[i + 1] >= '0' and s[i + 1] <= '9') {
          nr = nr * 10 + s[i + 1] - '0';
          i++;
        }

        str col = finds(s, i + 2);
        res[col] = max(res[col], nr);
      }
    }

    for (auto &x : res) {
      ss *= x.second;
    }
    sum += ss;
  }

  cout << sum << endl;

  return 0;
}
