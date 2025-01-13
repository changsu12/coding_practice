#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;


int N;
bool visited[101][101];
int a[101][101];
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
void dfs(int y, int x,int height);
int ret = 1;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	int maxans = 0;
	int minHeight = 101, maxHeight = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a[i][j];
			
		}
	}
	int height = 1;
	for(int d =0 ; d< 101; d++ ){
		memset(visited, false, sizeof(visited));
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j] && a[i][j] > d) {
					dfs(i, j, d);
					cnt++;
				}
			}
		}
		ret = max(ret, cnt);
		
	}
	cout << ret << endl;
}


void dfs(int y, int x, int height) {
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ay = y + dy[i];
		int ax = x + dx[i];
		if (ay < 0 || ax < 0 || ay >= N || ax >= N) continue;
		if (visited[ay][ax]) continue;
		if (a[ay][ax] <=height) continue;
		dfs(ay, ax,height);
	}
}