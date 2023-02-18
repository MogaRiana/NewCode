#include <iostream>

using namespace std;
typedef long long i64;

int main()
{
    int n, s = 1;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for(int i = 1; i < n; i++) {
        if(arr[i - 1] < arr[i]){
            s++;
        }
    }
    cout << s;
    return 0;
}
