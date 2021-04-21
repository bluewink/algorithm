/*
	말로만 듣던 tree DP

	처음엔 대체 이게 왜 DP인가 싶었는데
	풀이를 보고 나니 DP의 정석처럼 느껴진다.


*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
vector<int> graph[1000001], child[1000001];
int visited[1000001], dp[1000001][2];
void dfs(int cur) {
	visited[cur] = 1;
	for (int next : graph[cur]) {
		if (!visited[next]) {
			visited[next] = 1;
			child[cur].push_back(next);
			dfs(next);
		}
	}
}

int SNS(int pos, int check) {
	if (dp[pos][check] != -1) return dp[pos][check];

	int sum = 0;
	if (check) {
		//현 node가 early adapter
		for (int next : child[pos]) {
			sum += min(SNS(next, 1), SNS(next, 0));
		}
		sum++;
	}
	else {
		//현 node가 early adapter가 아니면
		for (int next : child[pos]) {
			sum += SNS(next, 1);
		}
	}
	return dp[pos][check] = sum;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	int src, dest;
	for (int i = 0;i < n - 1;i++) {
		cin >> src >> dest;
		graph[src].push_back(dest);
		graph[dest].push_back(src);
	}
	dfs(1);
	memset(dp, -1, sizeof(dp));
	cout << min(SNS(1, 0), SNS(1, 1));
	return 0;
}