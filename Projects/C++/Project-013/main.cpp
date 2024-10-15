#include <fstream>
#include <iostream>

using namespace std;
ifstream fin{"tari.txt"};
ofstream fout("solutii.txt");

int n, m, nc;
int a[100][100];
int x[100];

void citire() {
  fin >> n >> m >> nc;
  for (int i = 0; i < m; i++) {
    int x, y;
    fin >> x >> y;

    a[x][y] = a[y][x] = 1;
  }
}

bool valid(int k) {
  for (int i = 1; i < k; i++) {
    if (a[i][k] == 1 && x[i] == x[k]) {
      return false;
    }
  }
  return true;
}

void print() {
  for (int i = 1; i <= n; i++) {
    fout << x[i] << " ";
  }
  fout << endl;
}

void backtrack(int k) {
  if (k > n) {
    print();
    return;
  }

  for (int i = 1; i <= nc; i++) {
    x[k] = i;
    if (valid(k)) {
      backtrack(k + 1);
    }
  }
}

int main() {

  citire();
  backtrack(1);

  return 0;
}