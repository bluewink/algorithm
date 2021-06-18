#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
typedef pair<int, int> pi;
vector<pi> graph[1001];
int dist[1001], visited[1001], from[1001];
stack<int> trace;
priority_queue<pi,vector<pi>,greater<> > pq;
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int vn, en;
	cin >> vn >> en;
	int src, dest, cost;
	for (int i = 0;i < en;i++) {
		cin >> src >> dest >> cost;
		graph[src].push_back({ cost,dest });
	}
	cin >> src >> dest;

	fill(dist, dist + 1001, 987654321);
	dist[src] = 0;
	pq.push({ dist[src],src });
	int cur;
	while (!pq.empty()) {
		do {
			cur = pq.top().second;
			pq.pop();
		} while (!pq.empty()&&visited[cur] );

		if (visited[cur])
			break;

		visited[cur] = 1;
		for (pi x : graph[cur]) {
			int next = x.second;
			int cost = x.first;
			if (dist[next] > dist[cur] + cost) {
				dist[next] = dist[cur] + cost;
				pq.push({ dist[next],next });
				//경로 추적
				from[next] = cur;
			}
		}

	}
	cout << dist[dest] << endl;
	cur = dest;
	trace.push(cur);
	while (cur != src) {
		cur = from[cur];
		trace.push(cur);
	}
	cout << trace.size() << endl;
	while (!trace.empty()) {
		cout << trace.top() << " ";
		trace.pop();
	}
	return 0;
}
