/*
	dfs�� �̿��� ���� ����� + bfs�� �����ð� ã��.
	
	�ð��ʰ�.. -> 1. ��� ���� Ž����������, virus ������ ���� �����صξ��ٰ� ������ �����Ѵ�.
				2. ������ �����ߴ��� Ȯ���� �� ���� for loop -> ���̷��� + �� ���� == �� entry ������ �ذ�

	�������� : 1. dfs�� ���� ����� vector�� Ȱ���Ѵٸ� select�迭 ���� �� �ʿ�x
			  2. �ٸ� �ڵ带 ���� cnt�� queue�� �����ʰ� time map�� Ȱ���Ѵ�. -> ���߿� �̸� Ȱ���غ���
	
	�ð����⵵ : 2^n * n*n
*/

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int n, m;
int map[51][51], visited[51][51], selected[51], org[51][51];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
queue<pair<int, pair<int, int>>> q; //x,y
vector<pair<int, int>> vec, vir;

int ans = 987654321;
int w_num, v_num;
int cnt = 0;
void reset() {
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			map[i][j] = org[i][j];
			visited[i][j] = 0;
		}
	}
}
int check() {
	/*
	if (v_num + w_num == n * n) {
		return 1;
	}
	return 0;
	*/
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (map[i][j] == 0)
				return 0;
		}
	}
	return 1;
}

void play() {

	while (!q.empty()) {
		int px = q.front().second.first;
		int py = q.front().second.second;
		int cnt = q.front().first;
		q.pop();

		for (int i = 0;i < 4;i++) {
			int nx = px + dx[i];
			int ny = py + dy[i];

			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (!visited[ny][nx] && map[ny][nx] != 1) {
					//���� �ƴϸ�
					if (map[ny][nx] == 0)
						v_num++;
					map[ny][nx] = 2;	//���̷��� Ȱ��ȭ
					
					if (check()) {
						ans = min(ans, cnt+1);
						break;
					}
					q.push({ cnt + 1,{nx,ny} });
					visited[ny][nx] = 1;
				}
			}
		}
	}
	while (!q.empty()) {
		q.pop();
	}

}

void go(int dep, int idx) {

	if (dep == m) {
		//m���� ��� ����
		//cnt++;
		for (pair<int, int> pi : vec) {
			int xx = pi.first;
			int yy = pi.second;
	
			q.push({ 0,{ xx,yy } });
			visited[yy][xx] = 1;
			//cout << yy << " " << xx << endl;
		}
		//cout << endl;
		if (check())
			ans = 0;
		int tmp = v_num;
		play();
		v_num = tmp;
		reset();

		return;
	}

	/*
	for (int i = yy;i < n;i++) {
		for (int j = xx;j < n;j++) {
			if (!selected[i][j] && map[i][j]==2) {
				selected[i][j] = 1;
				vec.push_back({ j,i });
				go(dep + 1, i, j+1);
				vec.pop_back();
				selected[i][j] = 0;
			}
		}
	}
	*/
	for (int i = idx;i < vir.size();i++) {
		if (!selected[i]) {
			selected[i] = 1;
			vec.push_back({ vir[i].first,vir[i].second });
			go(dep + 1, i+1);
			vec.pop_back();
			selected[i] = 0;
		}
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> map[i][j];
			org[i][j] = map[i][j];
			if (map[i][j] == 1)
				w_num++;
			if (map[i][j] == 2) {
				v_num++;
				vir.push_back({ j,i });
			}
		}
	}

	go(0, 0);

	if (ans == 987654321) {
		cout << -1;
	}
	else {
		cout << ans;
	}
	//cout << "cnt : " << cnt << endl;
	return 0;

}