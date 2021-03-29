#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
	bruteforce -> �ð��ʰ�

	[i][j] -> i: i��°, j: ������� ����
	dp[i][j] : i��° ���Ǳ��� �ִ� ��ġ��

	dp[i][j] = max(dp[i-1][j]+ dp[i-1][j-weight[i]] + value[i])
	

*/
int n, k;
int dp[101][100001];
vector<int> wgt, val;
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	int w, v;
	for (int i = 0;i < n;i++) {
		cin >> w >> v;
		wgt.push_back(w);
		val.push_back(v);
	}

	for (int i = 0;i < n;i++) {
		for (int j = 0;j <= k;j++) {
			if (i == 0) {
				if (j == wgt[i])
					dp[i][j] = val[i];
				continue;
			}
			if (j - wgt[i] < 0) {
				dp[i][j] = dp[i - 1][j];
				continue;
			}
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - wgt[i]] + val[i]);

		}
	}
	int MM = -1;
	for (int j = 0;j <= k;j++) {
		MM = max(MM, dp[n - 1][j]);
	}
	cout << MM;
	return 0;
}