/*
	�κ���
	-> ��������
	
	��������
	�ݷʸ� ã�� ���ߴ�.
	�� ������ ������ �����ϴ� ��츦 ���ƴ�.
	�ݷʸ� ã�� ���� �� ó���� �� ��, ������ ���ڷ� �̷���� ��� �� ���� ���̽��� ����غ���.

	+ �������
	Ž�� ���������� ������ �� ��ٷο���.
	�� ���� ���� ��� sum < k && right == end�� �� Ž���� �����ϸ� �ȴ�.

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> vec;
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int left, right,sum, n, k,in;
	cin >> n >> k;
	for (int i = 0;i < n;i++) {
		cin >> in;
		vec.push_back(in);
	}
	left = right = 0;
	sum = vec[left];
	int mm = 987654321;
	int vec_len = vec.size();
	while (1) {
		if (right == vec_len - 1 && left == vec_len - 1) {
			if (sum >= k)
				mm = min(mm, right - left + 1);
			break;
		}
		if (sum >= k) {
			mm = min(mm, right - left + 1);
			if (mm == 1) {
				break;
			}
			if (left < right) {
				sum -= vec[left];
				left++;
			}
			else {
				right++;
				sum += vec[right];
			}
		}
		else {
			//sum < k
			if (right < vec_len - 1) {
				right++;
				sum += vec[right];
			}
			else {
				sum -= vec[left];
				left++;
			}
		}
	}
	if (mm == 987654321)
		cout << 0;
	else
		cout << mm;
	return 0;
}