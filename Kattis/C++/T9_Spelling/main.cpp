#include <bits/stdc++.h>
#include <cstddef>

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

  map<char, str> sum = {
      {'a', "2"},    {'b', "22"},  {'c', "222"}, {'d', "3"},    {'e', "33"},
      {'f', "333"},  {'g', "4"},   {'h', "44"},  {'i', "444"},  {'j', "5"},
      {'k', "55"},   {'l', "555"}, {'m', "6"},   {'n', "66"},   {'o', "666"},
      {'p', "7"},    {'q', "77"},  {'r', "777"}, {'s', "7777"}, {'t', "8"},
      {'u', "88"},   {'v', "888"}, {'w', "9"},   {'x', "99"},   {'y', "999"},
      {'z', "9999"}, {' ', "0"}};

  i64 t, a = 1;
  cin >> t;
  cin.ignore();

  while (a <= t) {
    str s;
    getline(cin, s);

    cout << "Case #" << a++ << ": " << sum[s[0]];
    for (i64 i = 1; i < s.size(); i++) {
      if (sum[s[i]].front() == sum[s[i - 1]].front()) {
        cout << " ";
      }

      cout << sum[s[i]];
    }

    cout << endl;
  }

  return 0;
}