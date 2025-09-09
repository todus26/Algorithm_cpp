// 21944번 - 문제 추천 시스템 Version 2
#include <iostream>
#include <set>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    set<pair<int, int>> allProblems;
    map<int, set<pair<int, int>>> algoProblems;
    map<int, pair<int, int>> problemInfo;
    
    for (int i = 0; i < N; i++) {
        int P, L, G;
        cin >> P >> L >> G;
        
        allProblems.insert({L, P});
        algoProblems[G].insert({L, P});
        problemInfo[P] = {L, G};
    }
    
    int M;
    cin >> M;
    
    while (M--) {
        string command;
        cin >> command;
        
        if (command == "add") {
            int P, L, G;
            cin >> P >> L >> G;
            
            allProblems.insert({L, P});
            algoProblems[G].insert({L, P});
            problemInfo[P] = {L, G};
        }
        else if (command == "solved") {
            int P;
            cin >> P;
            
            int L = problemInfo[P].first;
            int G = problemInfo[P].second;
            
            allProblems.erase({L, P});
            algoProblems[G].erase({L, P});
            problemInfo.erase(P);
        }
        else if (command == "recommend") {
            int G, x;
            cin >> G >> x;
            
            if (x == 1) {
                cout << algoProblems[G].rbegin()->second << "\n";
            } else {
                cout << algoProblems[G].begin()->second << "\n";
            }
        }
        else if (command == "recommend2") {
            int x;
            cin >> x;
            
            if (x == 1) {
                cout << allProblems.rbegin()->second << "\n";
            } else {
                cout << allProblems.begin()->second << "\n";
            }
        }
        else if (command == "recommend3") {
            int x, L;
            cin >> x >> L;
            
            if (x == 1) {
                auto it = allProblems.lower_bound({L, 0});
                if (it != allProblems.end()) {
                    cout << it->second << "\n";
                } else {
                    cout << -1 << "\n";
                }
            } else {
                auto it = allProblems.lower_bound({L, 0});
                if (it != allProblems.begin()) {
                    --it;
                    cout << it->second << "\n";
                } else {
                    cout << -1 << "\n";
                }
            }
        }
    }
    
    return 0;
}