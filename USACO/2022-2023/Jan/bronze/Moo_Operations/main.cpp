#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

int main() {
  i64 n;
  cin >> n;

  while (n--) {
    str s;
    cin >> s;

    size_t c1 = s.find("MOM");
    size_t c2 = s.find("OOO");
    size_t c3 = s.find("OOM");
    size_t c4 = s.find("MOO");

    // if (!c1 || !c2 || !c3 || !c4) {
    //   i64 c = s.size() - 3;
    //   if(!c4){
    //     cout << c << endl;
    //     continue;
    //   }
    //   if (!c1) {
    //     c += 1;
    //     cout << c << endl;
    //     continue;
    //   }
    //   if (!c2) {
    //     c += 2;
    //   }
    //   if (!c3) {
    //     c += 2;
    //   }
    //   cout << c << endl;
    // } else {
    //   cout << -1 << endl;
    // }

    vi64 v;

    if (!c1) {
      v.push_back(s.size() - 2);
    }
    if (!c2) {
      v.push_back(s.size() - 2);
    }
    if (!c3) {
      v.push_back(s.size() - 1);
    }
    if (!c4) {
      v.push_back(s.size() - 3);
    }

    sort(v.begin(), v.end());

    if (v.size() == 0) {
      cout << -1 << endl;
    } else {
      cout << v[0] << endl;
    }
  }

  return 0;
}