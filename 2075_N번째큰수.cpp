/*
	�켱���� ť
	
	�׻� min heap ũ�⸦ n���� �����Ѵ�.
	1. heap�� n���� ä���,
	2. ���Ŀ� ���� ������ �ϳ��� ���ش�.
	3. ��� Ž���� ������ �� heap�ȿ��� n��°�� ū��, n-1��°�� ū��... 1��°�� ū���� ����.
	4. ���� top�� �ִ°� n��°�� ū���� �ȴ�.

	�޸� �ʰ��� ���� ����ϴٰ� Ǯ�̸� �����ߴ�... �Ф�

*/
#include <iostream>
#include <queue>

using namespace std;
priority_queue<int, vector<int>, greater<>> pq;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, in;
	cin >> n;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> in;
			if (i == 0) {
				pq.push(in);
			}
			else {
				pq.push(in);
				pq.pop();
			}
		}
	}
	cout << pq.top();

	return 0;
}