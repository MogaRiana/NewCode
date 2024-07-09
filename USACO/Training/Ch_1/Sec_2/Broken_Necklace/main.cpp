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
TASK: beads
LANG: C++
*/

vec<pair<char, i64>> f(str &s) {
  vec<pair<char, i64>> ans;

  for (i64 i = 0; i < sz(s); i++) {
    if (ans.empty() or (!ans.empty() and s[i] != ans.back().ft)) {
      ans.push_back({s[i], 0});
    }
    ans.back().sd++;
  }

  return ans;
}

bool ver(vec<pair<char, i64>> &f) {
  bool ok = false;
  i64 n = sz(f);

  for (i64 i = 0; i < sz(f); i++) {
    if (f[i].ft == 'w') {
      i64 i1 = i - 1, i2 = i + 1;

      if (i == 0) {
        i1 = n - 1;
      } else if (i == n - 1) {
        i2 = 0;
      }

      if (f[i1].ft != f[i2].ft and f[i1].sd != f[i2].sd) {
        ok = true;
        break;
      }
    }
  }

  return ok;
}

void rec(vec<pair<char, i64>> &f) {
  i64 n = sz(f);
  vec<pair<char, i64>> ans;

  for (i64 i = 0; i < n; i++) {
    if (f[i].ft == 'w' or (f[i + 1].ft == 'w' and i < n)) {
      if (f[i + 1].ft == 'w') {
        i++;
      }
      i64 i1 = i - 1, i2 = i + 1;

      if (i == 0) {
        i1 = n - 1;
      } else if (i == n - 1) {
        i2 = 0;
      }

      if (f[i1].ft == f[i2].ft) {
        i64 sum = f[i1].sd + f[i].sd + f[i2].sd;

        for (i64 j = i2 + 1; j < n; j++) {
          if (f[j].ft != 'w' and f[j].ft != f[i1].ft) {
            break;
          }

          sum += f[j].sd;
          i = j;
        }

        ans.push_back({f[i1].ft, sum});
      } else {
        if (f[i1].sd < f[i2].sd) {
          i64 sum = f[i].sd + f[i2].sd;
          ans.push_back(f[i1]);
          ans.push_back({f[i2].ft, sum});
        } else if (f[i1].sd > f[i2].sd) {
          i64 sum = f[i1].sd + f[i].sd;
          ans.push_back({f[i1].ft, sum});
        } else {
          ans.push_back(f[i - 1]);
          ans.push_back(f[i]);
        }
      }

      i++;

      if (i1 == n - 1) {
        f.pop_back();
        n--;
      }
    } else {
      ans.push_back(f[i]);
    }
  }

  f = ans;
  if (ver(f)) {
    rec(f);
  }

  return;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin("beads.in");
  // ofstream cout("beads.out");

  i64 n;
  cin >> n;

  str s;
  cin >> s;

  vec<pair<char, i64>> freq = f(s);

  if (sz(freq) == 1) {
    cout << freq[0].sd << endl;
    return 0;
  }

  // if (ver(freq)) {
  rec(freq);
  //}

  if (freq[0].ft == freq[sz(freq) - 1].ft) {
    freq[0].sd += freq[sz(freq) - 1].sd;
    freq.pop_back();
  }

  i64 res = -1;
  for (i64 i = 0; i < sz(freq); i++) {
    i64 sum = freq[i].sd;

    if (i == sz(freq) - 1) {
      sum += freq[0].sd;

      if (sz(freq) > 2 and freq[0].ft == 'w') {
        sum += freq[1].sd;
      } else if (sz(freq) > 2 and freq[1].ft == 'w') {
        sum += freq[1].sd;
      }
    } else if (i == sz(freq) - 1) {
      if (sz(freq) > 2 and freq[0].ft == 'w') {
        sum += freq[1].sd;
      }
    } else {
      if (freq[i + 1].ft == 'w' or freq[i + 2].ft == 'w') {
        sum += freq[i + 1].sd;
        sum += freq[i + 2].sd;
      } else {
        sum += freq[i + 1].sd;
      }
    }

    res = max(res, sum);
  }

  cout << res << endl;

  return 0;
}