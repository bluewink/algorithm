#include <iostream>
using namespace std;
int n;
int dp[7][9];
int main() {

	cin >> n;

	for (int i = 1;i <= 9;i++) {
		dp[1][i] = 1;
		dp[2][i] = i;
	}
	dp[1][1] = 0;

	for (int k = 3;k <= 7;k++) {
		for (int i = 1;i <= 9;i++) {
			for (int j = 1;j <i;j++) {
				dp[k][i] += dp[k - 1][j];
				
				//dp[3][4] = dp[2][1]+dp[2][2]+d[2][3]
			}
		}
	}
	int cnt = 1;
	int a, b;
	int flag = 0;
	for (int i = 1;i <= 9;i++) {
		for (int j = 1;j <= 9;j++) {
			cnt += dp[i][j];
			cout << i << " " << j << " " << dp[i][j] << " " << cnt <<endl;
			if (cnt >= n-1) {
				a = i;
				b = j;
				flag = 1;
				break;
			}
		}
		if (flag)
			break;
	}
	//a자리 맨 앞자리 b
	cout << a << " " << b;


}