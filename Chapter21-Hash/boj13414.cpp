//13414번 - 수강신청
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int K, L;
    cin >> K >> L;
    
    unordered_map<string, int> last_position;
    vector<string> students(L);
    
    for (int i = 0; i < L; i++) {
        cin >> students[i];
        last_position[students[i]] = i;
    }
    
    vector<pair<int, string>> valid_students;
    unordered_map<string, bool> added;
    
    for (int i = 0; i < L; i++) {
        if (last_position[students[i]] == i && !added[students[i]]) {
            valid_students.push_back({i, students[i]});
            added[students[i]] = true;
        }
    }
    
    int count = min(K, (int)valid_students.size());
    for (int i = 0; i < count; i++) {
        cout << valid_students[i].second << "\n";
    }
    
    return 0;
}