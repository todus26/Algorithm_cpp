// 1158번 요세푸스 문제
#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    queue<int> q;
    for(int i=1; i<=n; i++){
        q.push(i);
    }
    cout << '<';
    while(q.size() > 1){   // 큐에 한 개의 원소만 남을 때까지 반복
        for(int i=0; i<k-1; i++){
            q.push(q.front());
            q.pop();
        }
        cout << q.front() << ", ";
        q.pop();
    }
    cout << q.front() << '>';
}