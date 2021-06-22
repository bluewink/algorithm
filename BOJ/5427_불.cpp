#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int, int> pi;
int wid, hgt;
char board[1001][1001];
int fire[1001][1001], user[1001][1001];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
queue<pi> fq, uq;

int user_bfs() {

	while (!uq.empty()) {
		int px = uq.front().second;
		int py = uq.front().first;
		uq.pop();

		if (px == 0 || px == wid + 1 || py == 0 || py == hgt + 1) {
			//바로 탈출 예외처리
			return user[py][px] + 1;
		}
		
		for (int dir = 0;dir < 4;dir++) {
			int nx = px + dx[dir];
			int ny = py + dy[dir];
			if (0 <= nx && nx <= wid+1 && 0 <= ny && ny <= hgt+1) {
				if (board[ny][nx] == '#') {
					continue;
				}
				if (!fire[ny][nx] || fire[ny][nx] > user[py][px] + 2) {
					//이동 가능
					if (user[ny][nx])	//이미 방문한 곳
						continue;

					if (nx == 0 || nx == wid+1 || ny == 0 || ny == hgt+1) {
						//탈출
						//cout << py << " " << px << endl;
						return user[py][px]+1;
					}

					user[ny][nx] = user[py][px] + 1;
					uq.push({ ny,nx });
				}
			}
		}
	}
	return -1;
}

void fire_bfs() {

	while (!fq.empty()) {
		int px = fq.front().second;
		int py = fq.front().first;
		fq.pop();
		for (int dir = 0;dir < 4;dir++) {
			int nx = px + dx[dir];
			int ny = py + dy[dir];
			if (0 < nx && nx <= wid && 0 < ny && ny <= hgt) {
				if (board[ny][nx] == '#') {
					continue;
				}
				if (!fire[ny][nx]) {
					fire[ny][nx] = fire[py][px] + 1;
					fq.push({ ny,nx });
				}
			}
		}
	}
}

int main() {

	int tn;
	cin >> tn;
	while (tn--) {

		while (!uq.empty())
			uq.pop();
		while (!fq.empty())
			fq.pop();
		memset(fire, 0, sizeof(fire));
		memset(user, 0, sizeof(user));
		memset(board, 0, sizeof(board));
		cin >> wid >> hgt;
		for (int i = 1;i <= hgt;i++) {
			for (int j = 1;j <= wid;j++) {
				cin >> board[i][j];
				if (board[i][j] == '@') {
					//user[i][j] = 1;
					uq.push({ i,j });
				}
				if (board[i][j] == '*') {
					fire[i][j] = 1;
					fq.push({ i,j });
				}
			}
		}

		fire_bfs();
		int res = user_bfs();
		if (res == -1)
			cout << "IMPOSSIBLE" << '\n';
		else
			cout << res << '\n';
	}


	return 0;
}