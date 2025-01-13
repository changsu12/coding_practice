#include <iostream>
#include <string>
using namespace std;

string s;
bool isVowel(int c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
int main() {
	while (true) {
		cin >> s;
		if (s == "end") { break; }
		bool flag = false;
		int lcnt=0, vcnt = 0;
		int prev = -1;
		bool include = false;
		for (int i = 0; i < s.length(); i++) {
			if (isVowel(s[i])) {
				include = true;
				vcnt++;
				lcnt = 0;
			}
			else lcnt++,vcnt = 0;
			if (lcnt == 3 || vcnt == 3) {  // 3개의 모음 또는 자음이 연속되었는지 확인한다. 
				flag = true; // 잘못되었다.!!
			}
			if (prev == s[i] && i >= 1 && (s[i]!='e' && s[i] !='o')) { // 2개의 문자가 같은지 확인한다.!!
				flag = true;
			}
			prev = s[i];
		}
		if (include == false) { flag = true; }
		if (flag == true)  cout << "<" << s << ">" << " is not acceptable." << endl;
		else  cout << "<" << s << ">" << " is acceptable." << endl;
		
		
	}
}