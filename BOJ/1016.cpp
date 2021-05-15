#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll MAX_NUM = 1e7;
/*
1. ������ ��� ����
2. min-max ��ȸ�ϸ鼭 ��Ͽ� �ִ��� check -> binary search
nlogn?
-> ����.. �������� ����� �ɷ����� ���Ѵ�...

->then? �����佺�׳׽��� ü

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
	//false : �������� ��� x
	for (ll i = 2;i <= 1e6;i++) {
		for (ll j = mm % (i*i) == 0 ? mm : mm+ i*i-(mm% (i*i));j <= MM;j += i * i) {
			//min ���� ũ�鼭, ���� ���� ������ : 1) �������� ������ ���� ���-> mm 2)�������� ���������� �ʴ°��-> mod��ŭ �����ش�.
			
			//�������� ����� ���
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