#include <iostream>

using namespace std;

int main()
{
    int h, m;
    cin >> h >> m;
    int hm = h * 60 + m;
    int t = hm - 45;
    if(t < 0){
        t += 24 * 60;
    }
    int h1 = t / 60;
    int m1 = t % 60;
    cout << h1 << " " << m1;
    return 0;
}
