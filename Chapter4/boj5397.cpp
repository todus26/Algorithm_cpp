// 5397번 키로거
#include <iostream>
#include <list>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){                                 // t가 0이 될 때까지 반복
        string s;
        cin >> s;
        list<char> l;                           // 문자열을 저장하기 위한 리스트
        list<char>::iterator cursor = l.end();  // 커서 위치를 나타내는 이터레이터 초기화
        for(int i=0; i<s.size(); i++){
            if(s[i] == '<'){                    // '<'가 입력되면 커서를 왼쪽으로 이동
                if(cursor != l.begin()){
                    cursor--;
                }
            }else if(s[i] == '>'){              // '>'가 입력되면 커서를 오른쪽으로 이동
                if(cursor != l.end()){
                    cursor++;
                }
            }else if(s[i] == '-'){              // '-'가 입력되면 커서 왼쪽에 있는 문자 삭제
                if(cursor != l.begin()){
                    cursor = l.erase(--cursor);
                }
            }else{                              // 그 외의 문자가 입력되면 커서 위치에 삽입
                l.insert(cursor, s[i]);
            }
        }
        for(auto c : l){
            cout << c;
        }
        cout << '\n';
    }
}