// C++ program to find indices of all
// occurrences of one string in other.
#include <iostream>
using namespace std;
void printIndex(string str, string s) {

  bool flag = false;
  for (int i = 0; i < str.size(); i++) {
    if (str.substr(i, s.size()) == s) {
      cout << i << " ";
      flag = true;
    }
  }

  if (flag == false)
    cout << "NONE";
}
int main() {
  string str1 = "GeeksforGeeks";
  string str2 = "Geeks";
  printIndex(str1, str2);
  return 0;
}
