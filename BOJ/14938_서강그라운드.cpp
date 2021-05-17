#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int v_val[101];
int dist[101][101];
const int INF = 987654321;
int MM = -1;
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int vn, m, en;
	cin >> vn >> m >> en;
	for (int i = 1;i <= vn;i++) {
		cin >> v_val[i];
	}
	int src, dest, cost;
	for (int i = 1;i <= vn;i++) {
		for (int j = 1;j <= vn;j++) {
			if (i == j)
				dist[i][j] = 0;
			else
				dist[i][j] = INF;
		}
	}
	for (int i = 0;i < en;i++) {
		cin >> src >> dest >> cost;
		if (src == dest)
			continue;
		if (dist[src][dest] > cost) {
			dist[src][dest] = cost;
			dist[dest][src] = cost;
		}
	}

	for (int k = 1;k <= vn;k++) {
		for (int i = 1;i <= vn;i++) {
			for (int j = 1;j <= vn;j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
	for (int i = 1;i <= vn;i++) {
		int sum = 0;
		for (int j = 1;j <= vn;j++) {
			if (dist[i][j] <= m) {
				sum += v_val[j];
			}
		}
		MM = max(MM, sum);
	}
	cout << MM;

	return 0;
}