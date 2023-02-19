#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef int i32;
typedef short i16;
typedef int8_t i8;
typedef long double d64;
typedef deque<i64> di64;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
#define endl '\n'

i64 make_num(string s) {
  i64 num = s[1] - 48;
  for (i64 i = 2; i < s.size(); i++) {
    num = num * 10 + s[i] - 48;
  }

  return num;
}

i64 search_pos(i64 a, vi64 &v) {
  i64 pos;
  for (i64 i = 0; i < v.size(); i++) {
    if (v[i] == a) {
      pos = i;
      break;
    }
  }

  return pos;
}

vi64 rearange(vi64 &v, i64 pw, i64 pl, i64 l) {
  v.push_back(-1);
  for (i64 i = v.size() - 1; i > pw; i--) {
    v[i] = v[i - 1];
  }
  v[pw + 1] = l;

  for (i64 i = pl; i < v.size() - 1; i++) {
    v[i] = v[i + 1];
  }
  v.pop_back();

  return v;
}

int main() {
  i64 n, k;
  cin >> n >> k;
  vi64 v(n);
  for (i64 i = 0; i < n; i++) {
    v[i] = i + 1;
  }

  while (k--) {
    string win, los;
    cin >> win >> los;
    i64 w = make_num(win), l = make_num(los);
    i64 posw = search_pos(w, v), posl = search_pos(l, v);

    if (posw > posl) {
      rearange(v, posw, posl, l);
    }
  }

  for (i64 i = 0; i < v.size(); i++) {
    cout << "T" << v[i] << " ";
  }

  return 0;
}