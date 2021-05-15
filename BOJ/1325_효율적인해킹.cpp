#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int n, m;
vector<int> graph[10001];
int visited[10001];
int cnt = 0;
int MM = -1;
vector<pair<int, int>> candi;
void dfs(int cur) {
	cnt++;
	visited[cur] = 1;
	for (int next : graph[cur]) {
		if (!visited[next]) {
			dfs(next);
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	int src, dest;
	for (int i = 0;i < m;i++) {
		cin >> dest >> src;
		graph[src].push_back(dest);
	}
	for (int i = 1;i <= n;i++) {
		fill(visited, visited + n+1, 0);
		cnt = 0;
		dfs(i);
		MM = max(MM, cnt);
		candi.push_back({ cnt,i });
	}

	for (pair<int, int> x : candi) {
		if (x.first == MM) {
			cout << x.second << " ";
		}
	}

	return 0;
}