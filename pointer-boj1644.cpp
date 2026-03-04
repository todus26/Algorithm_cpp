//1644번 - 소수의 연속합
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPrime[4000001];

void sieve(int n) {
    fill(isPrime, isPrime + n + 1, true);
    isPrime[0] = isPrime[1] = false;
    
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    sieve(n);
    
    vector<int> primes;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
    
    if (primes.empty()) {
        cout << 0 << '\n';
        return 0;
    }
    
    int left = 0, right = 0;
    int sum = primes[0];
    int answer = 0;
    
    while (left <= right && right < primes.size()) {
        if (sum == n) {
            answer++;
            sum -= primes[left];
            left++;
        } else if (sum < n) {
            right++;
            if (right < primes.size()) {
                sum += primes[right];
            }
        } else {
            sum -= primes[left];
            left++;
        }
    }
    
    cout << answer << '\n';
    
    return 0;
}