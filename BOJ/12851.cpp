/*

	숨바꼭질2

	bfs 문제.

	최소 경로 가지수를 세는 것이 난제였다.
	visited를 쓰지 않으면 메모리 초과가 나고 visited를 쓰면 중복되는 개수를 카운트할 수 없다...

	해결 : queue에서 뽑고 나서 visited에 표시를 한다.
	중복되어 들어가는 경우가 생기지만, *2 배로 이동하는 경우가 얼마 되지 않기 때문에 메모리 초과가 발생하지 않는다.
	*/


#include <iostream>
#include <queue>
using namespace std;

int src, target, mm;
queue<pair<int,int>> q;
int visited[100001];

int bfs() {
	int cur, cnt,num;
	int next;
	mm = 987654321;
	num = 0;
	q.push({ src,0 });

	while (!q.empty()) {
		cur = q.front().first;
		cnt = q.front().second;
		q.pop();

		visited[cur] = 1;
		
		if (cnt > mm) {
			break;
		}
		if (cur == target) {
			mm = cnt;
			num++;
		}

		next = cur + 1;
		if (next <= 100000 && !visited[next] ) {
			q.push({ next,cnt + 1 });
		}

		next = cur - 1;
		if (0<=next && !visited[next]) {
			q.push({ next,cnt + 1 });
		}

		next = 2 * cur;
		if (next <= 100000 && !visited[next]) {
			q.push({ next,cnt + 1 });
		}
	}

	return num;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> src >> target;
	
	int num = bfs();
	cout << mm << endl << num;


	return 0;
}