#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// #define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;
typedef pair<i64, i64> p64;
typedef vector<p64> vp64;
typedef vector<str> vstr;

typedef tree<p64, null_type, less<p64>, rb_tree_tag,
             tree_order_statistics_node_update>
    tr;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  tr t;

  string s;
  i64 sz = 0;
  i64 crt = 0;
  while (cin >> s) {
    if (s == "#") {
      if (sz % 2 == 0) {
        p64 p = *t.find_by_order(sz / 2);
        cout << p.first << endl;
        t.erase(p);
      } else {
        p64 p = *t.find_by_order((sz + 1) / 2 - 1);
        cout << p.first << endl;
        t.erase(p);
      }

      sz--;
    } else {
      t.insert({stoi(s), crt++});
      sz++;
    }
  }

  return 0;
}