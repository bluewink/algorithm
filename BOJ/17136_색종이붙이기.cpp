#include <iostream>
#include <algorithm>
using namespace std;

/*
	~17:40 ����.
	����...

	���ѷ����� ����.

	for loop �Ʒ��� return�� ������ ������ �ذ�Ǿ���.
	�� 

*/
int map[11][11];
int card_cnt[5];
int visited[11][11];
int mm = 987654321;
int covered, target;
void fill_map(int px, int py, int len, int opt) {
	for (int yy = py;yy <= py + len;yy++) {
		for (int xx = px;xx <= px + len;xx++) {
			if(opt)	//fill
				visited[yy][xx] = 1;
			else {
				visited[yy][xx] = 0;
			}
		}
	}
}

bool check_cover(int px, int py, int len) {
	//len : ���� -1 
	if (px + len >= 10 || py + len >= 10) {
		return false;
	}
	for (int yy = py;yy <= py+len;yy++) {
		for (int xx = px;xx <= px+len;xx++) {
			if (!map[yy][xx] || visited[yy][xx])
				return false;
		}
	}
	return true;
}

void go(int px, int py) {
	//cout << "called!" << endl;
	if (covered == target) {
		int sum = 0;
		for (int i = 0;i <= 4;i++) {
			sum += card_cnt[i];
		}
		mm = min(mm, sum);
		return;
	}

	for (int yy = py;yy < 10;yy++) {
		for (int xx = 0;xx < 10;xx++) {
			if (map[yy][xx] && !visited[yy][xx]) {
				for (int l = 4;l >= 0;l--) {
					if (card_cnt[l] < 5) {
						if (check_cover(xx, yy, l)) {
							
							card_cnt[l]++;
							covered += (l + 1)*(l + 1);
							fill_map(xx, yy, l, 1);
							go(xx + l + 1, yy);
							//go(xx, yy);
							fill_map(xx, yy, l, 0);
							covered -= (l + 1)*(l + 1);
							card_cnt[l]--;
						}
					}
					
				}
				// ��� ĭ�� ������ϱ� ������, 5,4,3,2,1 ���̸� �õ��� �Ŀ��� �����Ű�� �ȴ�!
				return;
				
			}
			
		}
	}

	
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0;i < 10;i++) {
		for (int j = 0;j < 10;j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				target++;
			}
		}
	}
	go(0, 0);
	if (mm == 987654321)
		cout << -1;
	else
		cout << mm;

	return 0;
}