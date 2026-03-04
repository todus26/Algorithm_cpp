// 3273번 두 수의 합
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, x;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cin >> x;
    sort(arr, arr+n);
    int cnt = 0;
    int left = 0, right = n-1;
    while(left < right){
        if(arr[left] + arr[right] == x){
            cnt++;
            left++;
            right--;
        }else if(arr[left] + arr[right] < x){
            left++;
        }else{
            right--;
        }
    }
    cout << cnt << '\n';
}