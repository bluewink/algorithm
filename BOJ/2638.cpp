
/* 치즈

	잘못된 풀이
	1. 빈 공간을 기준으로 상하좌우를 벽쪽까지 검사했을때 치즈가 있으면 막힌 공간이라고 착각.
	2. 1번처럼 생각하면 뚫린 공간임에도 막힌 공간이라고 판단할 수 있음.

	막힌 공간임을 어떻게 알 수 있을까?
	생각의 전환 : 외부 공기를 기준으로 생각하자! 임의의 외부 공기로부터 BFS 혹은 DFS로 접근 가능하다면 그 공간은 외부 공간에 뚫린 공간이 된다.
	따라서 BFS를 이용해 막힌 공간 여부를 확인한다!


*/

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;


int wid, hgt;
int map[101][101];
int status[101][101];
int visited[101][101];
//상하좌우
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0, 0 };
queue <pair<int, int> > q;

bool checkFourSide(int xx, int yy) {
	int nx, ny;
	int cnt = 0;
	for (int i = 0;i < 4;i++) {
		nx = xx + dx[i];
		ny = yy + dy[i];
		//치즈가 없고, 막혀있지도 않다면
		if (map[ny][nx] == 0 && visited[ny][nx] ==1) {
			cnt++;
		}
	}
	if (cnt >= 2) {
		//사라질 치즈
		return true;
	}
	return false;
}

void checkSurround(int xx, int yy) {

	q.push({ yy,xx });
	int cx, cy;
	int nx, ny;
	visited[yy][xx] = 1;
	while (!q.empty()) {
		cx = q.front().second;
		cy = q.front().first;
	
		q.pop();
		for (int i = 0;i < 4;i++) {
			nx = cx + dx[i];
			ny = cy + dy[i];
			if (0<=nx && nx<wid && 0<=ny && ny<hgt && !visited[ny][nx] && map[ny][nx]==0) {
				visited[ny][nx] = 1;
				//외부 공기와 닿아 있다.
				q.push({ ny,nx });
			}
		}

	}

}



int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int leftCheese = 0;

	cin >> hgt >> wid;
	for (int r = 0;r < hgt;r++) {
		for (int c = 0;c < wid;c++) {
			cin >> map[r][c];
			if (map[r][c] == 1) {
				leftCheese++;
			}
		}
	}
	int ans = 0;
	if (!leftCheese) {
		cout << ans;
		return 0;
	}
	while (1) {
		//status 초기화
		for (int r = 0;r < hgt;r++) {
			for (int c = 0;c < wid;c++) {
				status[r][c] = 0;
				visited[r][c] = 0;
			}
		}

		//치즈로 둘러쌓여 있는지 체크
		checkSurround(0, 0);

		for (int r = 0;r < hgt;r++) {
			for (int c = 0;c < wid;c++) {
				if (map[r][c] == 1) {
					if (checkFourSide(c, r)) {
						//사라질 치즈
						status[r][c] = -1;
					}
				}
			}
		}
		leftCheese = 0;
		for (int r = 0;r < hgt;r++) {
			for (int c = 0;c < wid;c++) {
				if (status[r][c] == -1) {
					//치즈 녹이기
					map[r][c] = 0;
				}
				
				if (map[r][c] == 1) {
					leftCheese++;
				}
			}
		}
		ans++;
		if (leftCheese == 0) {
			break;
		}
	}
	cout << ans;

	return 0;
}