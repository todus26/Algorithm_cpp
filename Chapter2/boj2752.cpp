// 2752번 세 수 정렬
#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[4];
    for(int i=0;i<3;i++){
        cin>>arr[i];
    }
    sort(arr, arr+3);
    for(int i=0;i<3;i++){
        cout<<arr[i]<<" ";
    }
}