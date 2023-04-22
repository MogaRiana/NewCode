#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

str alf = "abcdefghijklmnopqrstuvwxyz";

void b_search(char &c) {
  i64 l = 0, r = 25;

  while (l <= r) {
    i64 mid = l + (r - l) / 2;

    if (alf[mid] == c) {
      cout << mid + 1 << endl;
      break;
    } else if (alf[mid] < c) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 t;
  cin >> t;

  while (t--) {
    i64 n;
    str s;
    cin >> n >> s;

    sort(s.begin(), s.end());
    b_search(s[s.size() - 1]);
  }

  return 0;
}