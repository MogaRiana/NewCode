#include <iostream>

using namespace std;

int main()
{
    int n, s = 0;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int d = arr[0];
    for(int i = 0; i < n; i++){
        if(arr[i] < d){
            d = arr[i];
        }
    }
    for(int i = 0; i < n; i++){
        if(arr[i] != d){
            s++;
        }
        else{
            break;
        }
    }
    cout << s;
    return 0;
}
