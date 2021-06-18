#include <iostream>
#include <queue>
using namespace std;
int hgt, wid;
char map[51][51];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int visited[51][51], my_visited[51][51];
queue<pair<int, int>> q;
queue<pair<int, pair<int, int>> > mq;

int my_bfs() {
	
	while (!mq.empty()) {
		int px = mq.front().second.second;
		int py = mq.front().second.first;
		int turn = mq.front().first;
		mq.pop();
		if (map[py][px] == 'D') {
			return turn;
		}
		for (int dir = 0;dir < 4;dir++) {
			int nx = px + dx[dir];
			int ny = py + dy[dir];
			if (0 <= nx && nx < wid && 0 <= ny && ny < hgt) {
				if (my_visited[ny][nx] || map[ny][nx] == 'X'  ) {
					continue;
				}
				if (visited[ny][nx] > 0) {
					if (visited[ny][nx] - 2 <= turn)
						continue;
				}
				my_visited[ny][nx] = 1;
				mq.push({ turn + 1,{ny,nx} });
			}
		}
	}
	return -1;
}

void bfs() {
	while (!q.empty()) {
		int px = q.front().second;
		int py = q.front().first;
		q.pop();
		for (int dir = 0;dir < 4;dir++) {
			int nx = px + dx[dir];
			int ny = py + dy[dir];
			if (0 <= nx && nx < wid && 0 <= ny && ny < hgt) {
				if (map[ny][nx] == 'X' || map[ny][nx] == 'D' || visited[ny][nx]) {
					continue;
				}
				visited[ny][nx] = visited[py][px] + 1;
				q.push({ ny,nx });
			}
		}	
	}

}
int main() {

	cin >> hgt >> wid;
	for (int i = 0;i < hgt;i++) {
		for (int j = 0;j < wid;j++) {
			cin >> map[i][j];
			if (map[i][j] == '*') {
				q.push({ i,j });
				visited[i][j] = 1;
			}
			if (map[i][j] == 'S') {
				mq.push({ 0,{i,j} });
				my_visited[i][j] = 1;
			}
			if (map[i][j] == 'D')
				visited[i][j] = 987654321;
		}
	}
	bfs();
	/*
	for (int i = 0;i < hgt;i++) {
		for (int j = 0;j < wid;j++) {
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}
	*/
	int res = my_bfs();
	if (res == -1) {
		cout << "KAKTUS";
	}
	else
		cout << res;
	return 0;
}