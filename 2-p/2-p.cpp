#include <iostream>
#include <vector>
using namespace std;
// 벽을 3개 세우는 경우 + 바이러스
// 모든 경우의 수!!
vector<pair<int,int>> virus;
vector<pair<int,int>> wall;
vector<int, int>v;
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
bool visited[64][64];
int a[100][100];
int n, m;
void dfs(int y, int x) {
	
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m) {
			continue;
		}
		if (visited[ny][nx] || a[ny][nx] == 1) continue;
		visited[y][x] = 1;
		dfs(ny, nx);
	}
}
int solve() {
	fill(&visited[0][0], &visited[0][0] + 10 * 10, 0);
	for (pair<int,int> b: virus) {
		visited[b.first][b.second] = 1;
		dfs(b.first, b.second);
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 0 && !visited[i][j]) cnt++;
		}
	}
}
int main() {
	
	int a[64][64];
	int ret;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin>>a[i][j];
			if (a[i][j] == 2) virus.push_back({ i,j });
			if (a[i][j] == 1) wall.push_back({ i,j });
		}
	}
	for (int i = 0; i < wall.size(); i++) {  // 조합을 사용하여 벽을 세우는 경우
		for (int j = 0; j < i; j++) {
			for (int k = 0; k < j; k++) {
				a[wall[i].first][wall[i].second] = 1;
				a[wall[j].first][wall[j].second] = 1;
				a[wall[k].first][wall[k].second] = 1;
				ret = max(ret, solve());
				a[wall[i].first][wall[i].second] = 0;
				a[wall[j].first][wall[j].second] = 0;
				a[wall[k].first][wall[k].second] = 0;

			}
		}
	}
}