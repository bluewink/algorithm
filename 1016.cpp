#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll MAX_NUM = 1e7;
/*
1. 제곱수 목록 저장
2. min-max 순회하면서 목록에 있는지 check -> binary search
nlogn?
-> 문제.. 제곱수의 배수를 걸러내지 못한다...

->then? 에라토스테네스의 체

*/


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	ll mm,MM;
	cin >>  mm>> MM;
	bool isPrime[1000001];
	//isPrime[0] = mm, inPrime[100000] = MM
	vector<ll> res;
	fill(isPrime, isPrime + 1000001, true);
	//false : 제곱수의 배수 x
	for (ll i = 2;i <= 1e6;i++) {
		for (ll j = mm % (i*i) == 0 ? mm : mm+ i*i-(mm% (i*i));j <= MM;j += i * i) {
			//min 보다 크면서, 가장 작은 제곱수 : 1) 제곱수로 나누어 지는 경우-> mm 2)제곱수로 나누어지지 않는경우-> mod만큼 더해준다.
			
			//제곱수의 배수일 경우
			if(mm<=j && j<=MM)
				isPrime[j-mm] = false;
			//j-mm: index
		}
	}
	int cnt = 0;
	for (int i = 0;i < MM - mm +1;i++) {
		if(isPrime[i])
			cnt++;
	}
	cout << cnt;

	
	return 0;
}