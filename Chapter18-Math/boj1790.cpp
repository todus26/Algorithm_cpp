//1790번 - 수 이어 쓰기 2
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long N, k;
    cin >> N >> k;
    
    long long length = 0;
    long long digits = 1;
    long long start = 1;
    
    while (start <= N) {
        long long end = min(N, start * 10 - 1);
        long long count = end - start + 1;
        
        if (length + count * digits >= k) {
            long long pos = k - length;
            long long num = start + (pos - 1) / digits;
            long long idx = (pos - 1) % digits;
            
            string str = to_string(num);
            cout << str[idx] << '\n';
            return 0;
        }
        
        length += count * digits;
        digits++;
        start *= 10;
    }
    
    cout << -1 << '\n';
    return 0;
}