
/*
	��� ���� ����
	square and multiply�� �̿��� ��� square ������ �ð� ���⵵�� ���� ���� �� �ִ�!
	
	��������
	mod ������ ������ ��¿��� �ؼ� Ʋ�ȴ�.
	�߰��� ���� Ŀ���� garbage ���� �� �� ������, ���� �߰� �߰��� ��� mod�� ���ش�.

	��������
	�迭�� �ƴ� vector�� �̿��ϸ� 2d array passing, return�� ���� ���������� �� �� �ִ�.
*/

#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;
ll mat[6][6];
ll n, b;

ll res[6][6], squ[6][6];

void mat_mul(ll a[][6],ll b[][6], int opt) {
	//opt 1: ����, 0: ���ϱ�
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
		// b�� �������� �������� 1�̸� 
		if(b%2==1)
			mat_mul(res, squ, 0);	//�����ؿ� �迭�� ���� ���� �����ش�.
		//����
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