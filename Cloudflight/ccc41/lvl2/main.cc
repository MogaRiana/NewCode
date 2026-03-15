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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ifstream cin{"input.in"};
  ofstream cout{"output.out"};

  int n;
  cin >> n;
  cin.ignore();
  for (int i = 0; i < n; i++) {
    int a, b, m;
    cin >> a >> b >> m;
    cin.ignore();
    vector<string> v(b + 3);
    for (int j = 0; j < b + 3; j++) {
      getline(cin, v[j]);
    }

    if (a < b) {
      for (int i = 1; i <= a; i++) {
        if (v[0][i] == 'S') {
          v[1][i] = 'X';
          if (abs(i - 1) < abs(i - a)) {
            for (int j = i - 1; j >= 2; j--) {
              v[1][j] = 'X';
            }
            for (int j = 2; j < a; j++) {
              v[2][j] = 'X';
            }
            for (int j = b - 1; j >= 2; j -= 3) {
              for (int jj = 2; jj <= a; jj++) {
                v[j][jj] = 'X';
              }
            }
          } else {
            for (int j = i + 1; j < a; j++) {
              v[1][j] = 'X';
            }
            for (int j = 2; j < b; j++) {
              v[j][a - 1] = 'X';
            }
            for (int j = b - 1; j >= 2; j -= 3) {
              for (int jj = a - 1; jj >= 2; jj--) {
                v[j][jj] = 'X';
              }
            }
          }
        }
      }

      for (int i = 0; i < b + 2; i++) {
        for (int j = 0; j < a + 2; j++) {
          cout << v[i][j];
        }

        cout << endl;
      }
      cout << endl;
      continue;
    } else {
      for (int i = 1; i <= a; i++) {
        v[b - 1][i] = 'X';
      }

      for (int i = 1; i <= a; i++) {
        if (v[0][i] == 'S') {
          v[1][i] = 'X';
          if (abs(i - 1) < abs(i - a)) {
            for (int j = i - 1; j >= 2; j--) {
              v[1][j] = 'X';
            }
            for (int j = 2; j < b; j++) {
              v[j][2] = 'X';
            }
            for (int j = 5; j >= 2; j -= 3) {
              for (int jj = b - 1; jj >= 1; jj--) {
                v[jj][j] = 'X';
              }
            }
          } else {
            for (int j = i + 1; j < a; j++) {
              v[1][j] = 'X';
            }
            for (int j = 2; j < b; j++) {
              v[a - 1][j] = 'X';
            }
            for (int j = a - 3; j >= 2; j -= 3) {
              for (int jj = b - 1; jj >= 1; jj--) {
                v[j][jj] = 'X';
              }
            }
          }
        }
      }

      for (int i = 0; i < b + 2; i++) {
        for (int j = 0; j < a + 2; j++) {
          cout << v[i][j];
        }

        cout << endl;
      }
      cout << endl;
      continue;
    }
  }

  return 0;
}