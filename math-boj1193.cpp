//1193번 - 분수찾기
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int X;
    cin >> X;
    
    int line = 1;
    int sum = 0;
    
    while (sum + line < X) {
        sum += line;
        line++;
    }
    
    int pos = X - sum;
    
    int numerator, denominator;
    
    if (line % 2 == 1) {
        numerator = line - pos + 1;
        denominator = pos;
    } else {
        numerator = pos;
        denominator = line - pos + 1;
    }
    
    cout << numerator << "/" << denominator << '\n';
    
    return 0;
}