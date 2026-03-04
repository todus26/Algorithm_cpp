// 1181번 - 단어 정렬
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

bool compare(const string& a, const string& b) {
    // 1. 길이가 짧은 것부터
    if (a.length() != b.length()) {
        return a.length() < b.length();
    }
    // 2. 길이가 같으면 사전 순으로
    return a < b;
}

int main() {
    int N;
    cin >> N;
    
    set<string> uniqueWords;  // 중복 제거를 위한 set
    
    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        uniqueWords.insert(word);
    }
    
    // set의 원소들을 vector로 복사
    vector<string> words(uniqueWords.begin(), uniqueWords.end());
    
    // 정렬
    sort(words.begin(), words.end(), compare);
    
    // 출력
    for (const string& word : words) {
        cout << word << '\n';
    }
    
    return 0;
}