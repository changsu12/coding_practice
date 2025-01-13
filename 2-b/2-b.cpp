#include <iostream>
#include <cstring>
using namespace std;
//connected compponent를 사용해서 푸는 문제 -> dfs, bfs 상관 없지만 dfs로 

int n, m, w;
int a[50][50];
bool visited[50][50];
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
void dfs(int y, int x);
int ans;

int main() {
	int x = 0;
	int t;
	cin >> t;
	while (x < t) {
		cin >> n >> m >> w;
		int ax, b;
		memset(a, 0, sizeof(a)); // a 배열 초기화
		memset(visited, false, sizeof(visited)); // visited 배열 초기화
		for (int i = 0; i < w; i++) {
			cin >> ax >> b;
			a[ax][b] = 1;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!visited[i][j] && a[i][j] == 1) {
					dfs(i, j);
					ans++;
				}
			}
		}

		cout << ans << endl;
		ans = 0;
		x++;
	}

}
void dfs(int y, int x) {

	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ya = y + dy[i];
		int xa = x + dx[i];
		if (ya < 0 || xa < 0 || ya >= n || xa >= m) continue;
		if (visited[ya][xa]) continue;
		if (a[ya][xa] == 0)continue;
		dfs(ya, xa);
	}

}