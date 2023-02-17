#include <iostream>

using namespace std;

int main()
{
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    int n;
    cin >> n;
    if(n <= e){
        cout << "F" << endl;
    }
    else if(n > e && n <= d){
        cout << "D" << endl;
    }
    else if(n > d && n <= c){
        cout << "C" << endl;
    }
    else if(n > c && n <= b){
        cout << "B" << endl;
    }
    else{
        cout << "A" << endl;
    }
    return 0;
}
