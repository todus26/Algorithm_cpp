#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    
    int count = 0;
    int target;
    
    // n개의 정수를 입력받으면서 임시로 저장
    int* numbers = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    
    // 찾을 정수 v 입력
    cin >> target;
    
    // target과 같은 수의 개수 세기
    for (int i = 0; i < n; i++) {
        if (numbers[i] == target) {
            count++;
        }
    }
    
    cout << count << endl;
    
    delete[] numbers;
    return 0;
}