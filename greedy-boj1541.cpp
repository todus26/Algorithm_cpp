// 1541번 - 잃어버린 괄호
#include <iostream>
#include <string>
using namespace std;

int main() {
    string expression;
    cin >> expression;
    
    int result = 0;
    string num = "";
    bool minusFound = false;
    
    for (int i = 0; i <= expression.length(); i++) {
        // 마지막 문자이거나 연산자를 만났을 때
        if (i == expression.length() || expression[i] == '+' || expression[i] == '-') {
            if (num != "") {
                int value = stoi(num);
                
                if (minusFound) {
                    // 한 번이라도 마이너스를 만난 후에는 모든 수를 빼기
                    result -= value;
                } else {
                    // 마이너스를 만나기 전까지는 더하기
                    result += value;
                }
                
                num = "";
            }
            
            // 마이너스를 처음 만났을 때
            if (i < expression.length() && expression[i] == '-') {
                minusFound = true;
            }
        } else {
            // 숫자 부분을 문자열로 저장
            num += expression[i];
        }
    }
    
    cout << result << endl;
    
    return 0;
}