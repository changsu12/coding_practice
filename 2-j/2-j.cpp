#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int a[101][101];
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		int cnt = -1;
		bool flag = false;
		for (int j = 0; j < m; j++) {
			if (s[j] == 'c') {
				a[i][j]=0;
				cnt = 1;
				flag = true;
			}
			else {
				if (flag == false) {
					a[i][j] = -1;
				}
				else {
					a[i][j] = cnt;
					cnt++;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j]<<" ";
		}
		cout << endl;
	}

}

