#include <iostream>

using namespace std;
int DP[100001];
int dp[100001][2];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	dp[0][0] = dp[0][1] = 1;
	DP[0] = 3;
	dp[1][0] = dp[1][1] = 2;
	DP[1] = 7;
	
	for (int i = 2;i < n;i++) {
		dp[i][0] = dp[i][1] = dp[i - 1][1] + DP[i - 2];
		DP[i] = (dp[i][0] + dp[i][1] + DP[i - 1]) % 9901;
	}
	cout << DP[n-1];

	return 0;
}