/*
	dfs + MST

	��� Ǯ����� �� ���� �˰��� �з��� �ô�.
	MST�� Ǯ� ���� ��� �ٸ� MST ������ ���� Ǯ��ô�.

	DFS�� VERTEX�� �����ϰ�,
	��� �ٸ��� ���ƺ��鼭 EDGE�� �����
	kruskal algorithm���� MST�� ����� ����� ���ߴ�.

	�ּ� ���� ���.. => MST�� ���ø���!
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, pair<int, int>> pii;
int wid, hgt;
int map[11][11], color[11][11];
int island[7];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
vector<pii> edges;
int p[7];

int find(int a) {
	if (p[a] < 0)
		return a;
	p[a] = find(p[a]);
	return p[a];
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return;
	p[a] = b;
}

void make_edge(int sx, int sy) {
	int nx, ny;
	for (int dir = 0;dir < 4;dir++) {
		nx = sx; ny = sy;
		int len = 0;
		while (1) {
			len++;
			nx += dx[dir];
			ny += dy[dir];
			if (nx < 0 || nx >= wid || ny < 0 || ny >= hgt)
				break;
			if (!map[ny][nx])
				continue;
			if (len <= 2) {
				break;
			}
			else {
				edges.push_back({ len-1,{color[sy][sx],color[ny][nx]} });
				break;
			}
		
		}

	}
}

void dfs(int px, int py, int id) {
	
	for (int dir = 0;dir < 4;dir++) {
		int nx = px + dx[dir];
		int ny = py + dy[dir];
		if (0 <= nx && nx < wid && 0 <= ny && ny < hgt) {
			if (!color[ny][nx] && map[ny][nx]) {
				color[ny][nx] = id;
				dfs(nx, ny, id);
			}
		}
	}
	
}
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> hgt >> wid;
	for (int i = 0;i < hgt;i++) {
		for (int j = 0;j < wid;j++) {
			cin >> map[i][j];
		}
	}
	int cnt = 1;
	for (int i = 0;i < hgt;i++) {
		for (int j = 0;j < wid;j++) {
			if (map[i][j] && !color[i][j]) {
				color[i][j] = cnt;
				dfs(j, i, cnt++);
			}
		}
	}

	for (int i = 0;i < hgt;i++) {
		for (int j = 0;j < wid;j++) {
			if(map[i][j])
				make_edge(j, i);
		}
	}
	sort(edges.begin(), edges.end());

	fill(p, p + 7, -1);
	int sum = 0;
	int v_num = cnt-1;
	
	cnt = 0;
	for (pii x : edges) {
		int src = x.second.first;
		int dest = x.second.second;
		if (find(src) == find(dest)) {
			continue;
		}
		//cout << src << " " << dest << " " << x.first << " " << endl;
		sum += x.first;
		cnt++;
		merge(src, dest);
	}
	if (cnt == v_num - 1) {
		cout << sum;
	}
	else {
		cout << -1;
	}
	/*
	for (pii x : edges) {
		cout << x.first << " " << x.second.first << " " << x.second.second << endl;
	}*/
	return 0;
}