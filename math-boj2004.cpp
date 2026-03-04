//2004번 - 조합 0의 개수
#include <iostream>
#include <algorithm>
using namespace std;

long long countFactor(long long n, long long factor) {
    long long count = 0;
    for (long long i = factor; i <= n; i *= factor) {
        count += n / i;
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n, m;
    cin >> n >> m;
    
    long long count2 = countFactor(n, 2) - countFactor(m, 2) - countFactor(n - m, 2);
    long long count5 = countFactor(n, 5) - countFactor(m, 5) - countFactor(n - m, 5);
    
    cout << min(count2, count5) << '\n';
    
    return 0;
}