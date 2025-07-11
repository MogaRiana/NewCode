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

int N = 4;
int f[11];

void print() {
  // ofstream cout{"submultimi.out"};
  for (int i = 1; i <= N; i++) {
    if (f[i] == 1) {
      cout << i << " ";
    }
  }
  cout << "\n";
}

void bkt(int p) {
  if (p == N + 1) {
    return;
  }

  f[p] = 1;
  print();
  bkt(p + 1);
  f[p] = 0;
  bkt(p + 1);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin{"submultimi.in"};
  // cin >> N;
  bkt(1);

  return 0;
}