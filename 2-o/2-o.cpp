#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool vaild(string s) {
	stack<char> a;
	bool check=true;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ')') {
			if (a.size() == 0 || a.top() == '[') return false;
			else a.pop();
		}
		if (s[i] == ']') {
			if (a.size() == 0 || a.top() == '(') return false; 
			else a.pop();
		}
		if (s[i] == '(') a.push('(');
		if (s[i] == '[') a.push('[');

	}
	if (!a.empty()) return false;
	else return true;
}

int main() {
	while (true) {
		string s;
		getline(cin, s);
		if (s == ".") break;
		if (vaild(s)==true) cout << "yes"<<endl;
		else cout << "no"<<endl;
	}

}