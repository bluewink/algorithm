/*
	10:50 시작 11:37 ac
*/

#include <iostream>
#include <vector>
using namespace std;
int left_food[11][11], n,m,k, new_food[11][11];
vector<int> trees[11][11], dead_trees[11][11];	//element는 tree의 나이
int dx[8] = { 0,1,1,1,0,-1,-1,-1 };
int dy[8] = { -1,-1,0,1,1,1,0,-1 };
int solve() {
	int year = 0;
	while (1) {
		if (year == k) {
			break;
		}
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= n;j++) {
				if (!trees[i][j].empty()) {
					for (int k = trees[i][j].size() - 1;k >= 0;k--) {
						int cur_age = trees[i][j][k];
						if (left_food[i][j] < cur_age) {
							//양분이 모자람
							//trees[i][j][k] = -1;
							dead_trees[i][j].push_back(k);
							continue;
						}
						else {
							trees[i][j][k]++;
							left_food[i][j] -= cur_age;
						}
					}
				}

			}
		}

		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= n;j++) {
				if (!dead_trees[i][j].empty()) {
					for (int x : dead_trees[i][j]) {
						int cur_age = trees[i][j][x];
						left_food[i][j] += cur_age / 2;
						trees[i][j].erase(trees[i][j].begin()+x);
					}
					dead_trees[i][j].clear();
				}
			}
		}

		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= n;j++) {
				if (!trees[i][j].empty()) {
					for (int age : trees[i][j]) {
						if (age % 5 == 0) {
							for (int dir = 0;dir < 8;dir++) {
								int nx = j + dx[dir];
								int ny = i + dy[dir];
								if (1 <= nx && nx <= n && 1 <= ny && ny <= n) {
									trees[ny][nx].push_back(1);
								}
							}
						}
					}
				}
			}
		}

		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= n;j++) {
				left_food[i][j] += new_food[i][j];
			}
		}
		year++;
	}
	int cnt = 0;
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			cnt += trees[i][j].size();
		}
	}
	return cnt;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			cin >> new_food[i][j];
			left_food[i][j] = 5;
		}
	}
	int r, c, age;
	for (int i = 0;i < m;i++) {
		cin >> r >> c >> age;
		trees[r][c].push_back(age);
	}

	cout << solve();

	return 0;
}