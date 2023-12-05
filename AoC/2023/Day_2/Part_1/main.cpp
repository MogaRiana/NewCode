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
map<str, i64> m = {{"red", 12}, {"green", 13}, {"blue", 14}};

i64 finds(str &s, i64 in) {
  for (i64 k = 0; k < 3; k++) {
    if (s.substr(in, cc[k].size()) == cc[k]) {
      return m[cc[k]];
    }
  }

  return -1;
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
    i64 ss = s[5] - '0';
    if (s[6] >= '0' and s[6] <= '9') {
      ss = ss * 10 + s[6] - '0';
    }
    if (s[7] >= '0' and s[7] <= '9') {
      ss = ss * 10 + s[7] - '0';
    }
    bool ok = false;

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

        if (nr <= finds(s, i + 2)) {
          ok = true;
        } else {
          ok = false;
          break;
        }
      }
    }

    if (ok) {
      sum += ss;
    }
  }

  cout << sum << endl;

  return 0;
}
