/*
	DSLR

	구현 + BFS

	1. rotate 기능 구현이 까다로울 것 같아서 string을 이용.
	2. cmd history 구현을 위해 vector 사용

	위 1,2 번으로 인해 시간초과 발생
	1 -> string을 int로 바꿈. int로도 rotate가 어렵지 않다.
	2 -> parent[]배열을 둬서 역추적.
*/


#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int visited[10001];
int parent[10001];
char cmd[10001];
queue <int> q; 
int doubling(int xx) {
	if (2 * xx > 9999) {
		return (2 * xx) % 10000;
	}
	else {
		return 2 * xx;
	}
}
int minus_one(int xx) {
	if (xx == 0) {
		return 9999;
	}
	else return xx - 1;
}
int rotate_left(int x) {
	int a = x % 10;
	int aa = (x % 100 - a)/10;
	int aaa = (x % 1000 - 10 * aa - a)/100;
	int aaaa = x / 1000;
	return 1000 * aaa + 100 * aa + 10 * a + aaaa;
}
int rotate_right(int x) {
	int a = x % 10;
	int aa = (x % 100 - a) / 10;
	int aaa = (x % 1000 - 10 * aa - a) / 100;
	int aaaa = x / 1000;
	return 1000 * a + 100 * aaaa + 10 * aaa + aa;
}

void bfs(int org, int target) {
	int cur, next;
	visited[org] = 1;
	q.push(org);
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		if (cur == target) {
			while (!q.empty()) {
				q.pop();
			}
			return;
		}
		next = doubling(cur);
		if (!visited[next]) {
			visited[next] = 1;
			cmd[next] = 'D';
			parent[next] = cur;
			q.push(next);
		}

		next = minus_one(cur);
		if (!visited[next]) {
			visited[next] = 1;
			cmd[next] = 'S';
			parent[next] = cur;
			q.push(next);
		}

		next = rotate_left(cur);
		if (!visited[next]) {
			visited[next] = 1;
			cmd[next] = 'L';
			parent[next] = cur;
			q.push(next);
		}

		next = rotate_right(cur);
		if (!visited[next]) {
			visited[next] = 1;
			cmd[next] = 'R';
			parent[next] = cur;
			q.push(next);
		}
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int tn;
	cin >> tn;

	int a, b;
	while (tn--) {
		cin >> a >> b;
		memset(visited, 0, sizeof(visited));
		memset(parent, 0, sizeof(parent));
		memset(cmd, 0, sizeof(cmd));
		bfs(a, b);
		string ans;
		int cur;
		cur = b;
		while (cur != a) {
			ans.push_back(cmd[cur]);
			cur = parent[cur];
		}
		reverse(ans.begin(), ans.end());
		cout << ans << '\n';
	}

	return 0;
}