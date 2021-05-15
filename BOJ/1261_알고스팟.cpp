/*
	인접행렬로 다익스트라 구현하기.

	(주의) cin.tie(0)
	ios::sync_with_stdio(0)
	를 선언하고
	cin,cout / scanf,printf 를 함께 사용하면 안 된다...
*/

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int map[101][101], dist[101][101], visited[101][101];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
typedef pair<int, int> pi;
typedef pair<int, pair<int, int>> pii;
priority_queue<pii, vector<pii>, greater<>> pq;
const int INF = 987654321;
int main() {

	int wid, hgt, px,py;
	
	cin >> wid >> hgt;
	for (int i = 1;i <= hgt;i++) {
		for (int j = 1;j <= wid;j++) {
			scanf("%1d", &map[i][j]);
			dist[i][j] = INF;
		}
	}
	dist[1][1] = 0;
	pq.push({ 0,{1,1} });

	while (!pq.empty()) {
		do {
			px = pq.top().second.second;
			py = pq.top().second.first;
			pq.pop();
		} while (visited[py][px] && !pq.empty());
		if (visited[py][px])
			break;
		visited[py][px] = 1;
		for (int dir = 0;dir < 4;dir++) {
			int nx = px + dx[dir];
			int ny = py + dy[dir];
			if (1 <= nx && nx <= wid && 1 <= ny && ny <= hgt) {
				if (map[ny][nx]) {
					if (dist[ny][nx] > dist[py][px] + 1) {
						dist[ny][nx] = dist[py][px] + 1;
						pq.push({ dist[ny][nx], { ny,nx } });
					}
				}
				else {
					if (dist[ny][nx] > dist[py][px]) {
						dist[ny][nx] = dist[py][px];
						pq.push({ dist[ny][nx], { ny,nx } });
					}
				}
			}
		}
	}

	cout << dist[hgt][wid];
}