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
TASK: barn1
LANG: C++
*/

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin("barn1.in");
  ofstream cout("barn1.out");

  i64 m, s, c;
  cin >> m >> s >> c;

  vi64 pos(c);
  for (i64 i = 0; i < c; i++) {
    cin >> pos[i];
  }

  srt(pos);

  if (m >= c) {
    cout << c << endl;
    return 0;
  } else if (m == 1) {
    cout << pos[c - 1] - pos[0] + 1 << endl;
    return 0;
  }

  vec<pair<i64, p64>> dif;
  for (i64 i = 0; i < c - 1; i++) {
    dif.push_back({pos[i + 1] - pos[i], {pos[i], pos[i + 1]}});
  }

  vec<pair<i64, p64>> rr;
  i64 cnt = -1;
  for (i64 x = 0; x < sz(dif); x++) {
    if (dif[x].ft <= cnt) {
      rr.push_back(dif[x - 1]);
    }
    cnt = dif[x].ft;
  }

  if (dif[sz(dif) - 1].ft <= cnt) {
    rr.push_back(dif[sz(dif) - 1]);
  }

  rsrt(rr);
  vp64 res;
  for (i64 i = 0; i < sz(rr) && i < m - 1; i++) {
    res.push_back(rr[i].sd);
  }

  srt(res);
  i64 sum = 0;

  for (i64 i = 0; i < sz(res); i++) {
    if (i == 0) {
      sum += res[i].ft - pos[0] + 1;
    } else {
      i64 n = res[i].ft - res[i - 1].sd + 1;
      sum += n;
    }
  }

  sum += pos[c - 1] - res[sz(res) - 1].sd + 1;

  cout << sum << endl;

  return 0;
}

/*
20 200 80
65
178
64
70
18
32
88
90
98
20
152
31
118
117
127
81
175
73
136
161
165
63
130
133
190
10
4
138
200
43
189
37
86
182
145
110
67
126
114
153
99
25
155
119
176
55
48
197
62
147
125
60
12
23
112
96
27
122
35
50
36
49
149
108
100
188
77
191
6
121
166
132
82
95
150
89
22
40
128
56

*/