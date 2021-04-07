/*
	두용액 응용 버전.

	n이 5000까지이기 때문에 O(N^2 * logN)까지 활용가능 하다는 것이 포인트.

	두 번의 런타임 에러...
	(1) element를 세번 더했을 때 int의 범위 (2*10^9)을 넘어갈 수 있다. -> LONG LONG
	(2) ANS의 MIN 값을 987654321로 잡았는데 이를 넘어서는 값도 존재한다. -> MIN 값을 3* 10^9 보다 크게 잡는다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
vector<ll> vec;
vector<vector<ll>> candi;
ll res = 98765432100;
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	ll n, in;
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> in;
		vec.push_back(in);
	}

	sort(vec.begin(), vec.end());
	int selected;
	int len = vec.size();
	for (int i = 0;i < n;i++) {
		selected = i;
		int left = 0;
		int right = len - 1;
		
		while (1) {
			if (left >= right) {
				break;
			}
			if (selected<len-1 && left == selected) {
				left++;
				continue;
			}
			if (selected>0 && right == selected) {
				right--;
				continue;
			}
			ll sum = vec[selected] + vec[left] + vec[right];
			if (abs(res) > abs(sum)) {
				res = sum;
				candi.push_back({ vec[selected],vec[left],vec[right] });
			}
			if (sum > 0) {
				right--;
			}
			else if (sum < 0) {
				left++;
			}
			else {
				candi.push_back({ vec[selected],vec[left],vec[right] });
				break;
			}
		}
	}

	vector<ll> ans = candi.back();
	sort(ans.begin(), ans.end());
	for (ll x : ans) {
		cout << x << " ";
	}

	return 0;
}