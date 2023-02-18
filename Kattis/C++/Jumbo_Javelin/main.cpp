#include <iostream>

using namespace std;

int main()
{
    int n, b;
    int a=1;
    cin >> n;
    for(int i=0; i < n; i+=1){
        cin >> b;
        a = (a + b) - 1;
    }
    cout << a;
    return 0;
}
