#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
// 100�����̹Ƿ� ���ڰ���� �Ұ��� !!

bool cmp(string s1, string s2) {
	if (s1.size() == s2.size()) return s1 < s2; // ����� ���ٸ� �� ū ���ڿ��� �ڷ�
	else return s1.size() < s2.size(); // ����� �� ū ������� ����
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
			if (s[i]<65) { // ���ڶ�� 
				prev += s[i];
			}
			else { //���ڶ��
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