/*
	�޸� �ʰ� 

	union & find���� ���� ��������.
	p[a] = find(a) �� �ƴ϶�
	p[a] = find(p[a])�� �ؾ� �Ѵ�.

	���� ���� ¥�� ���� ���ȣ���� �Ǿ� ���� �����÷ο� �߻�!
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, pair<int, int>> pii;
int vn, en;
int p[10001];
vector<pii> e_vec;
int find(int a) {
	if (p[a] < 0)
		return a;
	p[a] = find(p[a]);
	return p[a];
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return;
	p[a] = b;
}
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> vn >> en;
	int src, dest, cost;
	
	for (int i = 0;i < en;i++) {
		cin >> src >> dest >> cost;
		e_vec.push_back({ cost,{src,dest} });
	}
	sort(e_vec.begin(), e_vec.end());
	fill(p, p + 10001, -1);
	int sum = 0, cnt = 0;
	for (pii x : e_vec) {
		src = x.second.first;
		dest = x.second.second;
		if (find(src) == find(dest)) {
			continue;
		}
		merge(src, dest);
		sum += x.first;
		cnt++;
		if (cnt == vn - 1)
			break;
	}
	cout << sum;

	return 0;
}