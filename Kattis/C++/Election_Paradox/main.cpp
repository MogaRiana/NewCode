#include <iostream>
#include<algorithm>

using namespace std;

int main()
{
    int n, a = 0;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    reverse(arr, arr + n);
    for (int i = 0; i < n; i++) {
        if(i < n / 2){
            a += arr[i];
        }
        else{
            a += arr[i] / 2;
        }
    }
    cout << a << endl;
    return 0;
}
