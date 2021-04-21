/*
	���θ� ��� tree DP

	ó���� ��ü �̰� �� DP�ΰ� �;��µ�
	Ǯ�̸� ���� ���� DP�� ����ó�� ��������.


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
		//�� node�� early adapter
		for (int next : child[pos]) {
			sum += min(SNS(next, 1), SNS(next, 0));
		}
		sum++;
	}
	else {
		//�� node�� early adapter�� �ƴϸ�
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