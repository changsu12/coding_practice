#include <iostream>
#include <queue>
using namespace std;

//�̰Ŵ� ť�� ���� Ǯ��� �� �� ������ 
int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		queue<string> a;
		bool flag = false; //�⺻
		cin >> s;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(') {
				a.push("(");
			}
			else {
				if (a.empty()) {
					flag = true;  //�߸��Ǿ��ٴ� ��
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