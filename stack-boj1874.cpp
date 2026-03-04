// 1874번 스택 수열
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
stack<int> st;
vector<char> v;

int main() {
	int n, cnt=1;
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		while (cnt <= x) {
			v.push_back('+');
			st.push(cnt);
			cnt++;
		}

		if(x == st.top()) {
			st.pop();
			v.push_back('-');
		}
		else {
			cout << "NO";
			return 0;
		}
	}
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}
}