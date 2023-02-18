#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, a = 1;
    while(cin >> n) {
        int x[n];
        for(int i = 0; i < n; i ++) {
            cin >> x[i];
        }
        sort(x, x + n);
        int nrmax = x[n - 1], nrmin = x[0];
        int range = nrmax - nrmin;
        cout << "Case " << a << ": " << nrmin << " " << nrmax << " " << range << endl;
        a++;
    }
    return 0;
}
