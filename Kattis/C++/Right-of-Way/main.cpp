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

  map<str, pair<str, str>> m = {{"South", {"West", "East"}},
                                {"West", {"North", "South"}},
                                {"North", {"East", "West"}},
                                {"East", {"South", "North"}}};

  str a, b, c;
  cin >> a >> b >> c;

  if (((b != m[a].first and b != m[a].second) and c == m[a].second) or
      (b == m[a].first and c != m[a].first)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
