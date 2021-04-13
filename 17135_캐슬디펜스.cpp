/*
	몬스터를 따로 저장해서 짰다. 
	턴이 종료될 때 monster를 erase시키는 과정에서 out of index error로 고생했다.
	
	결국 erase 시키지 않고 상태를 0,1,2 로 구현했는데 지저분하다..
	오히려 map[][]을 이용해서 구현하면 더 깔끔하겠다.
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef pair<int, int> pi;

int wid, hgt, d;
int map[16][16];
vector<int> selected_col;
vector<pair<int,pair<int,int>> > target;

int visited[16];
int MM = -1;

int play() {
	int cnt = 0;
	int dead_cnt = 0;
	while (1) {
		if (dead_cnt >= target.size())
			break;
		for (int i = 0;i < wid;i++) {
			if (map[hgt][i] == 2) {
				int gx = i;
				int gy = hgt;
				int mm = 987654321;
				int min_x = 987654321;
				int target_idx = -1;
				for (int j = 0;j < target.size();j++) {
					if (target[j].first==2)
						continue;
					int tx = target[j].second.second;
					int ty = target[j].second.first;
					int dist = abs(tx - gx) + abs(ty - gy);
					if (dist <= d) {
						if (dist < mm) {
							mm = dist;
							min_x = tx;
							target_idx = j;
						}
						else if (dist == mm) {
							if (tx < min_x) {
								min_x = tx;
								target_idx = j;
							}
						}
					}
				}
				if (target_idx == -1)
					continue;
				target[target_idx].first = 1;
			
			}
		}
		for (int j = 0;j < target.size();j++) {
			if (target[j].first == 2)
				continue;
			target[j].second.first++;
			if (target[j].first==1) {
				target[j].first = 2;
				cnt++;
				dead_cnt++;
			}
			else if (target[j].second.first == hgt) {
				dead_cnt++;
				target[j].first = 2;
			}
		}
	}
	return cnt;
}

void go(int idx, int dep) {
	if (dep == 3) {
		vector<pair<int, pair<int, int>> > tmp_target = target;
		for (int x : selected_col) {
			map[hgt][x] = 2;	
		}

		MM = max(MM, play());
		for (int x : selected_col) {
			map[hgt][x] = 0;	
		}
		target = tmp_target;
		return;
	}

	for (int i = idx;i < wid;i++) {
		if (!visited[i]) {
			visited[i] = 1;
			selected_col.push_back(i);
			go(idx + 1, dep + 1);
			selected_col.pop_back();
			visited[i] = 0;
		}
	}

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> hgt >> wid >> d;

	for (int i = 0;i < hgt;i++) {
		for (int j = 0;j < wid;j++) {
			cin >> map[i][j];
			if (map[i][j]) {
				target.push_back({ 0,{ i,j } });
			}
		}
	}
	go(0, 0);
	cout << MM;
	return 0;
}