//1038번 - 감소하는 수
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> nums;

void dfs(long long num, int digit) {
    nums.push_back(num);
    
    for (int i = 0; i < digit; i++) {
        dfs(num * 10 + i, i);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    for (int i = 0; i <= 9; i++) {
        dfs(i, i);
    }
    
    sort(nums.begin(), nums.end());
    
    if (N >= nums.size()) {
        cout << -1 << '\n';
    } else {
        cout << nums[N] << '\n';
    }
    
    return 0;
}