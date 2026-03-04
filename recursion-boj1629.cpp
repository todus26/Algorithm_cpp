#include <iostream>
using namespace std;

long long A, B, C;

long long power(long long a, long long b, long long c) {
    if (b == 0) return 1;
    
    long long half = power(a, b / 2, c);
    half = (half * half) % c;
    
    // b가 홀수인 경우
    if (b % 2 == 1) {
        half = (half * a) % c;
    }
    
    return half;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> A >> B >> C;
    
    long long result = power(A, B, C);
    cout << result << "\n";
    
    return 0;
}