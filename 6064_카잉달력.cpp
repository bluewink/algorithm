#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
int n, m, x, y;
/*
	1. m,n �� ���� �� ����. ->mm
	2. mm, mm�� �� ���� ���
	3. (mm+a) % b ���
	4. x: y �� �� ���� ã�´�.
	�� �� mm:mm���� ���ƿ��� ����
*/
set<int> s;
int main() {

	int tn;

	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> tn;
	while (tn--) {
		s.clear();
		cin >> n >> m >> x >> y;
		int a, b, ca, cb, target;
		if (n < m) {
			//a : ������ b: ū��
			a = x;
			b = y;
			ca = n;
			cb = m;
			target = y;
		}
		else {
			a = y;
			b = x;
			ca = m;
			cb = n;
			target = x;
		}
		//�ʱ�ȭ
		int cnt = 0;
		cnt = a;
		b = a;
		s.insert(b);

		int flag = 0;

		while (1) {
			if (b == target) {
				flag = 1;
				break;
			}
			b = (ca + b) % cb;
			if (b == 0)
				b = cb;
			/*
			while (1) {
				if (ca + b - cb < ca) {
					b = (ca + b) % cb;
					break;
				}
				else{
					b = ca + b - cb;
				}
			}
			*/
			cnt += ca;
			
			if (s.find(b) != s.end()) {
				//������ -> �� ���� �� �� ��
				break;
			}
			//������
		}

		if (flag) {
			cout << cnt << endl;
		}
		else {
			cout << -1 << endl;
		}

	}

	return 0;
}