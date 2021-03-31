/*
	�ҿ�ð� : 1�ð� 28��...

	5���� ��������.
	�� ĭ�� ������ ���� ���� ������ �̵��ؾ� �ϴµ�, ������ ��ĭ�� �����̴� �ɷ� ����...
	���ڷ� �����ѵ� �ڵ带 �����ϴ� ���ܰ� ���� �߻��ߴ�.

	�ڵ� �� Ǯ�� ������ �󸶳� �߿����� �����ִ� ��.
	�׷��� ����ó���� ȥ�ڼ� �� �س��� �ѵ��ϴ�.

	�ݺ��Ǵ� �ڵ尡 ������ ���߿� �����丵 �غ���.
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int n;
int board[21][21], tmp_board[21][21];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int merged[21][21];
int MM = -1;
vector<int> move_vec;
void move(int dir) {
	memset(merged, 0, sizeof(merged));
	int nr, nc;
	switch (dir)
	{
	case 0://���� �̵�
		for (int r = 1;r < n;r++) {
			for (int c = 0;c < n;c++) {
				if (!board[r][c])
					continue;
				nc = c + dx[dir]; nr = r + dy[dir];
				while (!board[nr][nc]) {
					if (nr == 0)
						break;
					nc += dx[dir];
					nr += dy[dir];
				}
				
				//��� ������
				if (!board[nr][nc]) {
					//�̵�
					board[nr][nc] = board[r][c];
					board[r][c] = 0;
					merged[nr][nc] = merged[r][c];
					merged[r][c] = 0;
				}
				else {
					//�̹� ������
					if (board[nr][nc] == board[r][c]) {
						//���� ������
						if (merged[nr][nc]) {
							//������ �� ����
							nr -= dy[dir]; nc -= dx[dir];
							if (nr == r && c == nc)
								continue;
							board[nr][nc] = board[r][c];
							board[r][c] = 0;
							merged[nr][nc] = merged[r][c];
							merged[r][c] = 0;
						}
						else {
							//������ �� ����
							board[nr][nc] = board[r][c] * 2;
							board[r][c] = 0;
							merged[nr][nc] = 1;
						}
					}
					else {
						//���� �ٸ��� -> �̵� �Ұ�
						nr -= dy[dir]; nc -= dx[dir];
						if (nr == r && c == nc)
							continue;
						board[nr][nc] = board[r][c];
						board[r][c] = 0;
						merged[nr][nc] = merged[r][c];
						merged[r][c] = 0;
					}

				}

			}
		}
		break;
	case 1:
		//�Ʒ��� �̵� 
		for (int r = n-2;r >=0;r--) {
			for (int c = 0;c < n;c++) {
				if (!board[r][c])
					continue;
				nc = c + dx[dir]; nr = r + dy[dir];
				while (!board[nr][nc]) {
					if (nr == n-1)
						break;
					nc += dx[dir];
					nr += dy[dir];
				}
				//��� ������
				if (!board[nr][nc]) {
					//�̵�
					board[nr][nc] = board[r][c];
					board[r][c] = 0;
					merged[nr][nc] = merged[r][c];
					merged[r][c] = 0;
				}
				else {
					//�̹� ������
					if (board[nr][nc] == board[r][c]) {
						//���� ������
						if (merged[nr][nc]) {
							//������ �� ����
							nr -= dy[dir]; nc -= dx[dir];
							if (nr == r && c == nc)
								continue;
							board[nr][nc] = board[r][c];
							board[r][c] = 0;
							merged[nr][nc] = merged[r][c];
							merged[r][c] = 0;
						}
						else {
							//������ �� ����
							board[nr][nc] = board[r][c] * 2;
							board[r][c] = 0;
							merged[nr][nc] = 1;
						}
					}
					else {
						//���� �ٸ��� -> �̵� �Ұ�
						nr -= dy[dir]; nc -= dx[dir];
						if (nr == r && c == nc)
							continue;
						board[nr][nc] = board[r][c];
						board[r][c] = 0;
						merged[nr][nc] = merged[r][c];
						merged[r][c] = 0;
					}

				}

			}
		}
		break;
	case 2:
		//�������� �̵�
		for (int c = 1;c<n;c++) {
			for (int r = 0;r < n;r++) {
				if (!board[r][c])
					continue;
				nc = c + dx[dir]; nr = r + dy[dir];
				while (!board[nr][nc]) {
					if (nc == 0)
						break;
					nc += dx[dir];
					nr += dy[dir];
				}
				//��� ������
				if (!board[nr][nc]) {
					//�̵�
					board[nr][nc] = board[r][c];
					board[r][c] = 0;
					merged[nr][nc] = merged[r][c];
					merged[r][c] = 0;
				}
				else {
					//�̹� ������
					if (board[nr][nc] == board[r][c]) {
						//���� ������
						if (merged[nr][nc]) {
							//������ �� ����
							nr -= dy[dir]; nc -= dx[dir];
							if (nr == r && c == nc)
								continue;
							board[nr][nc] = board[r][c];
							board[r][c] = 0;
							merged[nr][nc] = merged[r][c];
							merged[r][c] = 0;
						}
						else {
							//������ �� ����
							board[nr][nc] = board[r][c] * 2;
							board[r][c] = 0;
							merged[nr][nc] = 1;
						}
					}
					else {
						//���� �ٸ��� -> �̵� �Ұ�
						nr -= dy[dir]; nc -= dx[dir];
						if (nr == r && c == nc)
							continue;
						board[nr][nc] = board[r][c];
						board[r][c] = 0;
						merged[nr][nc] = merged[r][c];
						merged[r][c] = 0;
					}
				}
			}
		}
		break;
	case 3:
		//���������� �̵�
		for (int c = n-2;c >= 0;c--) {
			for (int r = 0;r < n;r++) {
				if (!board[r][c])
					continue;
				nc = c + dx[dir]; nr = r + dy[dir];
				while (!board[nr][nc]) {
					if (nc == n-1)
						break;
					nc += dx[dir];
					nr += dy[dir];
				}
				//��� ������
				if (!board[nr][nc]) {
					//�̵�
					board[nr][nc] = board[r][c];
					board[r][c] = 0;
					merged[nr][nc] = merged[r][c];
					merged[r][c] = 0;
				}
				else {
					//�̹� ������
					if (board[nr][nc] == board[r][c]) {
						//���� ������
						if (merged[nr][nc]) {
							//������ �� ����
							nr -= dy[dir]; nc -= dx[dir];
							if (nr == r && c == nc)
								continue;
							board[nr][nc] = board[r][c];
							board[r][c] = 0;
							merged[nr][nc] = merged[r][c];
							merged[r][c] = 0;
						}
						else {
							//������ �� ����
							board[nr][nc] = board[r][c] * 2;
							board[r][c] = 0;
							merged[nr][nc] = 1;
						}
					}
					else {
						//���� �ٸ��� -> �̵� �Ұ�
						nr -= dy[dir]; nc -= dx[dir];
						if (nr == r && c == nc)
							continue;
						board[nr][nc] = board[r][c];
						board[r][c] = 0;
						merged[nr][nc] = merged[r][c];
						merged[r][c] = 0;
					}
				}
			}
		}
		break;
	default:
		break;
	}
	
}

void dfs(int dep) {
	if (dep == 5) {
		
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < n;j++) {
				tmp_board[i][j] = board[i][j];
			}
		}

		for (int dir : move_vec) {
			move(dir);
		}
		//�ִ밪 ã��, ���󺹱�
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < n;j++) {
				MM = max(MM, board[i][j]);
				board[i][j] = tmp_board[i][j];
			}
		}
	
		return;
	}

	for (int dir = 0;dir < 4;dir++) {
		move_vec.push_back(dir);
		dfs(dep + 1);
		move_vec.pop_back();
	}

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> board[i][j];
		}
	}
	dfs(0);
	cout << MM;

	return 0;
}