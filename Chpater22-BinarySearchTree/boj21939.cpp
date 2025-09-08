// 21939 - 문제 추천 시스템 Version 1
#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    set<pair<int, int>> problems; // (difficulty, problem number)
    unordered_map<int, int> problem_map; // problem number -> difficulty
    
    for (int i = 0; i < N; i++) {
        int P, L;
        cin >> P >> L;
        problems.insert({L, P});
        problem_map[P] = L;
    }
    
    int M;
    cin >> M;
    
    for (int i = 0; i < M; i++) {
        string command;
        cin >> command;
        
        if (command == "add") {
            int P, L;
            cin >> P >> L;
            problems.insert({L, P});
            problem_map[P] = L;
        } else if (command == "solved") {
            int P;
            cin >> P;
            int L = problem_map[P];
            problems.erase({L, P});
            problem_map.erase(P);
        } else if (command == "recommend") {
            int x;
            cin >> x;
            if (x == 1) {
                auto it = prev(problems.end());
                cout << it->second << '\n';
            } else if (x == -1) {
                auto it = problems.begin();
                cout << it->second << '\n';
            }
        }
    }
    
    return 0;
}