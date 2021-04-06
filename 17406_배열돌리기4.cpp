/*
	배열돌리기.

	1. 중복을 허용하지 않는 순열
	2. 회전 후 임시 배열 값을 원 배열 값에 저장할 때 boundary 오류
	
	문제로 헤맸다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int wid, hgt, k;
int map[51][51], tmp_map[51][51], copy_map[51][51];
vector<vector<int>> insts;
vector<int> selected;
int visited[8];
int ans = 987654321;
void rot(int sx,int sy, int len) {	
	if (len<=1) {
		return;
	}
	int xx, yy;
	for (xx = sx;xx < sx + len;xx++) {
		tmp_map[sy][xx + 1] = map[sy][xx];
	}
	for (yy = sy;yy < sy + len;yy++) {
		tmp_map[yy+1][sx + len] = map[yy][sx+len];
	}
	for (xx = sx+len;xx > sx;xx--) {
		tmp_map[sy+len][xx-1] = map[sy+len][xx];
	}
	for (yy = sy+len;yy > sy;yy--) {
		tmp_map[yy-1][sx] = map[yy][sx];
	}
	for (int r = sy;r <= sy + len;r++) {
		for (int c = sx;c <= sx + len;c++) {
			map[r][c] = tmp_map[r][c];
		}
	}
	rot( sx + 1, sy + 1, len - 2);
}

void go(int idx, int dep) {

	if (dep == k) {
		for (int i = 1;i <= hgt;i++) {
			for (int j = 1;j <= wid;j++) {
				copy_map[i][j] = map[i][j];
				tmp_map[i][j] = map[i][j];
			}
		}
		for (int x : selected) {
			int r = insts[x][0];
			int c = insts[x][1];
			int s = insts[x][2];
			rot(c - s, r - s, 2 * s);
		}
		int row_sum = 0;
		for (int i = 1;i <= hgt;i++) {
			row_sum = 0;
			for (int j = 1;j <= wid;j++) {
				row_sum += map[i][j];
				map[i][j] = copy_map[i][j];
			}
			ans = min(ans, row_sum);
		}
		return;
	}

	for (int i = 0;i < k;i++) {
		if (!visited[i]) {
			visited[i] = 1;
			selected.push_back(i);
			go(i + 1, dep + 1);
			selected.pop_back();
			visited[i] = 0;
		}
	}

}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> hgt >> wid >> k;

	for (int i = 1;i <= hgt;i++) {
		for (int j = 1;j <= wid;j++) {
			cin >> map[i][j];
		}
	}
	int r, c, s;
	for (int i = 0;i < k;i++) {
		cin >> r >> c >> s;
		vector<int> inst = { r,c,s };
		insts.push_back(inst);
	}
	go(0, 0);
	cout << ans;

	return 0;
}