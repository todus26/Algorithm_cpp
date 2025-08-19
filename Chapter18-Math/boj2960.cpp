//2960번 - 에라토스테네스의 체
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, K;
    cin >> N >> K;
    
    vector<bool> prime(N + 1, true);
    int count = 0;
    
    for (int i = 2; i <= N; i++) {
        if (prime[i]) {
            for (int j = i; j <= N; j += i) {
                if (prime[j]) {
                    prime[j] = false;
                    count++;
                    if (count == K) {
                        cout << j << '\n';
                        return 0;
                    }
                }
            }
        }
    }
    
    return 0;
}