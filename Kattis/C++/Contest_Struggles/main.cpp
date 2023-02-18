#include <iostream>

using namespace std;

int main()
{
    int n, k, d, s;
    cin >> n >> k >> d >> s;
    int total = n * d;
    int a = n - k;
    int total2 = k * s;

    if(total - total2 > 100 * a){
        cout << "impossible";
    }
    else{
        double b = (total - total2) / double(a);
        cout.precision(10);
        if(b >= 0 and b <= 100){
            cout << fixed << b;
        }
        else{
            cout << "impossible";
        }
    }
    return 0;
}
