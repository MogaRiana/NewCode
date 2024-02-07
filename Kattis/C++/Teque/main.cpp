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

  i64 q;
  cin >> q;

  deque<i64> pb, pf;
  while (q--) {
    str s;
    i64 n;
    cin >> s >> n;

    if (s == "push_back") {
      pb.push_back(n);
    } else if (s == "push_front") {
      pf.push_front(n);
    } else if (s == "push_middle") {
      pf.push_back(n);
    } else if (s == "get") {
      if (n < pf.size()) {
        cout << pf[n] << endl;
      } else {
        cout << pb[n - pf.size()] << endl;
      }
    }

    if (pf.size() == pb.size() + 2) {
      pb.push_front(pf.back());
      pf.pop_back();
    } else if (pf.size() + 1 == pb.size()) {
      pf.push_back(pb.front());
      pb.pop_front();
    }
  }

  return 0;
}
