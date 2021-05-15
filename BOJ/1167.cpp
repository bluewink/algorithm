
/*
	1167 Ʈ���� ����.

	1. ������ �߸� ����
	1,2,3,4,5 ������ �Է��� ���´ٴ� ������ ����...

	2. �˰��� Ʋ���� ����.
	1�� ��忡�� ���� ����ϴ� ���� ���� �Ÿ��� �� ���̶� ����������, �߰��� �ִ� ���- �߰��� �ִ� ��� ���� �Ÿ��� �ִ� �Ÿ��� �� ���� �ִ�.

	sol : Ʈ���� ���� ���ϴ� �˰����� �̿��Ѵ�
	(1) ������ �� ������ ���� �Ÿ��� �� ��(v1)�� ã�´�.
	(2) v1���κ��� ���� �Ÿ��� �� ��(v2)�� ã�´�.
	v1-v2�� �Ÿ��� Ʈ���� ������ �ȴ�.
	
	�� sol�� dfs 2�� ������ ����.
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
		//���� ���
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
	//1. ������ �� ������ ���� �� �Ÿ��� �ִ� �� -> v1
	dfs(1, 0);
	memset(visited, 0, sizeof(visited));
	ans = -1;
	//2. v1���� ���� �� �Ÿ��� �ִ� ��.
	dfs(max_dist_node, 0);

	cout << ans;

	return 0;
}