#include <iostream>
#include <algorithm>
using namespace std;

int L, C;
char arr[15];
char pw[15];
int cnt = 0;

bool check(int len) {
    int ja = 0, mo = 0;
    string moeum = "aeiou";
    
    for(int i = 0; i < len; i++) {
        if(moeum.find(pw[i]) != string::npos) mo++;
        else ja++;
    }
    
    // 모음 1개 이상, 자음 2개 이상
    return mo >= 1 && ja >= 2;
}

void solve(int idx, int depth) {
    if(depth == L) {
        if(check(L)) {
            for(int i = 0; i < L; i++) cout << pw[i];
            cout << '\n';
        }
        return;
    }
    
    for(int i = idx; i < C; i++) {
        pw[depth] = arr[i];
        solve(i + 1, depth + 1);
    }
}

int main() {
    cin >> L >> C;
    
    for(int i = 0; i < C; i++) cin >> arr[i];
    
    // 알파벳 순 출력을 위해 정렬
    sort(arr, arr + C);
    
    solve(0, 0);
    
    return 0;
}