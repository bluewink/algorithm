/*
1890 ����

1�� �ñ�: �ܼ� dfs -> �ð� �ʰ�
2�� �ñ�: dp�� �����Ϸ� ������ �� �ȵ�...

�޸������̼��� �����غ���. Ǯ�� ������ �ִ� �� ����.
+ ���ǻ��� : �������� 2^63-1�� �̱� ������ long long�� ����ؾ���.
�Լ��� return ���� int�� �ƴ� long long�� �Ǿ����!

*/


#include <iostream>
using namespace std;
int board[101][101];

long long dp[101][101];
int n;
//�Ʒ� ������
int dx[2] = { 0,1 };
int dy[2] = { 1,0 };
long long dfs(int px, int py) {
	
	if (px == n - 1 && py == n - 1) {
		//����
		return 1;
	}
	//�̹� �������� ������ �ִٸ�, �ٷ� ����.
	if (dp[py][px] != 0) {
		return dp[py][px];
	}
	//���� ������ ���� ���̶��, ����� ���ش�.
	int nx, ny;
	for (int i = 0;i < 2;i++) {
		//board�� 0�� ��� ����ó��
		if (board[py][px] == 0) {
			return dp[py][px];
		}
		nx = px + board[py][px] * dx[i];
		ny = py + board[py][px] * dy[i];

		//DP. dp[i][j] : (i,j)���� �Ʒ��� �� �� ����� �� + (i,j)���� ���������� �� �� ����� ��
		if (0 <= nx && nx <= n - 1 && 0 <= ny && ny <= n - 1) {
			dp[py][px] += dfs(nx, ny);
		}

	}
	//����� ��� return.
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
	//top-down ����̱� ������ dp[0][0]�� ���� ������� ��� �ִ�.
	cout << dp[0][0];
	
	return 0;
}