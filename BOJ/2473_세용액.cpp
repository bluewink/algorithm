/*
	�ο�� ���� ����.

	n�� 5000�����̱� ������ O(N^2 * logN)���� Ȱ�밡�� �ϴٴ� ���� ����Ʈ.

	�� ���� ��Ÿ�� ����...
	(1) element�� ���� ������ �� int�� ���� (2*10^9)�� �Ѿ �� �ִ�. -> LONG LONG
	(2) ANS�� MIN ���� 987654321�� ��Ҵµ� �̸� �Ѿ�� ���� �����Ѵ�. -> MIN ���� 3* 10^9 ���� ũ�� ��´�.
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