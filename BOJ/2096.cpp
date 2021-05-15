/*
	��������
	
	dp Ȱ��
	
	�޸��ʰ�...
	��� input�� ��Ƶ� �ʿ䰡 ����,
	min_dp[3], max_dp[3] 2���� �迭�̸� ����ϴ�.
	�׸��� �� �迭�� 3���ۿ� ���� �ʱ� ������
	input[3]���� �α⺸��
	x,y,z�� �޴� ���� ���� �����ϴ�.

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
				//Ȧ��
				cin >> score[1][j];
			}
			else {
				//¦��
				cin >> score[0][j];
			}
		}
		if (i == 0)
			continue;

		if (i % 2 == 1) {
			//Ȧ��
			max_dp[1][0] = max(max_dp[0][0], max_dp[0][1]) + score[1][0];
			max_dp[1][1] = max(max(max_dp[0][0], max_dp[0][1]), max_dp[0][2]) + score[1][1];
			max_dp[1][2] = max(max_dp[0][1], max_dp[0][2]) + score[1][2];
			min_dp[1][0] = min(min_dp[0][0], min_dp[0][1]) + score[1][0];
			min_dp[1][1] = min(min(min_dp[0][0], min_dp[0][1]), min_dp[0][2]) + score[1][1];
			min_dp[1][2] = min(min_dp[0][1], min_dp[0][2]) + score[1][2];
		}
		else {
			//¦��
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