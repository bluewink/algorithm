/*
	소요시간 : 1시간 28분...

	5번의 시행착오.
	빈 칸이 있으면 벽을 만날 때까지 이동해야 하는데, 무조건 한칸씩 움직이는 걸로 구현...
	후자로 구현한뒤 코드를 수정하니 예외가 많이 발생했다.

	코드 전 풀이 구상이 얼마나 중요한지 보여주는 예.
	그래도 예외처리를 혼자서 다 해내서 뿌듯하다.

	반복되는 코드가 많은데 나중에 리팩토링 해보자.
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
	case 0://위로 이동
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
				
				//비어 있으면
				if (!board[nr][nc]) {
					//이동
					board[nr][nc] = board[r][c];
					board[r][c] = 0;
					merged[nr][nc] = merged[r][c];
					merged[r][c] = 0;
				}
				else {
					//이미 있으면
					if (board[nr][nc] == board[r][c]) {
						//값이 같으면
						if (merged[nr][nc]) {
							//합쳐질 수 없음
							nr -= dy[dir]; nc -= dx[dir];
							if (nr == r && c == nc)
								continue;
							board[nr][nc] = board[r][c];
							board[r][c] = 0;
							merged[nr][nc] = merged[r][c];
							merged[r][c] = 0;
						}
						else {
							//합쳐질 수 있음
							board[nr][nc] = board[r][c] * 2;
							board[r][c] = 0;
							merged[nr][nc] = 1;
						}
					}
					else {
						//값이 다르면 -> 이동 불가
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
		//아래로 이동 
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
				//비어 있으면
				if (!board[nr][nc]) {
					//이동
					board[nr][nc] = board[r][c];
					board[r][c] = 0;
					merged[nr][nc] = merged[r][c];
					merged[r][c] = 0;
				}
				else {
					//이미 있으면
					if (board[nr][nc] == board[r][c]) {
						//값이 같으면
						if (merged[nr][nc]) {
							//합쳐질 수 없음
							nr -= dy[dir]; nc -= dx[dir];
							if (nr == r && c == nc)
								continue;
							board[nr][nc] = board[r][c];
							board[r][c] = 0;
							merged[nr][nc] = merged[r][c];
							merged[r][c] = 0;
						}
						else {
							//합쳐질 수 있음
							board[nr][nc] = board[r][c] * 2;
							board[r][c] = 0;
							merged[nr][nc] = 1;
						}
					}
					else {
						//값이 다르면 -> 이동 불가
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
		//왼쪽으로 이동
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
				//비어 있으면
				if (!board[nr][nc]) {
					//이동
					board[nr][nc] = board[r][c];
					board[r][c] = 0;
					merged[nr][nc] = merged[r][c];
					merged[r][c] = 0;
				}
				else {
					//이미 있으면
					if (board[nr][nc] == board[r][c]) {
						//값이 같으면
						if (merged[nr][nc]) {
							//합쳐질 수 없음
							nr -= dy[dir]; nc -= dx[dir];
							if (nr == r && c == nc)
								continue;
							board[nr][nc] = board[r][c];
							board[r][c] = 0;
							merged[nr][nc] = merged[r][c];
							merged[r][c] = 0;
						}
						else {
							//합쳐질 수 있음
							board[nr][nc] = board[r][c] * 2;
							board[r][c] = 0;
							merged[nr][nc] = 1;
						}
					}
					else {
						//값이 다르면 -> 이동 불가
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
		//오른쪽으로 이동
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
				//비어 있으면
				if (!board[nr][nc]) {
					//이동
					board[nr][nc] = board[r][c];
					board[r][c] = 0;
					merged[nr][nc] = merged[r][c];
					merged[r][c] = 0;
				}
				else {
					//이미 있으면
					if (board[nr][nc] == board[r][c]) {
						//값이 같으면
						if (merged[nr][nc]) {
							//합쳐질 수 없음
							nr -= dy[dir]; nc -= dx[dir];
							if (nr == r && c == nc)
								continue;
							board[nr][nc] = board[r][c];
							board[r][c] = 0;
							merged[nr][nc] = merged[r][c];
							merged[r][c] = 0;
						}
						else {
							//합쳐질 수 있음
							board[nr][nc] = board[r][c] * 2;
							board[r][c] = 0;
							merged[nr][nc] = 1;
						}
					}
					else {
						//값이 다르면 -> 이동 불가
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
		//최대값 찾기, 원상복구
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