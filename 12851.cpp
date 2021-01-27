/*

	���ٲ���2

	bfs ����.

	�ּ� ��� �������� ���� ���� ��������.
	visited�� ���� ������ �޸� �ʰ��� ���� visited�� ���� �ߺ��Ǵ� ������ ī��Ʈ�� �� ����...

	�ذ� : queue���� �̰� ���� visited�� ǥ�ø� �Ѵ�.
	�ߺ��Ǿ� ���� ��찡 ��������, *2 ��� �̵��ϴ� ��찡 �� ���� �ʱ� ������ �޸� �ʰ��� �߻����� �ʴ´�.
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