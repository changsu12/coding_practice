#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
// 100글자이므로 숫자계산이 불가능 !!

bool cmp(string s1, string s2) {
	if (s1.size() == s2.size()) return s1 < s2; // 사이즈가 같다면 더 큰 문자열이 뒤로
	else return s1.size() < s2.size(); // 사이즈가 더 큰 순서대로 진행
}

int main() {
	int t;
	cin >> t;
	vector<string> in;
	while (t--) {
		string s;
		string prev = "";
		cin >> s;
		for (int i = 0; i < s.length(); i++) {
			if (s[i]<65) { // 숫자라면 
				prev += s[i];
			}
			else { //문자라면
				if (!prev.empty()) {
					while (prev.size() > 1 && prev.front() == '0') {
						prev.erase(prev.begin());
					}
					in.push_back(prev);
					prev = "";  
				}
			}
			
		}
		if (!prev.empty()) {
			while (prev.size() > 1 && prev.front() == '0') {
				prev.erase(prev.begin());
			}
			in.push_back(prev);
		}
		
		
	}
	sort(in.begin(), in.end(),cmp);
	for (string ret : in) {
		cout << ret << endl;
	}
	return 0;
}