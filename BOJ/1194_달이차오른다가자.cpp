/*
	bfs + dfs 로 풀이를 시도했으나 시간 초과...
	풀이를 찾아보니 비트마스크 + bfs로 해결할 수 있다고 한다.
	다음에 다시 시도해보자.
*/

#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
char map[51][51];
int wid, hgt;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int ans = 987654321;
int key[8];
void bfs(int sx,int sy,int cnt) {
	int visited[50][50];
	memset(visited, 0, sizeof(visited));
	queue <pair<int,pair<int,int>>> q;
	int exit_flag = 0;
	q.push({ cnt,{sy,sx} });
	visited[sy][sx] = 1;
	while (!q.empty()) {
		int px = q.front().second.second;
		int py = q.front().second.first;
		int cnt = q.front().first;
		q.pop();
		for (int dir = 0;dir < 4;dir++) {
			int nx = px + dx[dir];
			int ny = py + dy[dir];
			if (0 <= nx && nx < wid && 0 <= ny && ny < hgt) {
				if (!visited[ny][nx]) {
					if (map[ny][nx] == '#')
						continue;

					if ('a' <= map[ny][nx] && map[ny][nx] <= 'f') {
						if (key[map[ny][nx] - 'a']) {
							continue;
						}
						key[map[ny][nx] - 'a'] = 1;
						bfs(nx, ny, cnt + 1);
						key[map[ny][nx] - 'a'] = 0;
						visited[ny][nx] = 1;
					}
					else if ('A' <= map[ny][nx] && map[ny][nx] <= 'F') {
						if (key[map[ny][nx] - 'A']) {
							//go
							visited[ny][nx] = 1;
							q.push({ cnt + 1,{ny,nx} });
						}
					}
					else if (map[ny][nx] == '.' || map[ny][nx] == '0') {
						//go
						visited[ny][nx] = 1;
						q.push({ cnt + 1,{ny,nx} });
					}
					else {
						// Ż��
						ans = min(ans, cnt + 1);
						exit_flag = 1;
						break;
					}
				}
			}
		}
		if (exit_flag) {
			break;
		}
	}

}

int main() {

	scanf("%d %d", &hgt, &wid);
	int sx, sy;
	for (int i = 0;i < hgt;i++) {
		for (int j = 0;j < wid;j++) {
			scanf(" %c", &map[i][j]);
			if (map[i][j] == '0') {
				sx = j; sy = i;
			}
		}
	}
	
	bfs(sx, sy, 0);
	if (ans == 987654321)
		printf("%d",-1);
	else
		printf("%d", ans);
}