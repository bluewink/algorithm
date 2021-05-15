
/*
	행렬 제곱 문제
	square and multiply를 이용할 경우 square 연산의 시간 복잡도를 대폭 줄일 수 있다!
	
	시행착오
	mod 연산을 마지막 출력에만 해서 틀렸다.
	중간에 값이 커지면 garbage 값이 들어갈 수 있으니, 연산 중간 중간에 모두 mod를 해준다.

	개선사항
	배열이 아닌 vector를 이용하면 2d array passing, return을 보다 직관적으로 할 수 있다.
*/

#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;
ll mat[6][6];
ll n, b;

ll res[6][6], squ[6][6];

void mat_mul(ll a[][6],ll b[][6], int opt) {
	//opt 1: 제곱, 0: 곱하기
	ll tmp[6][6];
	memset(tmp, 0, sizeof(tmp));
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			for (int k = 0;k < n;k++) {
				tmp[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (opt)
				squ[i][j] = tmp[i][j] % 1000;
			else
				res[i][j] = tmp[i][j] % 1000;
		}
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> b;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> squ[i][j];
			if (i == j)
				res[i][j] = 1;
		}
	}
	while (1) {	
		if (b == 0)
			break;
		// b로 나눴을때 나머지가 1이면 
		if(b%2==1)
			mat_mul(res, squ, 0);	//제곱해온 배열에 현재 값을 곱해준다.
		//제곱
		mat_mul(squ, squ, 1);
		b /= 2;
	}
	
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cout << res[i][j]  << " ";
		}
		cout << endl;
	}
	

	return 0;
}