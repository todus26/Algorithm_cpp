//1011번 - Fly me to the Alpha Centauri
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        long long x, y;
        cin >> x >> y;
        
        long long distance = y - x;
        long long n = (long long)sqrt(distance);
        
        if (n * n == distance) {
            cout << 2 * n - 1 << '\n';
        } else if (distance <= n * n + n) {
            cout << 2 * n << '\n';
        } else {
            cout << 2 * n + 1 << '\n';
        }
    }
    
    return 0;
}