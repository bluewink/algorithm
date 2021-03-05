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
		cin >> in;
		pq.push(in);
	}
	int ans = 0;
	while (!pq.empty()) {

		int cur = pq.top();
		pq.pop();
		
		if (pq.empty()) {	
			break;
		}
		else {
			int next = pq.top();
			pq.pop();
			pq.push(next + cur);
			ans += next + cur;
		}
	}

	cout << ans;

	return 0;
}