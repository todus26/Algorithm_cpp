// 2562번 최댓값
#include <iostream>
using namespace std;

int main(void){
    int max = 0, idx = 0;
    for(int i=1; i<=9; i++){
        int n;
        cin >> n;
        if(n > max){
            max = n;
            idx = i;
        }
    }
    cout << max << '\n' << idx;
}