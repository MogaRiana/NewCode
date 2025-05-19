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

i64 n, m;
vi64 a(n + 1), b(n + 1);
vp64 aa(n + 1, {0, 0}), bb(n + 1, {0, 0});

i64 ver(p64 interv, i64 start, i64 pos, i64 i) {
  // 72p
  if ((start - pos < interv.ft or start - pos > interv.sd) and
      (start + pos < interv.ft or start + pos > interv.sd)) {
    if (aa[i].ft != a[i] and bb[i].ft != b[i]) { // ambele sunt umbrite
      if (aa[i + 1].ft + bb[i + 1].ft > m and
          i + 1 <= n) { // umbrele se intersecteaza
        return min(aa[i].sd, bb[i].sd);
      } else { // umbrele nu se intersecteaza
        return max(aa[i].sd, bb[i].sd);
      }
    } else if (aa[i].ft == a[i] and bb[i].ft == b[i]) { // niciuna nu e umbrita
      return i;
    } else if (aa[i].ft != a[i]) { // doar cea de sus e umbrita
      return aa[i].sd;
    } else if (bb[i].ft != b[i]) { // doar cea de jos e umbrita
      return bb[i].sd;
    }

    // 76p
    // if (aa[i].ft != a[i]) {
    //   posres = aa[i].sd + 1;
    // } else {
    //   return bb[i].sd + 1;
    // }
  }

  return -1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"dashgame.in"};
  ofstream cout{"dashgame.out"};

  cin >> n >> m;

  a.resize(n + 1);
  aa.resize(n + 1);
  b.resize(n + 1);
  bb.resize(n + 1);

  for (i64 i = 1; i <= n; i++) {
    cin >> a[i];
    aa[i] = {a[i], i};
  }
  for (i64 i = 1; i <= n; i++) {
    cin >> b[i];
    bb[i] = {b[i], i};

    if (b[i] + a[i] >= m) {
      cout << "NU" << endl << i << endl;
      return 0;
    }
  }

  for (i64 i = n - 1; i > 0; i--) {
    if (aa[i + 1].ft - 1 > aa[i].ft) {
      aa[i] = {aa[i + 1].ft - 1, aa[i + 1].sd};
    }
  }
  for (i64 i = n - 1; i > 0; i--) {
    if (bb[i + 1].ft - 1 > bb[i].ft) {
      bb[i] = {bb[i + 1].ft - 1, bb[i + 1].sd};
    }
  }

  i64 res = -1;
  bool found = false;

  bool ok = false;
  i64 minres = 0;
  i64 pos = 1, start = m / 2 + 1;
  for (i64 i = 2; i <= n; i++) {
    p64 interv = {bb[i].ft + 1, m - aa[i].ft};
    if (ok) {
      interv = {b[i] + 1, m - a[i]};
    }

    if ((start - pos < interv.ft or start - pos > interv.sd) and
        (start + pos < interv.ft or start + pos > interv.sd)) {
      if (aa[i].ft == a[i] and bb[i].ft == b[i]) {
        found = true;
        res = i;
        break;
      }

      if (!ok) {
        ok = true;
        interv = {b[i] + 1, m - a[i]};
      } else {
        found = true;
        res = i;
        break;
      }
    }

    if (start + pos < interv.ft or start + pos > interv.sd) {
      pos *= -1;
      minres++;
    }
    start += pos;
  }

  ok = false;
  i64 maxres = 0;
  pos = 1, start = m / 2 + 1;
  for (i64 i = 2; i <= n; i++) {
    p64 interv = {bb[i].ft + 1, m - aa[i].ft};
    if (ok) {
      interv = {b[i] + 1, m - a[i]};
    }

    if ((start - pos < interv.ft or start - pos > interv.sd) and
        (start + pos < interv.ft or start + pos > interv.sd)) {
      if (aa[i].ft == a[i] and bb[i].ft == b[i]) {
        found = true;
        res = max(res, i);
        break;
      }

      if (!ok) {
        ok = true;
        interv = {b[i] + 1, m - a[i]};
      } else {
        found = true;
        res = max(res, i);
        break;
      }
    }

    if (start - pos >= interv.ft and start - pos <= interv.sd) {
      pos *= -1;
      maxres++;
    }
    start += pos;
  }

  if (found) {
    cout << "NU" << endl << res << endl;
    return 0;
  }

  cout << "DA" << endl;
  cout << minres << " " << maxres << endl;

  return 0;
}