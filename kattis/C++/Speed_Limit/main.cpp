#include <iostream>

using namespace std;

int main()
{
    int n, m = 0;
    while(cin >> n){
        if(n == -1){
            break;
        }
        int v[n], t[n], a[n];
        for(int i = 0; i < n; i++){
            cin >> v[i] >> t[i];
        }
        a[0] = t[0];
        for(int i = 1; i < n; i++){
            a[i] = t[i] - t[i-1];
        }
        for(int i = 0; i < n; i++){
            m += a[i] * v[i];
        }
        cout << m << " miles" << endl;
        m = 0;
    }
    return 0;
}
