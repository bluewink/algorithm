#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
int n, m, x, y;
/*
	1. m,n 중 작은 걸 고른다. ->mm
	2. mm, mm이 될 때를 계산
	3. (mm+a) % b 계산
	4. x: y 가 될 때를 찾는다.
	이 때 mm:mm으로 돌아오면 실패
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
			//a : 작은쪽 b: 큰쪽
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
		//초기화
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
				//있으면 -> 한 바퀴 다 돈 셈
				break;
			}
			//없으면
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