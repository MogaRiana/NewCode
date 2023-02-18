#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int a = 1, b;
    for(int i = 1; a == 1; i++) {
        int s = i;
        b = i;
        for(int j = 0; j < n; j++) {
            s += arr[j];
            if(s < 0) {
                a = 1;
                break;
            }
            else{
                a = 0;
            }
        }
    }
    cout << b;
    return 0;
}
