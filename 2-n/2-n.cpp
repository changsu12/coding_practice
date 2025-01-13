#include <iostream>
#include <queue>
using namespace std;

//이거는 큐를 놓고 풀어야 할 것 같은데 
int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		queue<string> a;
		bool flag = false; //기본
		cin >> s;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(') {
				a.push("(");
			}
			else {
				if (a.empty()) {
					flag = true;  //잘못되었다는 뜻
				}
				else {
					a.pop();
				}
			}
		}
		if (!a.empty()) {
			flag = true;
		}
		if (flag == true) cout << "NO"<<"\n";
		else cout << "YES"<<"\n";
	}
}