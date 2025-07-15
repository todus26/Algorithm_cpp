// 2752번 세 수 정렬
#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a > b) {
        if (a > c) {
            if (b > c) {
                cout << c << ' ' << b << ' ' << a << '\n';
            } else {
                cout << b << ' ' << c << ' ' << a << '\n';
            }
        } else {
            cout << b << ' ' << a << ' ' << c << '\n';
        }
    } else {
        if (b > c) {
            if (a > c) {
                cout << c << ' ' << a << ' ' << b << '\n';
            } else {
                cout << a << ' ' << c << ' ' << b << '\n';
            }
        } else {
            cout << a << ' ' << b << ' ' << c << '\n';
        }
    }
    
    // int arr[4];
    // for(int i=0;i<3;i++){
    //     cin>>arr[i];
    // }
    // sort(arr, arr+3);
    // for(int i=0;i<3;i++){
    //     cout<<arr[i]<<" ";
    // }
}