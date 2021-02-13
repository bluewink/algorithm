#include <iostream>
#include <algorithm>
using namespace std;

int hgt, wid;
int map[505][505];

int tx[19][4] = {
	//일자
	{0,1,2,3},{0,0,0,0},
	//밭전
	{0,1,0,1,},
	//fu
	{0,1,2,1},{0,0,1,0},{0,-1,0,1},{0,-1,0,0},
	//리을
	{0,0,1,1},{0,-1,0,-1},{0,1,1,2},{0,1,-1,0},
	//니은
	{0,0,0,1},{0,0,-1,0},{0,1,2,0},{0,1,2,2},{0,1,0,0},{0,1,1,1},{0,0,1,2},{0,-2,-1,0}
};
int ty[19][4] = {
	//일자
	{0,0,0,0},{0,1,2,3},
	//밭전
	{0,0,1,1},
	//fu
	{0,0,0,1},{0,1,1,2},{0,1,1,1},{0,1,1,2},
	//리을
	{0,1,1,2},{0,1,1,2},{0,0,1,1},{0,0,1,1},
	{0,1,2,2},{0,1,2,2},{0,0,0,1},{0,0,0,1},{0,0,1,2},{0,0,1,2},{0,1,1,1},{0,1,1,1}
};


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> hgt >> wid;

	for (int i = 0;i < hgt;i++) {
		for (int j = 0;j < wid;j++) {
			cin >> map[i][j];
		}
	}
	int nx, ny;
	int MM = -1;
	int flag = 0;
	for (int i = 0;i < hgt;i++) {

		for (int j = 0;j < wid;j++) {

			for (int k = 0;k < 19;k++) {
				int sum = 0;
				flag = 0;
				for (int m = 0;m < 4;m++) {
					nx = j + tx[k][m];
					ny = i + ty[k][m];
					
					if (nx >= 0 && nx < wid && ny >= 0 && ny < hgt) {
						sum += map[ny][nx];
					}
					else {
						flag = -1;
						break;
					}
				}
				if (flag != -1) {
					MM = max(MM, sum);
				}
				
			}
		}
	}
	cout << MM;

	return 0;
}