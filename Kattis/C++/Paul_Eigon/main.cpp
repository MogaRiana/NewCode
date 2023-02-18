#include <iostream>

using namespace std;

int main()
{
    int n, p, q, d;
    cin >> n >> p >> q;
    d = p + q;
    if((d / n) % 2 == 0){
        cout << "paul" << endl;
    }
    else{
        cout << "opponent" << endl;
    }
    return 0;
}
