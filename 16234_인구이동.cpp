/*
	dfs로 영역 구분하기
	-> 영역별로 숫자 재분배.

	삽질
	: 변수명을 idx라고 불분명하게 지었다가 엉뚱하게 사용해서 디버깅했음.
	-> idx가 아닌 team_id 로 하면 더 좋을듯.


*/

#include <iostream>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;
int map[51][51];
int n, l, r;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int team[51][51];
int sum[2501];
int num[2501];
vector<pair<int,int>> vec[2501];
int opened = 0;
void dfs(int team_id,int px, int py) {

	int nx, ny;
	team[py][px] = team_id;
	sum[team_id] += map[py][px];
	num[team_id]++;
	vec[team_id].push_back({ py,px });
	for (int i = 0;i < 4;i++) {
		nx = px + dx[i];
		ny = py + dy[i];

		if (0 <= nx && nx < n && 0 <= ny && ny < n) {
			int diff = abs(map[ny][nx] - map[py][px]);
			if (l <= diff && diff <= r) {
				
				if (!team[ny][nx]) {
					//아직 미정이면
					team[ny][nx] = team_id;
					dfs(idx, nx, ny);
				}
			
			}

		}

	}


}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> l >> r;
	
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> map[i][j];
		}
	}
	int ans = 0;
	while (1) {
		int team_id = 1; //팀 id

		for (int i = 0;i < n;i++) {
			for (int j = 0;j < n;j++) {
				if (!team[i][j]) {
					dfs(team_id++, j, i);
				}
			}
		}
		opened = 0;
		
		for (int i = 1;i <= team_id;i++) {
			if (num[i] <= 1)
				continue;
		
			opened = 1;
			
			for (pair<int, int> p : vec[i]) {
				
				int px = p.second;
				int py = p.first;
				
				map[py][px] = sum[i] / num[i];
			}
		}
		if (opened) {
			ans++;
		}
		else {
			cout << ans;
			return 0;
		}
		memset(team, 0, sizeof(team));
		for (int i = 0;i <= team_id;i++) {
			num[i] = sum[i] = 0;
			vec[i].clear();
		}
		
	}


	return 0;
}