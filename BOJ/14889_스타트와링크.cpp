#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int map[21][21];

int n;
vector<int> vec, opp;
int visited[21];
int team[21];
int mm = 98764321;
void go(int idx,int dep) {
	if (dep == n / 2) {
		// n/2명 선택 완료
		
		for (int i = 1;i <= n;i++) {
			if (find(vec.begin(), vec.end(), i) == vec.end()) {
				opp.push_back(i);
			}
		}
		
		int sum_a, sum_b;
		sum_a = sum_b = 0;

		for (int i = 0;i < vec.size();i++) {
			for (int j = 0;j < vec.size();j++) {
				if (i == j)
					continue;
				sum_a += map[vec[i]][vec[j]];
			}
		}
		for (int i = 0;i < opp.size();i++) {
			for (int j = 0;j < opp.size();j++) {
				if (i == j)
					continue;
				sum_b += map[opp[i]][opp[j]];
			}
		}
		mm = min(mm, abs(sum_a - sum_b));

		opp.clear();
		return;
	}

	for (int i = idx;i < n;i++) {
		if (!visited[i]) {
			visited[i] = 1;
			vec.push_back(i);
			go(i+1, dep + 1);
			vec.pop_back();
			visited[i] = 0;
		}
	}

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			cin >> map[i][j];
		}
	}
	go(1, 0);

	cout << mm;

}