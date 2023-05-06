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

  str ss;
  getline(cin, ss);

  str r;
  map<str, i64> res;
  for (i64 i = 0; i < ss.size(); i++) {
    if (ss[i] == ' ') {
      res[r]++;
      r = "";
    } else {
      r.push_back(ss[i]);
    }
  }
  res[r]++;

  bool ok = true;
  for (auto &x : res) {
    if (x.second > 1) {
      cout << "no" << endl;
      ok = false;
      break;
    }
  }

  if (ok) {
    cout << "yes" << endl;
  }

  return 0;
}