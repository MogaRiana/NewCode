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

  i64 posl = 8;
  str s;
  map<char, vector<pair<char, i64>>> b;
  map<char, vector<pair<char, i64>>> w;
  for (i64 i = 0; i < 8; i++, posl--) {
    char posc = 'a';
    cin >> s >> s;

    for (i64 j = 2; j < s.size(); j += 4, posc++) {
      if (s[j] >= 'a' and s[j] <= 'z') {
        b[s[j]].push_back({posc, posl});
      } else if (s[j] >= 'A' and s[j] <= 'Z') {
        w[s[j]].push_back({posc, posl});
      }
    }
  }
  cin >> s;

  return 0;
}