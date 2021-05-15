/*
	숨바꼭질 3

	첫 시도: 단순 bfs + 거리값이 적을 시 방문하도록 조건 추가
	-> 메모리 초과

	해결 : dijkstra.
	간선마다 cost가 일정하지 않을 경우, bfs가 아닌 다익스트라를 먼저 떠올리자!
	+ pq는 기본적으로 max_heap이란 걸 간과해서 시간이 더 걸림.


*/


#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int src, dest;
const int INF = 987654321;
priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
int visited[100001];
int cost[100001];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> src >> dest;

	fill(cost, cost + 100001, INF);
	
	cost[src] = 0;
	pq.push({ 0,src });

	while (!pq.empty()) {
		int cur;
		do {
			cur = pq.top().second;
			pq.pop();
			

		} while (!pq.empty() && visited[cur]);

		if (visited[cur])
			break;

		visited[cur] = 1;

		int next = 2 * cur;
		if (0 <= next && next <= 100000) {
			if (cost[next] > cost[cur] ) {
				cost[next] = cost[cur];
				pq.push({ cost[next],next });
			}
		}

		next = cur + 1;
		if (0 <= next && next <= 100000) {
			if (cost[next] > cost[cur] + 1) {
				cost[next] = cost[cur] + 1;
				pq.push({ cost[next],next });
			}
		}

		next = cur - 1;
		if (0 <= next && next <= 100000) {
			if (cost[next] > cost[cur] + 1) {
				cost[next] = cost[cur] + 1;
				pq.push({ cost[next],next });
			}
		}
	}

	cout << cost[dest];

	return 0;
}