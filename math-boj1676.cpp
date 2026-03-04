//1676번 - 팩토리얼 0의 개수
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    int count = 0;
    for (int i = 5; i <= N; i *= 5) {
        count += N / i;
    }
    
    cout << count << '\n';
    
    return 0;
}