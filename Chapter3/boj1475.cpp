// 1475번 방 번호
#include <iostream>
#include <string>
using namespace std;

int main(){
    string room;
    cin >> room;
    int arr[10] = {0, };
    for(int i=0; i<room.length(); i++){
        arr[room[i] - '0']++;
    }
    int six_nine = (arr[6] + arr[9] + 1) / 2;
    arr[6] = arr[9] = six_nine;
    int max = 0;
    for(int i=0; i<10; i++){
        if(arr[i] > max) max = arr[i];
    }
    cout << max << '\n';
}