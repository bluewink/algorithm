#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int wid, hgt,k;
int visited[1001][1001][11], map[1001][1001];
queue<pair<int, pair<int, int>> > q;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int bfs() {

	while (!q.empty()) {
		int chance = q.front().first;
		int px = q.front().second.second;
		int py = q.front().second.first;
		q.pop();
		if (px == wid - 1 && py == hgt - 1) {		
			return visited[py][px][chance];
		}
		for (int dir = 0;dir < 4;dir++) {
			int nx = px + dx[dir];
			int ny = py + dy[dir];

			if (0 <= nx && nx < wid && 0 <= ny && ny < hgt) {
				
				if (!map[ny][nx]) {
					//ºó °ø°£
					if (!visited[ny][nx][chance]) {
						visited[ny][nx][chance] = visited[py][px][chance] + 1;
						q.push({ chance,{ny,nx} });
					}

				}
				else {
					//º®
					if (chance <= 0)
						continue;
					if (!visited[ny][nx][chance-1]) {
						visited[ny][nx][chance-1] = visited[py][px][chance] + 1;
						q.push({ chance-1,{ny,nx} });
					}
					
				}

			}
		}
	}
	return -1;
}
int main() {

	cin >> hgt >> wid >> k;

	for (int i = 0;i < hgt;i++) {
		for (int j = 0;j < wid;j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	visited[0][0][k] = 1;
	q.push({ k,{ 0,0 } });
	cout << bfs();
	

	return 0;
}