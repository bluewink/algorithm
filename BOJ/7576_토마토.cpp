#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
int wid, hgt;
int map[1001][1001];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int MM = -1;
queue<pair<int, int> > q;
bool check() {
	for (int i = 0;i < hgt; i++) {
		for (int j = 0;j < wid;j++) {
			if (!map[i][j])
				return false;
			MM = max(MM, map[i][j]);
		}
	}
	return true;
}
void bfs() {
	while (!q.empty()) {
		int py = q.front().first;
		int px = q.front().second;
		q.pop();
		for (int dir = 0;dir < 4;dir++) {
			int ny = py + dy[dir];
			int nx = px + dx[dir];
			if (0 <= nx && nx < wid && 0 <= ny && ny < hgt) {
				if (!map[ny][nx]) {
					map[ny][nx] = map[py][px] + 1;
					q.push({ ny,nx });
				}
			}
		}	
	}
}
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> wid >> hgt;

	for (int i = 0;i < hgt; i++) {
		for (int j = 0;j < wid;j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				q.push({ i,j });
			}
		}
	}
	bfs();
	if (check())
		cout << MM - 1;
	else
		cout << -1;

	return 0;
}