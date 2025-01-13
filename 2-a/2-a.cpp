#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
int N, M;
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
int visited[100][100];
int a[100][100];

// 최단 거리를 구하는 거기에 bfs 쓸 생각을 해야한다. 

void bfs(int y,int x) {
	queue<pair<int, int>> q;
	visited[y][x] = 1;
	q.push({ y,x });
	while (!q.empty()) {
		pair<int,int> here = q.front();
		q.pop(); // 꼭 작성!!
		for (int i = 0; i < 4; i++) {
			int ny = here.first + dy[i];// 실수 i로 표시해야한다. 
			int nx = here.second + dx[i];
			if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue; // 실수
			if (a[ny][nx] == 0) continue;
			if (!visited[ny][nx]) {
				visited[ny][nx] = visited[here.first][here.second] + 1;
				q.push({ny,nx});
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.length(); j++) {
			a[i][j] = s[j] - '0';
		}
	}
	bfs(0, 0);
	cout << visited[N-1][M-1];
}
