#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
//custom operator!!
vector<pair<int, int>> v;
map<int, int> mp,mp_first;
int a[1004];
bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) {
		return mp_first[a.second] < mp_first[b.second];
	}
	return a.first > b.first;
}



int main() {
	int n, temp;
	cin >> n >> temp;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mp[a[i]]++;
		if (mp_first[a[i]] == 0) { mp_first[a[i]] = i + 1; }
	}
	for (auto ret : mp) {
		v.push_back({ ret.second, ret.first });
	}
	sort(v.begin(), v.end(), cmp);
	for (auto i : v) {
		for (int j = 0; j < i.first; j++) {
			cout << i.second <<" ";
		}
	}


}