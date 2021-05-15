/*
	우선순위 큐 카테고리...
	에서 골랐는데 그리디 문제였다

	풀이가 생각이 안나서 풀이를 찾아봤다.

*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
priority_queue<int,vector<int>,greater<>> pq;
vector<int> rest;
int n, cut_num;
int main() {

	ios::sync_with_stdio(0);
	cin.tie();

	cin >> n >> cut_num;
	int in;

	for (int i = 0;i < n;i++) {
		cin >> in;
		if (in % 10 == 0)
			pq.push(in);
		else
			rest.push_back(in);
	}
	int ans = 0;

	while (1) {
		if (!pq.empty()) {
			int cur = pq.top();
			//cout << cur <<endl;
			pq.pop();

			if (cur < 10)
				continue;

			if (cur == 10) {
				ans++;
				continue;
			}
			else {
				if (cut_num > 0) {
					pq.push(cur - 10);
					cut_num--;
					ans++;
				}
			}
		}
		else {
		
			if (rest.empty())
				break;

			if (cut_num <= 0)
				break;
			else {
				int cur = rest.back();
				rest.pop_back();
				if (cur > 10) {
					rest.push_back(cur - 10);
					cut_num--;
					ans++;
				}
			}
		}
	}
	cout << ans;

	return 0;
}