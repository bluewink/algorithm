
/* ġ��

	�߸��� Ǯ��
	1. �� ������ �������� �����¿츦 ���ʱ��� �˻������� ġ� ������ ���� �����̶�� ����.
	2. 1��ó�� �����ϸ� �ո� �����ӿ��� ���� �����̶�� �Ǵ��� �� ����.

	���� �������� ��� �� �� ������?
	������ ��ȯ : �ܺ� ���⸦ �������� ��������! ������ �ܺ� ����κ��� BFS Ȥ�� DFS�� ���� �����ϴٸ� �� ������ �ܺ� ������ �ո� ������ �ȴ�.
	���� BFS�� �̿��� ���� ���� ���θ� Ȯ���Ѵ�!


*/

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;


int wid, hgt;
int map[101][101];
int status[101][101];
int visited[101][101];
//�����¿�
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0, 0 };
queue <pair<int, int> > q;

bool checkFourSide(int xx, int yy) {
	int nx, ny;
	int cnt = 0;
	for (int i = 0;i < 4;i++) {
		nx = xx + dx[i];
		ny = yy + dy[i];
		//ġ� ����, ���������� �ʴٸ�
		if (map[ny][nx] == 0 && visited[ny][nx] ==1) {
			cnt++;
		}
	}
	if (cnt >= 2) {
		//����� ġ��
		return true;
	}
	return false;
}

void checkSurround(int xx, int yy) {

	q.push({ yy,xx });
	int cx, cy;
	int nx, ny;
	visited[yy][xx] = 1;
	while (!q.empty()) {
		cx = q.front().second;
		cy = q.front().first;
	
		q.pop();
		for (int i = 0;i < 4;i++) {
			nx = cx + dx[i];
			ny = cy + dy[i];
			if (0<=nx && nx<wid && 0<=ny && ny<hgt && !visited[ny][nx] && map[ny][nx]==0) {
				visited[ny][nx] = 1;
				//�ܺ� ����� ��� �ִ�.
				q.push({ ny,nx });
			}
		}

	}

}



int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int leftCheese = 0;

	cin >> hgt >> wid;
	for (int r = 0;r < hgt;r++) {
		for (int c = 0;c < wid;c++) {
			cin >> map[r][c];
			if (map[r][c] == 1) {
				leftCheese++;
			}
		}
	}
	int ans = 0;
	if (!leftCheese) {
		cout << ans;
		return 0;
	}
	while (1) {
		//status �ʱ�ȭ
		for (int r = 0;r < hgt;r++) {
			for (int c = 0;c < wid;c++) {
				status[r][c] = 0;
				visited[r][c] = 0;
			}
		}

		//ġ��� �ѷ��׿� �ִ��� üũ
		checkSurround(0, 0);

		for (int r = 0;r < hgt;r++) {
			for (int c = 0;c < wid;c++) {
				if (map[r][c] == 1) {
					if (checkFourSide(c, r)) {
						//����� ġ��
						status[r][c] = -1;
					}
				}
			}
		}
		leftCheese = 0;
		for (int r = 0;r < hgt;r++) {
			for (int c = 0;c < wid;c++) {
				if (status[r][c] == -1) {
					//ġ�� ���̱�
					map[r][c] = 0;
				}
				
				if (map[r][c] == 1) {
					leftCheese++;
				}
			}
		}
		ans++;
		if (leftCheese == 0) {
			break;
		}
	}
	cout << ans;

	return 0;
}