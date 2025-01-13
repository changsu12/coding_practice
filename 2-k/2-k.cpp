#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		int five_cnt = 0;
		for (int i = 5; i <= n; i *= 5) {
			five_cnt += n / i;
		}
		
		cout << five_cnt << "\n";
	}
	

}