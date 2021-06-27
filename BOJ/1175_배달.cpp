#include <iostream>
#include <queue>
using namespace std;
struct info {
	int x, y, direction, t1,t2,cnt;
	info(int _x, int _y, int _d, int _t1, int _t2, int _c) {
		x = _x;
		y = _y;
		direction = _d;
		t1 = _t1;
		t2 = _t2;
		cnt = _c;
	}
};
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int w, h;
char map[51][51];
queue<info> q;
int visited[4][4][4][51][51];	// t1,t2, dir, y,x

void bfs() {

	while (!q.empty()) {
		int px = q.front().x;
		int py = q.front().y;
		//cout << py << " " << px << endl;
		int pdir = q.front().direction;
		int t1 = q.front().t1;
		int t2 = q.front().t2;
		int cnt = q.front().cnt;
		q.pop();
		if (t1 && t2) {
			cout << cnt;
			return;
		}
		for (int dir = 0;dir < 4;dir++) {
			int nx = px + dx[dir];
			int ny = py + dy[dir];
			if (pdir == dir)
				continue;
			if (0 <= nx && nx < w && 0 <= ny && ny < h) {
				if (map[ny][nx] == '#')
					continue;
				if (!visited[t1][t2][dir][ny][nx]) {
					visited[t1][t2][dir][ny][nx] = 1;
					int tmp1 = t1;
					int tmp2 = t2;
					if (map[ny][nx] == 'C') 
						t1 = 1;
					if (map[ny][nx] == 'D')
						t2 = 1;

					q.push(info(nx,ny,dir,t1,t2,cnt+1));
					t1 = tmp1;
					t2 = tmp2;
				}
				
			}
		}
		

	}
	cout << -1;
}

int main() {

	cin >> h >> w;
	int flag = 0;
	for (int i = 0;i < h;i++) {
		for (int j = 0;j < w;j++) {
			cin >> map[i][j];
			if (map[i][j] == 'S') {
				q.push(info(j,i,-1,0,0,0));
			}
			if (map[i][j] == 'C') {
				if (!flag)
					flag = 1;
				else
					map[i][j] = 'D';
			}
			
		}
	}
	bfs();


	return 0;
}