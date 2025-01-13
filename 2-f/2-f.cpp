#include <iostream>
using namespace std;



int l=1, r=1; // 바구니의 첫 시작점 


int main() {
	int n, m, j;
	cin >> n >> m;
	cin >> j;
	r = l + m - 1;
	int cnt = 0;
	for (int i = 0; i < j; i++) {
		int a;
		cin >> a ;
		if (a>=l && a<=r) {
			continue;
		}
		else if (l >a) {
			cnt = cnt + l - a;
			l= a;
			r = l + m - 1;
			
		}
		else if (r < a) {
			cnt = cnt + a - r;
			r = a;
			l = r - m + 1;
			
		}
	}
	cout << cnt;
}