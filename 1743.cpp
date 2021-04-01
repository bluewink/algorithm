#include <iostream>
#include <algorithm>
using namespace std;
int wid, hgt, n;
int map[101][101];
int visited[101][101];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int cnt = 0;
void dfs(int px,int py) {

	cnt++;
	for (int dir = 0;dir < 4;dir++) {
		int nx = px + dx[dir];
		int ny = py + dy[dir];
		
		if (1<=nx && nx<=wid && 1<=ny && ny<=hgt && !visited[ny][nx] && map[ny][nx]) {
			visited[ny][nx] = 1;
			dfs(nx, ny);
		}
	}

	return;
}
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> hgt >> wid >> n;
	int r, c;
	for (int i = 0;i < n;i++){
		cin >> r >> c;
		map[r][c] = 1;
	}
	int MM = -1;
	for (int i = 1;i <= hgt;i++) {
		for (int j = 1;j <= wid;j++) {
			if (!visited[i][j] && map[i][j]) {
				visited[i][j] = 1;
				cnt = 0;
				dfs(j, i);
				MM = max(MM,cnt);
			}
		}
	}
	cout << MM;
	return 0;
}