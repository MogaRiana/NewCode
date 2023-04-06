#include <bits/stdc++.h>

using namespace std;

int main() {
  unordered_map<char, int> um = {
      {'a', 1}, {'b', 2}, {'c', 3}, {'d', 4}, {'e', 5}};

  auto it = um.find('f');

  if (it == um.end()) {
    cout << "Nu exista" << endl;
  } else {
    cout << "Iterator points to " << it->first << " = " << it->second << endl;
  }

  return 0;
}