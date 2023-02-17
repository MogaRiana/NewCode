#include <iostream>

using namespace std;

int main()
{
    int t, s;
    cin >> t;
    int N[t], arr[t];
    for(int i = 0; i < t; i++){
        cin >> N[i];
    }
    for(int i = 0; i < t; i++){
        s = 1;
        for(int j = 1; j <= N[i]; j++){
            s *= j;
        }
        arr[i] = s;
    }
    for(int i = 0; i < t; i++){
        arr[i] %= 10;
        cout << arr[i] << endl;
    }
    return 0;
}
