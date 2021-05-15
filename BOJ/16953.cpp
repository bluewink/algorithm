#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
ll a, b;
const ll INF = 1e9;
queue<pair<ll, ll> > q;	// num, cnt
int flag = 0;
void bfs() {

	q.push({ a,0 });

	while (!q.empty()) {
		ll cur = q.front().first;
		ll cnt = q.front().second;
		q.pop();

		if (cur > b) {
			continue;
		}

		if (cur == b) {
			cout << cnt + 1;
			flag = 1;
			break;
		}

		//2 곱하기
		if (2 * cur <= INF) {
			q.push({ 2 * cur,cnt + 1 });
		}

		//오른쪽에 1 추가
		ll next = cur * 10 + 1;
		if (next <= INF) {
			q.push({ next,cnt + 1 });
		}

	}

}

int main() {


	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b;

	bfs();
	if (!flag) {
		cout << -1;
	}

	return 0;
}