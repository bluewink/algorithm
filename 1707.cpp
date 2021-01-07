/*
1���õ� : dfs �������� origin���� �ΰ� cyclic ���� üũ
2���õ� : odd cyclic ���� ���� üũ
�� ����� O( V*(V+E) ) �̹Ƿ� �ð� �ʰ��� ����.
��� ������ ���� dfs�� �������� ��������..
��ĥ�ϱ�� Ǯ��� �Ѵ�.
�� ������ �湮�ϸ鼭 �� ���� ������ �����ư��� ��ĥ�Ѵ�.
���� � ������ �̹� �湮�ߴµ� �ڽŰ� ���� �����̶�� �̺� �׷����� �� �� ����.
�ð� ���⵵ : O(V+E)
*/

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> graph[20001];
int color[20001];


int flag = 0;

void dfs(int cur, int dep) {
	//1:red 2:blue
	if (dep == 0)	//���� ��� red��
		color[cur] = 1;

	for (int next : graph[cur]) {
		if (color[next] && color[next] == color[cur]) {
			flag = -1;
			return;
		}
		if (!color[next]) {
			//���� �湮�� ���ߴٸ�
			color[next] = color[cur] == 1 ? 2 : 1;
			dfs(next, dep + 1);
		}
		
	}
	return;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int tn, vn,en, src, dest, res;
	cin >> tn;

	while (tn--) {
		for (int i = 0;i <= 20000;i++) {
			graph[i].clear();
		}
		memset(color, 0, sizeof(color));
		cin >> vn >> en;
		for (int i = 0;i < en;i++) {
			cin >> src >> dest;
			graph[src].push_back(dest);
			graph[dest].push_back(src);
			
		}
		res = 0;
		for (int i = 1;i <= vn;i++) {
			flag = 0;
			if (!color[i]) {
				dfs(i, 0);
			}
			if (flag == -1) {
				cout << "NO" << '\n';
				res = -1;
				break;
			}
		}
		if (res == -1)
			continue;
		cout << "YES" << '\n';
	}


	return 0;
}