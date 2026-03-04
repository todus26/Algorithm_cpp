//9375번 - 패션왕 신해빈
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        int n;
        cin >> n;
        
        map<string, int> clothes;
        
        for (int i = 0; i < n; i++) {
            string name, type;
            cin >> name >> type;
            clothes[type]++;
        }
        
        int result = 1;
        for (auto& item : clothes) {
            result *= (item.second + 1);
        }
        
        cout << result - 1 << "\n";
    }
    
    return 0;
}