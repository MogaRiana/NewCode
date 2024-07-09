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
TASK: palsquare
LANG: C++
*/

bool pal(str &n) {
  str temp = n;
  reverse(temp.begin(), temp.end());

  return temp == n;
}

char reVal(int num) {
  if (num >= 0 && num <= 9)
    return (char)(num + '0');
  else
    return (char)(num - 10 + 'A');
}

string fromDeci(string &res, int base, int n) {
  int index = 0;

  while (n > 0) {
    res.push_back(reVal(n % base));
    n /= base;
    index++;
  }

  reverse(res.begin(), res.end());

  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin("palsquare.in");
  ofstream cout("palsquare.out");

  i64 b;
  cin >> b;

  for (i64 i = 1; i <= 300; i++) {
    str d = "", p = "";
    d = fromDeci(d, b, i);
    p = fromDeci(p, b, i * i);

    if (pal(p)) {
      cout << d << " " << p << endl;
    }
  }

  return 0;
}