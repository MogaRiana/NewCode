#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef vector<i64> vi64;
typedef string str;

int main() {
  vector<char> v = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                    'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                    's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

  i64 n;
  cin >> n;

  while (n--) {
    i64 x;
    cin >> x;

    bool ok = true;
    vector<char> a;
    for (i64 i = 0; i < 26 and ok; i++) {
      for (i64 j = 0; j < 26 and ok; j++) {
        for (i64 k = 0; k < 26 and ok; k++) {
          if (i + 1 + j + 1 + k + 1 == x) {
            a.push_back(v[i]);
            a.push_back(v[j]);
            a.push_back(v[k]);
            ok = false;
          }
        }
      }
    }

    sort(a.begin(), a.end());
    for (auto &c : a) {
      cout << c;
    }
    cout << endl;
  }

  return 0;
}