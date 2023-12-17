#include <algorithm>
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
typedef vector<p64> vp64;

bool b_search(vi64 &v, i64 num) {
  i64 l = 0, r = v.size() - 1;

  while (l <= r) {
    i64 mid = l + (r - l) / 2;

    if (v[mid] == num) {
      return true;
    } else if (v[mid] < num) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }

  return false;
}

bool b_search_cp(vp64 &v, i64 num) {
  i64 l = 0, r = v.size() - 1;

  while (l <= r) {
    i64 mid = l + (r - l) / 2;

    if (v[mid].first == num) {
      return true;
    } else if (v[mid].first < num) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }

  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"input.in"};
  ofstream cout{"output.out"};

  str s;
  i64 c;
  i64 sum = 0;
  map<i64, i64> cp;
  while (getline(cin, s)) {
    vi64 nr, v;
    bool ok = false;

    if (s[6] != ' ') {
      c = (s[6] - '0') * 10 + (s[7] - '0');
    } else {
      c = s[7] - '0';
    }

    for (i64 i = 10; i < s.size(); i++) {
      if (s[i] != ' ') {
        if (s[i] == '|') {
          ok = true;
        } else {
          i64 n;
          if (i < s.size() - 1 and s[i + 1] != ' ') {
            n = (s[i] - '0') * 10 + (s[i + 1] - '0');
            i++;
          } else {
            n = s[i] - '0';
          }

          if (!ok) {
            nr.push_back(n);
          } else {
            v.push_back(n);
          }
        }
      }
    }

    i64 crt = 0;
    sort(nr.begin(), nr.end());
    for (i64 i = 0; i < v.size(); i++) {
      if (b_search(nr, v[i])) {
        crt++;
      }
    }

    if (c == 1) {
      for (i64 i = c + 1; i <= c + crt; i++) {
        cp[i]++;
      }
    } else {
      for (i64 i = c + 1; i <= c + crt; i++) {
        cp[i] += cp[c] + 1;
      }
    }
  }

  sum += c;
  for (auto &x : cp) {
    if (x.first > c) {
      break;
    }
    sum += x.second;
  }

  cout << sum << endl;

  return 0;
}
