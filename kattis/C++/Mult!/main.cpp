#include <iostream>

using namespace std;

int main()
{
    int n, a;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    a = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] % a == 0){
            cout << arr[i] << endl;
            a = arr[i + 1];
            i += 1;
        }
    }
    return 0;
}
