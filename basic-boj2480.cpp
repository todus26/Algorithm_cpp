// 2480번 주사위 세 개
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a+3);
    if(a[0] == a[2]) cout << 10000 + a[0]*1000; // 세 수가 동일
    else if(a[0] == a[1] || a[1] == a[2]) cout << 1000 + a[1]*100; // 두 수가 동일
    else cout << a[2]*100;
}