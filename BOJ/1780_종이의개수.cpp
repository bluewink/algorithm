#include <iostream>
#include <vector>
using namespace std;

int board[2200][2200];
int n;

int ans[5];	// 0: 0으로만, 1: 1로만, 2: -1로만

void rec(int sx, int sy, int len) {

	int target = board[sy][sx];
	if (len == 1) {
		//base
		if (target == -1)
			ans[2]++;
		else {
			ans[target]++;
		}
		return;
	}
	for (int yy = sy;yy < len + sy;yy++) {
		for (int xx = sx;xx < len + sx;xx++) {

			if (target != board[yy][xx]) {

				for (int i = 0;i < 3;i++) {
					for (int j = 0;j < 3;j++) {

						int next_len = len / 3;
						rec(sx+(next_len*j), sy+(next_len*i), next_len);
					}
				}
				return;
			}

		}
	}
	//다 값이 같은 종이
	if (target == -1)
		ans[2]++;
	else {
		ans[target]++;
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

	rec(0, 0, n);

	cout << ans[2] << endl << ans[0] << endl << ans[1];
	
	return 0;

}