#include <iostream>

using namespace std;

int main()
{
    int n, h1, v1, r1, r2, r3, r4;
    cin >> n >> h1 >> v1;
    int h2 = n - h1;
    int v2 = n - v1;
    r1 = h1 * v1 * 4;
    r2 = h1 * v2 * 4;
    r3 = h2 * v1 * 4;
    r4 = h2 * v2 * 4;
    if(r1 >= r2 && r1 >= r3 && r1 >= r4){
        cout << r1;
    }
    else if(r2 >= r1 && r2 >= r3 && r2 >= r4){
        cout << r2;
    }
    else if(r3 >= r1 && r3 >= r2 && r3 >= r4){
        cout << r3;
    }
    else if(r4 >= r1 && r4 >= r2 && r4 >= r3){
        cout << r4;
    }
    return 0;
}
