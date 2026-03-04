// 2445번 별 찍기 - 8
#include <iostream>
using namespace std;

int main(void){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=0; j<i; j++){
            cout << '*';
        }
        for(int j=0; j<2*(n-i); j++){
            cout << ' ';
        }
        for(int j=0; j<i; j++){
            cout << '*';
        }
        cout << '\n';
    }
    for(int i=n-1; i>0; i--){
        for(int j=0; j<i; j++){
            cout << '*';
        }
        for(int j=0; j<2*(n-i); j++){
            cout << ' ';
        }
        for(int j=0; j<i; j++){
            cout << '*';
        }
        cout << '\n';
    }
}