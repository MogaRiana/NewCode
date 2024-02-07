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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  list<char> l;
  l.push_back('a');
  l.push_back('n');
  l.push_back('a');

  auto it = l.begin();
  it++;
  it = l.insert(it, 'm');
  it = l.erase(it);

  for (auto &c : l) {
    cout << c;
  }

  return 0;
}
