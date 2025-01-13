#include <iostream>
using namespace std;


char a[101][101];


string go( int y, int x,int size) {
	if (size == 1) return string(1, a[y][x]);
	char b = a[y][x];
	string ret = "";
	bool flag = 0;
	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x+ size; j++) {
			if (b != a[i][j]) { // 다른 수가 나온다면 
				ret += "(";
				ret+= go(y, x, size / 2);
				ret+= go(y, x + size/2, size / 2);
				ret+= go(y + size / 2, x, size / 2);
				ret+= go(y + size / 2, x + size / 2, size / 2);
				ret += ")";
				return ret;
			}
		}
	}
	return string(1, a[y][x]);
}

int main() {
	int n; 
	string s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < n; j++) {
			a[i][j] = s[j];
		}
	}
	cout << go(0, 0,n) << endl;
}