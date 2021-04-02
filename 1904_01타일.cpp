#include <iostream>
using namespace std;
const int MOD = 15746;
int dp[1000001];
int main() {

	int n;
	cin >> n;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3;i <= n;i++) {
		dp[i] = (dp[i - 2] + dp[i - 1]) % MOD;
	}
	cout << dp[n];

	return 0;
}