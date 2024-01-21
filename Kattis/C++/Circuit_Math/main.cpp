#include <algorithm>
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

const vector<char> alph = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
                           'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
                           'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

map<char, bool> m = {{'A', false}, {'B', false}, {'C', false}, {'D', false},
                     {'E', false}, {'F', false}, {'G', false}, {'H', false},
                     {'I', false}, {'J', false}, {'K', false}, {'L', false},
                     {'M', false}, {'N', false}, {'O', false}, {'P', false},
                     {'Q', false}, {'R', false}, {'S', false}, {'T', false},
                     {'U', false}, {'V', false}, {'W', false}, {'X', false},
                     {'Y', false}, {'Z', false}};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 n;
  cin >> n;

  i64 ii = 0;
  for (i64 i = 0; i < n; i++) {
    char c;
    cin >> c;
    m[alph[ii++]] = (c == 'T') ? true : false;
  }

  vector<bool> st;
  str s;
  cin.ignore();
  getline(cin, s);

  for (i64 i = 0; i < s.size(); i += 2) {
    char c = s[i];
    if (c != '*' and c != '-' and c != '+') {
      st.push_back(m[c]);
    } else {
      if (c == '+' or c == '*') {
        bool b = (c == '+') ? st[st.size() - 1] or st[st.size() - 2]
                            : st[st.size() - 1] and st[st.size() - 2];
        st.pop_back();
        st.pop_back();
        st.push_back(b);
      } else if (c == '-') {
        st.back() = !st.back();
      }
    }
  }

  if (st.back()) {
    cout << "T" << endl;
  } else {
    cout << "F" << endl;
  }

  return 0;
}