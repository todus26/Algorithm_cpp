// 2164번 카드2
#include <iostream>
#include <queue>
using namespace std;

int N;
queue<int> q;

int main(void){
    cin >> N;
    for(int i = 1; i <= N; ++i) q.push(i);
    while(q.size() != 1){
        q.pop();
        int tmp = q.front();
        q.push(tmp);
        q.pop();
    }
    cout << q.front();
}