#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int l, r, c;
char map[31][31][31];	//l,r,c
int dx[6] = { 0,0,-1,1,0,0 };
int dy[6] = { -1,1,0,0,0,0 };
int dz[6] = { 0,0,0,0,-1,1 };
int visited[31][31][31];
queue<pair<int,pair<int, int>>> q; //z,y,x
void bfs() {

	while (!q.empty()) {
		int px = q.front().second.second;
		int py = q.front().second.first;
		int pz = q.front().first;
		q.pop();

		if (map[pz][py][px] == 'E') {
			//Á¾·á
			cout << "Escaped in " << visited[pz][py][px]-1 << " minute(s)." << '\n';
			return;
		}
		for (int dir = 0;dir < 6;dir++) {
			int nx = px + dx[dir];
			int ny = py + dy[dir];
			int nz = pz + dz[dir];
			if (0 <= nx && nx < c && 0 <= ny && ny < r && 0 <= nz && nz < l) {
				if (map[nz][ny][nx] == '#')
					continue;

				if (!visited[nz][ny][nx]) {
					visited[nz][ny][nx] = visited[pz][py][px] + 1;
					q.push({ nz,{ny,nx} });
				}
			}


		}

	}
	cout << "Trapped!\n";
}

int main() {
	while (1) {
		cin >> l >> r >> c;
		if (l == 0 && r == 0 && c == 0)
			break;

		memset(visited, 0, sizeof(visited));
		while (!q.empty())
			q.pop();
		//memset(map, 0, sizeof(map));
		for (int f = 0;f < l;f++) {
			for (int i = 0;i < r;i++) {
				for (int j = 0;j < c;j++) {
					cin >> map[f][i][j];
					if (map[f][i][j] == 'S') {
						visited[f][i][j] = 1;
						q.push({ f,{i,j} });
					}
				}
			}
		}
		bfs();
	}
	return 0;
}