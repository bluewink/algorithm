/*
	�� ���
	�� ������

	1. ����
	2. �� ������ left - right�� ����
	3. left�� ������Ű�� right�� ���ҽ�Ű�鼭
	4. ������ ���� ���� ������ ã�´�.

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
typedef long long ll;
vector<int> vec;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	ll n,in;
	cin >> n;
	
	for (ll i = 0;i < n;i++) {
		cin >> in;
		vec.push_back(in);
	}
	sort(vec.begin(), vec.end());

	ll sum, left, right, mm,a, b, left_num,right_num;
	left = 0, right = vec.size()-1;
	mm = 9876543210;
	while (1) {
		left_num = vec[left];
		right_num = vec[right];
		sum = left_num + right_num;
		if (abs(sum) < abs(mm)) {
			mm = sum;
			a = left_num;
			b = right_num;
		}
		if (sum < 0) {
			left++;
		}
		else if (sum > 0) {
			right--;
		}
		else {
			//����!
			a = left_num;
			b = right_num;
			break;
		}
		if (left >= right) {
			break;
		}
	}

	if (a > b) {
		cout << b << " " << a;
	}
	else {
		cout << a << " " << b;
	}

	return 0;
}