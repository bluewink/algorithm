#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int src, dest;
const int INF = 987654321;
priority_queue<pair<int, int> > pq;
int visited[100001];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> src >> dest;

	while (!pq.empty()) {

		int cur;
		do {
			cur = pq.top().second;
			pq.pop();
		} while (!pq.empty() && visited[cur]);

	}


	return 0;
}