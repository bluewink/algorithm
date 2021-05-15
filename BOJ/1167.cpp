
/*
	1167 트리의 지름.

	1. 문제를 잘못 이해
	1,2,3,4,5 순으로 입력이 들어온다는 보장이 없다...

	2. 알고리즘 틀리게 설정.
	1번 노드에서 가는 출발하는 것이 가장 거리가 길 것이라 생각했지만, 중간에 있는 노드- 중간에 있는 노드 사이 거리가 최대 거리가 될 수도 있다.

	sol : 트리의 지름 구하는 알고리즘을 이용한다
	(1) 임의의 한 점에서 가장 거리가 먼 점(v1)을 찾는다.
	(2) v1으로부터 가장 거리가 먼 점(v2)을 찾는다.
	v1-v2간 거리가 트리의 지름이 된다.
	
	위 sol을 dfs 2번 적용해 구현.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
vector<pair<int,int>> graph[100005];
int visited[100005];
int ans = -1;
int max_dist_node = -1;
void dfs(int cur, int sum) {

	int child_flag = 0;
	visited[cur] = 1;

	for (pair<int, int> next : graph[cur]) {
		
		int next_node = next.first;
		int cur_sum = sum + next.second;
		
		if (!visited[next_node]) {
			child_flag = 1;
			visited[next_node] = 1;
			dfs(next_node, cur_sum);
		}
	}
	if (!child_flag) {
		//말단 노드
		if (ans < sum) {
			ans = sum;
			max_dist_node = cur;
		}
	}

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	int in, cost, v_num;
	for (int i = 0;i < n;i++) {
		cin >> v_num;
		do {
			cin >> in;
			if (in == -1)
				break;
			cin >> cost;
			graph[v_num].push_back({ in,cost });
		} while (in != -1);
		
	}
	//1. 임의의 한 점에서 가장 먼 거리에 있는 점 -> v1
	dfs(1, 0);
	memset(visited, 0, sizeof(visited));
	ans = -1;
	//2. v1에서 가장 먼 거리에 있는 점.
	dfs(max_dist_node, 0);

	cout << ans;

	return 0;
}