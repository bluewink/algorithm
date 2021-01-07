/*
1차시도 : dfs 시작점을 origin으로 두고 cyclic 여부 체크
2차시도 : odd cyclic 존재 여부 체크
위 방법은 O( V*(V+E) ) 이므로 시간 초과가 난다.
모든 정점에 대해 dfs를 적용하지 않으려면..
색칠하기로 풀어야 한다.
각 정점을 방문하면서 두 가지 색깔을 번갈아가며 색칠한다.
만약 어떤 정점을 이미 방문했는데 자신과 같은 색깔이라면 이분 그래프가 될 수 없다.
시간 복잡도 : O(V+E)
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
	if (dep == 0)	//시작 노드 red로
		color[cur] = 1;

	for (int next : graph[cur]) {
		if (color[next] && color[next] == color[cur]) {
			flag = -1;
			return;
		}
		if (!color[next]) {
			//아직 방문을 안했다면
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