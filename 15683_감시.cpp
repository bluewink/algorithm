/*
	15:00 시작, 15:50 종료
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct _cctv {
	int type;
	int px;
	int py;
};
int wid, hgt, cctv_num;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int board[9][9], tmp_board[9][9];
int ans = 987654321;
_cctv cctv[10];
vector<int> directions;

void mark(int dir, int px,int py) {

	while (1) {
		int nx = px + dx[dir];
		int ny = py + dy[dir];
		if (0 > nx || nx >= wid || 0 > ny || ny >= hgt) {
			break;
		}
		if (board[ny][nx] == 6) {
			break;
		}
		if(1<=board[ny][nx] && board[ny][nx]<=5){
			px = nx;
			py = ny;
			continue;
		}
		board[ny][nx] = -1;
		px = nx;
		py = ny;
	}

}

void dfs(int num, int idx) {

	if (num == cctv_num) {

		for (int i = 0;i < hgt;i++) {
			for (int j = 0;j < wid;j++) {
				tmp_board[i][j] = board[i][j];
			}
		}
		for (int i = 0;i < cctv_num;i++) {
			int xx = cctv[i].px;
			int yy = cctv[i].py;
			int type = cctv[i].type;
			int dir = directions[i];
			switch (type)
			{
			case 1:
				mark(dir, xx, yy);
				break;
			case 2:
				if (dir == 0 || dir == 2) {
					mark(0, xx, yy);
					mark(1, xx, yy);
				}
				else {
					mark(3, xx, yy);
					mark(2, xx, yy);
				}
				break;
			case 3:
				switch (dir)
				{
				case 0:
					mark(0, xx, yy);
					mark(2, xx, yy);
					break;
				case 1:
					mark(0, xx, yy);
					mark(3, xx, yy);
					break;
				case 2:
					mark(2, xx, yy);
					mark(1, xx, yy);
					break;
				case 3:
					mark(3, xx, yy);
					mark(1, xx, yy);
					break;
				default:
					break;
				}
				break;
			case 4:
				for (int j = 0;j < 4;j++) {
					if (j == dir)
						continue;
					mark(j, xx, yy);
				}
				break;
			case 5:
				for (int j = 0;j < 4;j++) {
					mark(j, xx, yy);
				}
				break;
			default:
				break;
			}

		}
		int cnt = 0;
		for (int i = 0;i < hgt;i++) {
			for (int j = 0;j < wid;j++) {
				if (!board[i][j])
					cnt++;
				board[i][j] = tmp_board[i][j];
			}
		}
		ans = min(ans, cnt);

		return;
	}
	for (int i = idx;i < cctv_num;i++) {
		for (int dir = 0;dir < 4;dir++) {
			directions.push_back(dir);
			dfs(num + 1,i+1);
			directions.pop_back();
		}
	}

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> hgt >> wid;
	
	for (int i = 0;i < hgt;i++) {
		for (int j = 0;j < wid;j++) {
			cin >> board[i][j];
			if (1 <= board[i][j] && board[i][j] <= 5) {
				cctv[cctv_num].px = j;
				cctv[cctv_num].py = i;
				cctv[cctv_num].type = board[i][j];
				cctv_num++;
			}
		}
	}
	dfs(0,0);
	cout << ans;
	return 0;

}