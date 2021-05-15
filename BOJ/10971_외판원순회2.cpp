#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int graph[11][11], visited[11];
vector<int> candi;	//cost;
int mm = 987654321;
void go(int dep, int cur, int org) {
	if (dep == n) {
		int sum = 0;
		for (int x : candi) {
			sum += x;
		}
		mm = min(mm, sum);
		return;
	}

	for (int i = 0;i < n;i++) {
		if (!graph[cur][i] || visited[i])	
			continue;
		if (dep < n - 1 && i == org)	//마지막 전에 시작 노드를 방문하지 못하게 함
			continue;
		candi.push_back(graph[cur][i]);	
		visited[i] = 1;
		go(dep + 1, i, org);
		visited[i] = 0;
		candi.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	for (int i = 0;i < n;i++) {
		for(int j=0;j<n;j++){
			cin >> graph[i][j];
		}
	}
	for (int i = 0;i < n;i++) {
		go(0, i, i);
	}
	cout << mm;
	return 0;
}