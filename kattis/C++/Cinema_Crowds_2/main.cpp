#include <iostream>

using namespace std;

int main()
{
    int n, m, s = 0, p = 0, a = 0;
    cin >> n >> m;
    int g[m];
    for(int i = 0; i < m; i++) {
        cin >> g[i];
    }
    for(int i = 0; i < m; i++) {
        a = g[i] + s;
        if(a <= n) {
            s+= g[i];
        }
        else {
            p++;
        }
        if(p == 1) {
            cout << m - i << endl;
            return 0;
        }

    }
    return 0;
}
