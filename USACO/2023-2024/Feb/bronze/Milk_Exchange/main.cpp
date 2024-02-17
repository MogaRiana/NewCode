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
typedef vector<str> vstr;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 n, m;
  cin >> n >> m;

  str s;
  cin >> s; 
  vi64 v(n);

  i64 sum = 0;
  for (i64 i = 0; i < n; i++) {
    cin >> v[i];
    sum += v[i];
  }

  for(i64 i = 0; i < n; i++){
    if(i == 0){
      if(s[i] == 'R' and s[i + 1] == 'L'){
        if(s[n - 1] == 'R'){
          sum -= min(m, v[n - 1]);
        }
      }else if(s[n - 1] == 'R' and s[i] == 'L'){
        if(s[i + 1] == 'L'){
          sum -= min(m, v[i + 1]);
        }
      }
    }else if(i == n - 1){
      if(s[i] == 'R' and s[0] == 'L'){
        if(s[i - 1] == 'R'){
          sum -= min(m, v[i - 1]);
        }
      }else if(s[i - 1] == 'R' and s[i] == 'L'){
        if(s[0] == 'L'){
          sum -= min(m, v[0]);
        }
      }
    }else{
      if(s[i] == 'R' and s[i + 1] == 'L'){
        if(s[i - 1] == 'R'){
          sum -= min(m, v[i - 1]);
        }
      }else if(s[i - 1] == 'R' and s[i] == 'L'){
        if(s[i + 1] == 'L'){
          sum -= min(m, v[i + 1]);
        }
      }
    }
  }
  cout << sum << endl;

  return 0;
} 