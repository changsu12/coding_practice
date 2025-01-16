#include <iostream>
#include <vector>
#include <string>
using namespace std;
int N, M;
bool visited[10004];
int cnt[10004];
vector<int> v[10004];

int dfs(int x) {
	int ret = 1;
	for (int here : v[x]) {
		if (visited[here]) continue;
		visited[here] = 1;
		ret+=dfs(here);
	}
	return ret;
}


int main() {
	cin >> N >> M;
	int mx;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		v[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		memset(visited, 0, sizeof(visited));
		cnt[i] = dfs(i);
		mx = max(mx, cnt[i]);
	}
	for (int i = 1; i <= N; i++) {
		if (cnt[i] == mx) {
			cout << i << " ";
		}
	}

}