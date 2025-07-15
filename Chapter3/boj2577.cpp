// 2577번 숫자의 개수
#include <iostream>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    int result = a * b * c;

    int arr[10] = {0, };
    while(result > 0){
        arr[result % 10]++;
        result /= 10;
    }
    for(int i=0; i<10; i++){
        cout << arr[i] << '\n';
    }
}