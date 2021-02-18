#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int r, c, t;
int map[51][51], tmp[51][51];
vector<pair<int, int>> robot;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

void move(int yy, int xx,int dir) {
	int nx = xx + dx[dir];
	int ny = yy + dy[dir];
	
	if (map[ny][nx] == -1) {
		tmp[ny][nx] = -1;
		return;
	}
	if (map[yy][xx] == -1) {
		tmp[ny][nx] = 0;
	}
	else
		tmp[ny][nx] = map[yy][xx];
	
	//map[ny][nx] = map[yy][xx];
}

void dist() {

	memset(tmp, 0, sizeof(tmp));
	//Ȯ��
	for (int y = 1;y <= r;y++) {
		for (int x = 1;x <= c;x++) {
			if (map[y][x] > 0) {
				int dist_cnt = 0;
				for (int i = 0;i < 4;i++) {
					int nx = x + dx[i];
					int ny = y + dy[i];
					int dist_value = map[y][x] / 5;
					
					if (1 <= nx && nx <= c && 1 <= ny && ny <= r) {
						if (map[ny][nx] == -1)
							continue;
						tmp[ny][nx] +=  dist_value;
						dist_cnt++;
					}
				}
				tmp[y][x] = tmp[y][x] + (map[y][x]-(map[y][x] / 5)*dist_cnt);
			}

		}
	}

	for (int y = 1;y <= r;y++) {
		for (int x = 1;x <= c;x++) {
			
			if (map[y][x] == -1) {
				continue;
			}
			map[y][x] = tmp[y][x];
		}
	}

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c >> t;
	for (int y = 1;y <= r;y++) {
		for (int x = 1;x <= c;x++) {
			cin >> map[y][x];
			if (map[y][x] == -1) {
				robot.push_back({ y,x });
				//robot[0] : top, robot[1]: bottom
			}
		}
	}

	while (t--) {

		dist();
		//�����¿� 0123
		memset(tmp, 0, sizeof(tmp));
		for (int y = 1;y <= r;y++) {
			for (int x = 1;x <= c;x++) {
				if (x == 1) {
					//1��
					if (y <= robot[0].first) {
						if (y == robot[0].first) {
							//��
							move(y, x, 3);
						}
						else
							move(y, x, 1);	//�Ʒ�
					}
					else {
						if (y == robot[1].first) {
							//��
							move(y, x, 3);
						}
						else
							move(y, x, 0); //��
					}
				}
				else if (x == c) {
					//�� ������ ��
					if (y <= robot[0].first) {
						//����
						if (y == 1) {
							move(y, x, 2); //��
						}
						else
							move(y, x, 0); //��
					}
					else {
						//�Ʒ���
						if (y == r) {
							//��������
							move(y, x, 2);
						}
						else
							move(y, x, 1); //��
					}
				}
				else if (y == robot[0].first || y == robot[1].first) {
					//����������
					move(y, x, 3);

				}
				else if (y == 1 || y == r) {
					//��������
					move(y, x, 2);
					
				}
				else tmp[y][x] = map[y][x];
			}

		}

		for (int y = 1;y <= r;y++) {
			for (int x = 1;x <= c;x++) {
				if (map[y][x] == -1) {
					continue;
				}
				map[y][x] = tmp[y][x];
			}
		}

	}

	int sum = 0;
	for (int y = 1;y <= r;y++) {
		for (int x = 1;x <= c;x++) {
			sum += map[y][x];
		}
	}
	
	cout << sum+2;
}