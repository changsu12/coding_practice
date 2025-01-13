#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool visited[101][101];
int ax[104][104];
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
int N, M;
vector<int> ret;


int dfs(int y, int x) {
	visited[y][x] = true;
	int ret = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= M || nx >= N) continue;
		if (visited[ny][nx]==1)continue;
		if (ax[ny][nx] == 1) continue;
		ret+= dfs(ny, nx);
	}
	return ret;
}

int main() {
	int sq; // 직사각형의 개수 
	int x1, y1, x2, y2;
	cin >> M>> N >> sq;
	int cnt=0;
	for (int i = 0; i < sq; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		for (int x = x1; x < x2; x++) {
			for (int y = y1; y < y2; y++) {
				ax[y][x] = 1;
			}
		}
	}
	
	
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (ax[i][j]!=1 && visited[i][j]==0) {
				ret.push_back(dfs(i, j));
				
			}
		}
	}
	sort(ret.begin(), ret.end());
	cout << ret.size() << endl;
	for (int size : ret) {
		cout << size << " ";
	}
}