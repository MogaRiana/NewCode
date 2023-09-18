#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  while (cin >> s) {

    vector<int> sum;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'B' or s[i] == 'F' or s[i] == 'P' or s[i] == 'V') {
        sum.push_back(1);
        if (i >= 0 and i < s.size() - 1 and
            (s[i - 1] == s[i] or s[i + 1] == s[i])) {
          sum.push_back(1);
        }
      } else if (s[i] == 'C' or s[i] == 'G' or s[i] == 'J' or s[i] == 'K' or
                 s[i] == 'Q' or s[i] == 'S' or s[i] == 'X' or s[i] == 'Z') {
        sum.push_back(2);
        if (i >= 0 and i <= s.size() - 1 and
            (s[i - 1] == s[i] or s[i + 1] == s[i])) {
          sum.push_back(2);
        }
      } else if (s[i] == 'D' or s[i] == 'T') {
        sum.push_back(3);
        if (i >= 0 and i < s.size() - 1 and
            (s[i - 1] == s[i] or s[i + 1] == s[i])) {
          sum.push_back(3);
        }
      } else if (s[i] == 'L') {
        sum.push_back(4);
        if (i >= 0 and i < s.size() - 1 and
            (s[i - 1] == s[i] or s[i + 1] == s[i])) {
          sum.push_back(4);
        }
      } else if (s[i] == 'M' or s[i] == 'N') {
        sum.push_back(5);
        if (i >= 0 and i < s.size() - 1 and
            (s[i - 1] == s[i] or s[i + 1] == s[i])) {
          sum.push_back(5);
        }
      } else if (s[i] == 'R') {
        sum.push_back(6);
        if (i >= 0 and i < s.size() - 1 and
            (s[i - 1] == s[i] or s[i + 1] == s[i])) {
          sum.push_back(6);
        }
      }
    }

    for (auto i : sum) {
      cout << i;
    }
    cout << endl;
  }

  return 0;
}
