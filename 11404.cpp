#include <iostream>

/*
	플루이드 알고리즘.
	모든 vertex로의 최소 비용을 구함.

	풀었던 문제지만 재채점 되면서 오답 처리되었다.
	풀고나니 INF값을 100,001로 너무 작게 잡았다.
	도시 개수 * 최대 cost = 100 * 100,000 = 10,000,000 이상으로 inf를 잡아줘야한다.
	*/
using namespace std;
int vn,en;

int map[105][105];
int dist[105][105];
const int INF = 987654321;
int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> vn >> en;
	int src, dest, cost;
	for (int i = 1;i <= vn;i++) {
		for (int j = 1;j <= vn;j++) {
			map[i][j] = INF;
			if (i == j)
				map[i][j] = 0;
		}
	}

	for (int i = 0;i < en;i++) {
		cin >> src >> dest >> cost;
		if(map[src][dest] == INF)
			map[src][dest] = cost;
		else if(map[src][dest] > cost)
			map[src][dest] = cost;
	}
	


	for (int k = 1;k <= vn;k++) {

		for (int i = 1;i <= vn;i++) {

			for (int j = 1;j <= vn;j++) {
				if (map[i][j] > map[i][k] + map[k][j]) {
					map[i][j] = map[i][k] + map[k][j];
				}

			}
		}
	}

	for (int i = 1;i <= vn;i++) {
		for (int j = 1;j <= vn;j++) {
			if (map[i][j] == INF)
				cout << 0 << " ";
			else
				cout << map[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}