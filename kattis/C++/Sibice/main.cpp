#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int w, h;
    cin >> w >> h;
    while (n>0){
        int t;
        cin >> t;
        if (t*t <= h*h + w*w){
            cout << "DA" << endl;
        }
        else {
            cout << "NE" << endl;
        }
        n-=1;
    }
    return 0;
}
