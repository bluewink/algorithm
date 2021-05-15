/*
1890 점프

1차 시기: 단순 dfs -> 시간 초과
2차 시기: dp를 도입하려 했지만 잘 안됨...

메모이제이션을 공부해보자. 풀이 패턴이 있는 것 같음.
+ 주의사항 : 가짓수가 2^63-1개 이기 때문에 long long을 사용해야함.
함수의 return 값도 int가 아닌 long long이 되어야함!

*/


#include <iostream>
using namespace std;
int board[101][101];

long long dp[101][101];
int n;
//아래 오른쪽
int dx[2] = { 0,1 };
int dy[2] = { 1,0 };
long long dfs(int px, int py) {
	
	if (px == n - 1 && py == n - 1) {
		//도착
		return 1;
	}
	//이미 가짓수가 결정돼 있다면, 바로 종료.
	if (dp[py][px] != 0) {
		return dp[py][px];
	}
	//아직 가보지 못한 곳이라면, 계산을 해준다.
	int nx, ny;
	for (int i = 0;i < 2;i++) {
		//board가 0일 경우 예외처리
		if (board[py][px] == 0) {
			return dp[py][px];
		}
		nx = px + board[py][px] * dx[i];
		ny = py + board[py][px] * dy[i];

		//DP. dp[i][j] : (i,j)에서 아래로 갈 때 경우의 수 + (i,j)에서 오른쪽으로 갈 때 경우의 수
		if (0 <= nx && nx <= n - 1 && 0 <= ny && ny <= n - 1) {
			dp[py][px] += dfs(nx, ny);
		}

	}
	//계산한 결과 return.
	return dp[py][px];
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
	dfs(0, 0);
	//top-down 방식이기 때문에 dp[0][0]에 최종 결과값이 들어 있다.
	cout << dp[0][0];
	
	return 0;
}