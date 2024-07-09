#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ft first
#define sd second
#define sz(x) (i64) x.size()
#define col(x) x.begin(), x.end()
#define srt(x) sort(x.begin(), x.end())
#define rsrt(x) sort(x.rbegin(), x.rend())
#define rvs(x) reverse(x.begin(), x.end())
#define LSOne(S) ((S) & (-S))

template <typename T> using vec = vector<T>;
template <typename T> using deq = deque<T>;

typedef int64_t i64;
typedef int32_t i32;
typedef int16_t i16;
typedef string str;
typedef pair<i64, i64> p64;
typedef vec<i64> vi64;
typedef vec<i32> vi32;
typedef vec<vi64> vv;
typedef vec<p64> vp64;
typedef vec<str> vstr;

/*
ID: Riana Moga (rianamo1)
TASK: namenum
LANG: C++
*/

ifstream fin("dict.txt");

set<str> a = {};
set<str> res = {};
map<i64, vec<char>> m = {{2, {'A', 'B', 'C'}}, {3, {'D', 'E', 'F'}},
                         {4, {'G', 'H', 'I'}}, {5, {'J', 'K', 'L'}},
                         {6, {'M', 'N', 'O'}}, {7, {'P', 'R', 'S'}},
                         {8, {'T', 'U', 'V'}}, {9, {'W', 'X', 'Y'}}};

void cn() {
  string c;
  while (fin >> c) {
    a.insert(c);
  }
}

str s;

void slv(str n) {
  if (n.empty() and a.count(s)) {
    res.insert(s);
    return;
  } else {
    i32 d = n[0] - '0';
    for (char c : m[d]) {
      s += c;
      slv(n.substr(1));
      s.pop_back();
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin("namenum.in");
  ofstream cout("namenum.out");

  str n;
  cin >> n;

  cn();

  slv(n);
  if (res.empty()) {
    cout << "NONE" << endl;
  } else {
    for (str r : res) {
      cout << r << endl;
    }
  }

  return 0;
}