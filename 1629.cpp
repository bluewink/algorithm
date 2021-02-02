#include <iostream>

using namespace std;
typedef long long ll;


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	ll a, b, c, acc, res;
	cin >> a >> b >> c;
	
	// a�� b�� ���� ���� c�� ���� ������.
	acc = res = 1;
	//square & multiply
	int cnt = 0;
	while (b > 0) {
		if (cnt == 0) {
			acc = a;
		}
		else {
			acc *= acc;
			acc %= c;
		}
		if (b % 2 == 1) {
			res *= acc ;
			res %= c;
		}
		b /= 2;
		cnt++;
	}
	cout << res % c;

}