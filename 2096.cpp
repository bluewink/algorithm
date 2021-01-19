/*
	내려가기
	
	dp 활용
	
	메모리초과...
	모든 input을 담아둘 필요가 없이,
	min_dp[3], max_dp[3] 2개의 배열이면 충분하다.
	그리고 각 배열이 3개밖에 되지 않기 때문에
	input[3]으로 두기보다
	x,y,z로 받는 것이 더욱 간편하다.

*/

#include <iostream>
#include <algorithm>
using namespace std;
int score[2][3];
int max_dp[2][3];
int min_dp[2][3];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < 3;j++) {
			if (i == 0) {
				cin >> score[i][j];
				max_dp[0][j] = min_dp[0][j] = score[0][j];
				continue;
			}
			if (i % 2 == 1) {
				//홀수
				cin >> score[1][j];
			}
			else {
				//짝수
				cin >> score[0][j];
			}
		}
		if (i == 0)
			continue;

		if (i % 2 == 1) {
			//홀수
			max_dp[1][0] = max(max_dp[0][0], max_dp[0][1]) + score[1][0];
			max_dp[1][1] = max(max(max_dp[0][0], max_dp[0][1]), max_dp[0][2]) + score[1][1];
			max_dp[1][2] = max(max_dp[0][1], max_dp[0][2]) + score[1][2];
			min_dp[1][0] = min(min_dp[0][0], min_dp[0][1]) + score[1][0];
			min_dp[1][1] = min(min(min_dp[0][0], min_dp[0][1]), min_dp[0][2]) + score[1][1];
			min_dp[1][2] = min(min_dp[0][1], min_dp[0][2]) + score[1][2];
		}
		else {
			//짝수
			max_dp[0][0] = max(max_dp[1][0], max_dp[1][1]) + score[0][0];
			max_dp[0][1] = max(max(max_dp[1][0], max_dp[1][1]), max_dp[1][2]) + score[0][1];
			max_dp[0][2] = max(max_dp[1][1], max_dp[1][2]) + score[0][2];
			min_dp[0][0] = min(min_dp[1][0], min_dp[1][1]) + score[0][0];
			min_dp[0][1] = min(min(min_dp[1][0], min_dp[1][1]), min_dp[1][2]) + score[0][1];
			min_dp[0][2] = min(min_dp[1][1], min_dp[1][2]) + score[0][2];
		}
	}
	
	int idx = (n-1)%2;
	cout << max(max(max_dp[idx][0], max_dp[idx][1]), max_dp[idx][2]);
	cout << " " << min(min(min_dp[idx][0], min_dp[idx][1]), min_dp[idx][2]);
	return 0;
}